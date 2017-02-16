#ifndef INVENTORY_H
#define INVENTORY_H

#include <QVector>
#include <QDebug>
#include <QSqlQuery>

#include "item.h"
#include "database.h"

class Inventory
{
public:
    Inventory(int cols, int rows);
    ~Inventory();
    Item *getItem(int x, int y);
    void fromDB();
    void wipeDB();
    void moveItem(Item *item, int col, int row);
    bool eatItem(int col, int row);
    int getColumns();
    int getRows();

private:
    void deleteItems();
    QVector< QVector<Item*> > items;
    DataBase *dataBase;

};

#endif // INVENTORY_H
