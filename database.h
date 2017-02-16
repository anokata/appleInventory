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
    QSqlQuery queryExec(QString);
    QSqlQuery queryExec(QSqlQuery query);

private:
    QSqlDatabase db;
    QString dbName;
};

#endif // DATABASE_H
