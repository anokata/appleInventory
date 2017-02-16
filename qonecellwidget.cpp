#include "qonecellwidget.h"
static const char *appleImage = "./resources/apple.jpg";

/* Конструктор виджета источника предметов. */
QOneCellWidget::QOneCellWidget(QWidget *parent) : QTableWidget(1, 1, parent)
{
    configure();
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setData(Qt::DecorationRole, 
                  QPixmap::fromImage(loadFile(appleImage)));
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    this->setItem(0, 0, item);
}

/* Деструктор виджета источника. */
QOneCellWidget::QOneCellWidget(int rows, int columns, QWidget *parent)
    : QTableWidget(rows, columns, parent)
{
    configure();
}

/* Метод конфигурации виджета.
 * Скрытие заголовков таблицы. Установка размеров и поведения. */
void QOneCellWidget::configure()
{
    horizontalHeader()->hide();
    verticalHeader()->hide();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader()->setDefaultSectionSize(120);
    horizontalHeader()->setDefaultSectionSize(120);
    setDragEnabled(true);
    setDragDropOverwriteMode(true);
    setDragDropMode(QAbstractItemView::DragDrop);
    setDefaultDropAction(Qt::CopyAction);
    setDropIndicatorShown(true);
    viewport()->setAcceptDrops(true);
}

void QOneCellWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QTableWidget::mousePressEvent(event);
        /* Вызываем сигнал перетаскивания нового предмета. */
        emit itemPassed(QString(appleImage), FOOD);
    }
}

/* Метод для загрузки изображения. */
QImage QOneCellWidget::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        qDebug() << "Can not load file";
        return newImage;
    }
    return newImage;
}

void QOneCellWidget::dragEnterEvent(QDragEnterEvent *event)
{ 
    event->ignore();
}
