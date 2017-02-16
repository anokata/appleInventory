#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>

#include "mainmenu.h"
#include "gamefield.h"

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

signals:

public slots:
    void newgame();
    void exit();
    void goMainMenu();

private:
    MainMenu *mainMenuWidget;
    GameField *gameField;
};

#endif // WINDOW_H
