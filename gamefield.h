#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include "qinvtablewidget.h"
#include "qonecellwidget.h"

const int CELL_SIZE = 120;

class GameField : public QWidget
{
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField();
    void enable();
    void disable();

signals:

public slots:
private:
    QPushButton *mainMenuButton;
    QInvTableWidget *inventoryWidget;
    QOneCellWidget *oneItem;
};

#endif // GAMEFIELD_H
