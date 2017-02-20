#ifndef WINDOW_H_SERVER
#define WINDOW_H_SERVER

#include <QWidget>
#include <QLabel>

#include "server.h"

class ServerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();

signals:

private slots:
    void haveData();
public slots:

private:
    Server *server;
};

#endif // WINDOW_H_SERVER
