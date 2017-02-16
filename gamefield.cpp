#include "gamefield.h"

/* Конструктор виджета игрового поля. Создаёт элементы интерфейса. */
GameField::GameField(QWidget *parent) : QWidget(parent)
{
    const int INV_DIMENSION = 3;
    oneItem = new QOneCellWidget(this);
    oneItem->setEnabled(false);
    inventoryWidget = new QInvTableWidget(INV_DIMENSION, 
                                          INV_DIMENSION, this, oneItem);
    inventoryWidget->setEnabled(false);
    mainMenuButton = new QPushButton(trUtf8("Главное меню"), this);
    mainMenuButton->setLayoutDirection(Qt::RightToLeft);
    mainMenuButton->setEnabled(false);

    setGeometry(10, 100, parent->width(), parent->height());
    oneItem->setGeometry(450, 100, CELL_SIZE, CELL_SIZE);
    inventoryWidget->setGeometry(0, 0, 400, 400);
    mainMenuButton->setGeometry(450, 300, 120, 30);

    connect(mainMenuButton, SIGNAL (clicked()), parent, SLOT (goMainMenu()));
}

/* Деструктор виджета игрового поля. Удаляет созданные объекты. */
GameField::~GameField()
{
    delete inventoryWidget;
    delete oneItem;
    delete mainMenuButton;
}

/* Включение игрового поля */
void GameField::enable()
{
    inventoryWidget->wipeInventory();
    inventoryWidget->setEnabled(true);
    oneItem->setEnabled(true);
    mainMenuButton->setEnabled(true);
}

/* Отключение игрового поля */
void GameField::disable()
{
    inventoryWidget->wipeInventory();
    inventoryWidget->setEnabled(false);
    oneItem->setEnabled(false);
    mainMenuButton->setEnabled(false);
}
