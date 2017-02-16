#include "window.h"
#include <QApplication>

/* Конструктор главного окна */
Window::Window(QWidget *parent) : QWidget(parent)
{
    const int WINDOW_WIDTH = 600;
    setFixedSize(WINDOW_WIDTH, WINDOW_WIDTH);
    setGeometry(0, 0, WINDOW_WIDTH, WINDOW_WIDTH);

    mainMenuWidget = new MainMenu(this);
    gameField = new GameField(this);
}

/* Деструктор главного окна */
Window::~Window()
{
    delete mainMenuWidget;
    delete gameField;
}

/* Слот для перехода в главное меню */
void Window::goMainMenu()
{
    gameField->disable();
    mainMenuWidget->enable();
}

/* Слот для начала новой игры */
void Window::newgame()
{
    gameField->enable();
    mainMenuWidget->disable();
}

/* Слот для выхода из приложения */
void Window::exit()
{
    gameField->enable();
    QApplication::instance()->quit();
}

