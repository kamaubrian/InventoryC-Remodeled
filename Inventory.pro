#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T14:00:28
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Inventory
TEMPLATE = app


SOURCES += main.cpp\
        adminpage.cpp \
    mainview.cpp

HEADERS  += adminpage.h \
    mainview.h

FORMS    += adminpage.ui \
    mainview.ui
