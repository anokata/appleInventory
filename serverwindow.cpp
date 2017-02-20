#include "serverwindow.h"
#include <QApplication>

/* Конструктор главного окна */
ServerWindow::ServerWindow(QWidget *parent) : QWidget(parent)
{
    const int WINDOW_WIDTH = 300;
    setFixedSize(WINDOW_WIDTH, WINDOW_WIDTH);
    setGeometry(50, 50, WINDOW_WIDTH, WINDOW_WIDTH);

    server = new Server(10000);
    connect(server, SIGNAL(dataRecivedS()), this, SLOT(haveData()));
}

/* Деструктор главного окна */
ServerWindow::~ServerWindow()
{
    delete server;
}

    //server->sendData(QString("<Data from server>"));
void ServerWindow::haveData()
{
    qDebug() << server->popData();
}

