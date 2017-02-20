#pragma once
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QString host, int port);
    ~Client();
    QString getData();

public slots:
    void sendToServer(QString data);

private slots:
    void readyRead();
    void connected();
    void error(QAbstractSocket::SocketError);

signals:
    void dataRecived();

private:
    QTcpSocket *sock;
    quint16 blockSize;
    QString data;
};
