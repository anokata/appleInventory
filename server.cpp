#include "server.h"
#include <QDebug>

Server::Server(int port) : QObject()
{
    tcpServer = new QTcpServer();
    if (!tcpServer->listen(QHostAddress::Any, port))
        return;
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConn()));
}

Server::~Server()
{
    tcpServer->close();
    delete tcpServer;
}

void Server::sendData(QString data)
{
    for (auto c : clients) {
        sendToClient(c, data);
    }
}

void Server::newConn()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readClient()));
    sendToClient(clientSocket, "[Connected]");
    clients.append(clientSocket);
}
        
void Server::readClient() // TODO dublicate
{
    QTcpSocket* sock = (QTcpSocket*)sender();
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
    clientsData.push_back(data);
    emit dataRecivedS();
}

void Server::sendToClient(QTcpSocket *sock, const QString &str)
{
    QByteArray a;
    QDataStream out(&a, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(a.size() - sizeof(quint16));
    sock->write(a);
}

QString Server::popData()
{
    QString data = clientsData.last();
    clientsData.pop_back();
    return data;
}
