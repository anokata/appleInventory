
QMAKE_CXXFLAGS += -std=c++11
CONFIG += c++11
TEMPLATE = app
TARGET = qt
INCLUDEPATH += .
DEPENDPATH += .
QT += sql
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += gamefield.h \
           inventory.h \
           item.h \
           mainmenu.h \
           qinvtablewidget.h \
           qonecellwidget.h \
           window.h \
    database.h \
    const.h
SOURCES += gamefield.cpp \
           inventory.cpp \
           item.cpp \
           main.cpp \
           mainmenu.cpp \
           qinvtablewidget.cpp \
           qonecellwidget.cpp \
           window.cpp \
    database.cpp
