#include "inventorydb.h"
static const char *dbFile = "./resources/inventory.db";

/* Конструктор базы инвентаря. */
InventoryDB::InventoryDB()
{
    dataBase = new DataBase(QString(dbFile));
}

/* Метод получения всех предметов в инвентаре */
QSqlQuery InventoryDB::getAllItems()
{
    return dataBase->queryExec(
               "select X, Y, Count, Type, ImagePath, Items.ItemID "
               "from Inventory inner join Items "
               "where Inventory.ItemID = Items.ItemID");
}

/* Метод очистки базы данных */
void InventoryDB::clearInventory()
{
    dataBase->queryExec("delete from inventory").finish();
    dataBase->queryExec("delete from items").finish();
}

/* Метод удаления предмета из инвентаря по его id */
void InventoryDB::deleteById(int id)
{
    QSqlQuery query;
    query.prepare("delete from inventory where ItemID = :id");
    query.bindValue(":id", id);
    dataBase->queryExec(query).finish();
}

/* Метод получения предмета по координатам ячейки инвентаря */
QSqlQuery InventoryDB::itemAtCell(int col, int row)
{
    QSqlQuery query;
    query.prepare("select Count, Items.ItemID, Type, ImagePath from Inventory "
                "inner join Items where Inventory.ItemID = Items.ItemID "
                "and X = :col and Y = :row");
    query.bindValue(":col", col);
    query.bindValue(":row", row);
    return dataBase->queryExec(query);
}

/* Метод изменения количества предметов у предмета по его id */
void InventoryDB::updateItemCount(int id, int newCount)
{
    QSqlQuery query;
    query.prepare("UPDATE Items SET Count = :count WHERE ItemID = :id ");
    query.bindValue(":id", id);
    query.bindValue(":count", newCount);
    dataBase->queryExec(query).finish();
}

/* Метод добавления предмета в инвентарь */
void InventoryDB::addInventoryItem(int id, int col, int row)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Inventory VALUES (:iid, :x, :y)");
    query.bindValue(":iid", id);
    query.bindValue(":x", col);
    query.bindValue(":y", row);
    dataBase->queryExec(query).finish();
}

/* Метод добавления нового предмета */
int InventoryDB::addNewItem(QString name, int count, ItemType type, QString path)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Items (ItemID, Name, Count, Type, ImagePath) "
            "VALUES (null, :name, :count, :type, :path)");
    query.bindValue(":name", name);
    query.bindValue(":count", count);
    query.bindValue(":type", type);
    query.bindValue(":path", path);
    int last = dataBase->queryExec(query).lastInsertId().toInt();
    return last;
}

/* Метод удаления самого предмета по его id */
void InventoryDB::deleteByIdItem(int id)
{
    QSqlQuery query;
    query.prepare("delete from items where ItemID = :id");
    query.bindValue(":id", id);
    dataBase->queryExec(query).finish();
}
