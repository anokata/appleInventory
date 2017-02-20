#pragma once
#include <QtNetwork>
#include <QVector>

class Server: public QObject
{
    Q_OBJECT

public:
    explicit Server(int port);
    ~Server();
    QString popData();

public slots:
    void sendData(QString data);

signals:
    void dataRecivedS();

private slots:
    void newConn();
    void readClient();

private:
    void sendToClient(QTcpSocket *sock, const QString &str);
    QTcpServer *tcpServer;
    quint16 blockSize;
    QString data;
    QVector<QTcpSocket*> clients;
    QVector<QString> clientsData;

};
