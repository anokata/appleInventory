#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

#include "const.h"

class DataBase
{
public:
    DataBase(QString);
    ~DataBase();
    QSqlQuery itemAtCell(int col, int row);
    void deleteById(int id);
    void updateItemCount(int id, int newCount);
    void addInventoryItem(int id, int row, int col);
    int addNewItem(QString name, int count, ItemType type, QString path);
    void deleteByIdItem(int id);
    QSqlQuery getAllItems();
    void wipeDB();

private:
    QSqlDatabase db;
    QString dbName;
};

#endif // DATABASE_H
