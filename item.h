#ifndef ITEM_H
#define ITEM_H
#include <QString>

#include "const.h"

class Item
{
public:
    Item(int id, QString imagePath, ItemType type);
    Item(int id, QString imagePath, ItemType type, int count);
    QString getImagePath();
    ItemType getType();
    int getId();
    int getCount();

private:
    QString imagePath;
    ItemType type;
    int count;
    int ID;

};

#endif // ITEM_H
