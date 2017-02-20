#include "client.h"
#include <QDebug>

Client::Client(QString host, int port) : QObject()
{
    sock = new QTcpSocket(this);
    sock->connectToHost(host, port);
    connect(sock, SIGNAL(connected()), this, SLOT(connected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

Client::~Client()
{
    delete sock;
}

void Client::readyRead()
{
    QDataStream in(sock);
    data = "";
    in.setVersion(QDataStream::Qt_5_5);
    blockSize = 0;
    for (;;) {
        if (!blockSize) {
            if (sock->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> blockSize;
        }

        if (sock->bytesAvailable() < blockSize) {
            break;
        }

        QTime time;
        QString str;
        in >> time >> str;
        data += time.toString() + " " + str + '\n';
        blockSize = 0;
    }
    emit dataRecived();
}

void Client::connected()
{ }

void Client::error(QAbstractSocket::SocketError err)
{ 
    qDebug() << err << sock->errorString();
}

void Client::sendToServer(QString data)
{
    QByteArray a;
    QDataStream out(&a, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << quint16(0) << QTime::currentTime() << data;
    out.device()->seek(0);
    out << quint16(a.size() - sizeof(quint16));
    sock->write(a);
}

QString Client::getData()
{
    return data;
}
