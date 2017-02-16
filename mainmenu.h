#ifndef MAINMENU_H
#define MAINMENU_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void disable();
    void enable();

signals:

public slots:
private:
    QPushButton *exitButton;
    QPushButton *newgameButton;
};

#endif // MAINMENU_H
