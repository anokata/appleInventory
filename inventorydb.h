#ifndef INVENTORYDB_H
#define INVENTORYDB_H

#include <QSqlQuery>

#include "database.h"

class InventoryDB
{
public:
    InventoryDB();

    QSqlQuery itemAtCell(int col, int row);
    void deleteById(int id);
    void updateItemCount(int id, int newCount);
    void addInventoryItem(int id, int row, int col);
    int addNewItem(QString name, int count, ItemType type, QString path);
    void deleteByIdItem(int id);
    QSqlQuery getAllItems();
    void clearInventory();

private:
    DataBase *dataBase;
};

#endif // INVENTORYDB_H
