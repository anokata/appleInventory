#include "inventory.h"
static const char *dbFile = "./resources/inventory.db";

/* Конструктор инвентаря. Иницилизация контейнера. Подключение к БД */
Inventory::Inventory(int cols, int rows)
{
    items = QVector< QVector<Item*> >(rows);
    for (int i = 0; i < rows; ++i) {
        items[i] = QVector<Item*>(cols);
    }

    dataBase = new DataBase(QString(dbFile));
    fromDB();
}

/* Деструктор инвентаря. Освобождение БД. */
Inventory::~Inventory()
{
    deleteItems();
    delete dataBase;
}

/* Метод очистки базы данных */
void Inventory::wipeDB() {
    dataBase->wipeDB();
    fromDB();
}

/* Метод постройки инвентаря по данным из БД */
void Inventory::fromDB()
{
    deleteItems();

    QSqlQuery query = dataBase->getAllItems();
    while (query.next()) { 
        int x = query.value(0).toInt(); 
        int y = query.value(1).toInt(); 
        int count = query.value(2).toInt(); 
        ItemType type = (ItemType) query.value(3).toInt(); 
        QString imagePath = query.value(4).toString();
        int id = query.value(5).toInt(); 
        Item *item = new Item(id, imagePath, type, count);
        items[x][y] = item;
    }
    query.finish();
}

/* Метод получения предмета */
Item *Inventory::getItem(int x, int y)
{
    return (items[x][y]);
}

/* Метод получения размерности инвентаря по горизонтали */
int Inventory::getColumns()
{
    return items[0].size();
}

/* Метод получения размерности инвентаря по вертикали */
int Inventory::getRows()
{
    return items.size();
}

/* Метод удаления всех предметов */
void Inventory::deleteItems()
{
    for (int i = 0; i < items.size(); ++i) {
        for (int j = 0; j < items[i].size(); ++j) {
            delete items[i][j];
            items[i][j] = NULL;
        }
    }
}

/* Метод перемещения предмета */
void Inventory::moveItem(Item *item, int col, int row)
{
    QSqlQuery query = dataBase->itemAtCell(col, row);
    if (query.next()) {
        /* Куда хотят положить уже есть предмет. Обновим количество. */
        int count = query.value(0).toInt(); 
        int id = query.value(1).toInt(); 
        if (id == item->getId()) {
            /* не обрабатывать при применении к одному и тому же предмету */
            return;
        }
        dataBase->updateItemCount(id, count + item->getCount());

        if (item->getId() != -1) {
            /* Если предмет который пытаются положить
             *  был не новый удалим его со старого места */
            dataBase->deleteById(item->getId());
            /* И удалим со старым значением сам предмет */
            dataBase->deleteByIdItem(item->getId());
        }
    } else { 
        /* Если кладут на пустую ячейку */
        if (item->getId() != -1) {
            /* Кладут не новый предмет - удалим сначала со старого места */
            dataBase->deleteById(item->getId());
            dataBase->addInventoryItem(item->getId(), col, row);
        } else {
            /* создаём новый предмет в пустой ячейке */
            int lastid = dataBase->addNewItem("apple", item->getCount(), item->getType(), item->getImagePath());
            dataBase->addInventoryItem(lastid, col, row);
        }
    }
    query.finish();
}

/* Метод съедания предмета */
bool Inventory::eatItem(int col, int row)
{
    QSqlQuery query = dataBase->itemAtCell(col, row);
    if (query.next()) {
        int count = query.value(0).toInt(); 
        int id = query.value(1).toInt(); 
        if (count == 1) {
            dataBase->deleteById(id);
            dataBase->deleteByIdItem(id);
        } else {
            dataBase->updateItemCount(id, count - 1);
        }
        query.finish();
        return true;
    }
    query.finish();
    return false;
}
