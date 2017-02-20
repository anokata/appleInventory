#include <QtGui>
#include <QPushButton>
#include <QApplication>
#include "window.h"
#include "serverwindow.h"
 
/* Главная функция приложения. */
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ServerWindow serverw;
    serverw.show();
    Window window;
    window.show();
    int result = app.exec();
    return result;
}
 
