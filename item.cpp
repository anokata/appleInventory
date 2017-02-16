#include "item.h"
#include <QStringList>

/* Конструктор предмета по ид, изображению и типу */
Item::Item(int id, QString imagePath, ItemType type) :
    imagePath(imagePath), type(type), ID(id)
{
    count = 1;
}

/* Конструктор предмета по ид, изображению, типу и количеству */
Item::Item(int id, QString imagePath, ItemType type, int count) :
    imagePath(imagePath), type(type), count(count), ID(id)
{ }

/* Геттер количества */
int Item::getCount()
{
    return count;
}

/* Геттер id */
int Item::getId()
{
    return ID;
}

/* Геттер пути изображения */
QString Item::getImagePath()
{
    return imagePath;
}

/* Геттер типа предмета */
ItemType Item::getType()
{
    return type;
}

