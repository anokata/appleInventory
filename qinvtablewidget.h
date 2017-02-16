#ifndef QINVTABLEWIDGET_H
#define QINVTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QDropEvent>
#include <QImage>
#include <QSound>

#include "inventory.h"
#include "qonecellwidget.h"
#include "const.h"

const QString appleWav = ":/resources/apple-crunch.wav";

class QInvTableWidget : public QOneCellWidget
{
Q_OBJECT
public:
    QInvTableWidget(int rows, int columns, 
                    QWidget *parent, QWidget *recipient);
    ~QInvTableWidget();
    void wipeInventory();
    void dropEvent(QDropEvent *event);

public slots:
    void cellStart(int row, int col);
    void passItem(QString path, ItemType type);

signals:
    void itemPassed(QString path, ItemType type);

protected:
    Inventory *inventory;

private:
    bool dropMimeData(int row, int column, 
                      const QMimeData *data, Qt::DropAction action);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void refreshCells();
    void debugPrintAllItems();

};

#endif // QINVTABLEWIDGET_H
