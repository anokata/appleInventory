#include "database.h"
#include <QDebug>

/* Конструктор базы данных. Устанавливает соединение. */
DataBase::DataBase(QString dbName)
{
    this->dbName = dbName;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName); 

    if (!db.open()) {
        qDebug() << "db not ok" << db.lastError().text();
    }
}

/* Деструктор базы данных. Корректно завершает соединение с базой. */
DataBase::~DataBase()
{
    db.close();
    QSqlDatabase::removeDatabase(dbName);
}

/* Выполнение запроса к БД */
QSqlQuery DataBase::queryExec(QString queryString)
{
    db = QSqlDatabase::database(dbName);
    QSqlQuery query(db);
    db.transaction();
    query.exec(queryString);
    db.commit();
    return query;
}

/* Выполнение запроса к БД */
QSqlQuery DataBase::queryExec(QSqlQuery query)
{
    db = QSqlDatabase::database(dbName);
    db.transaction();
    query.exec();
    db.commit();
    return query;
}
