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
    mainview.cpp \
    edititems.cpp \
    availableinventory.cpp \
    editteams.cpp \
    returnitems.cpp

HEADERS  += adminpage.h \
    mainview.h \
    edititems.h \
    availableinventory.h \
    editteams.h \
    returnitems.h

FORMS    += adminpage.ui \
    mainview.ui \
    edititems.ui \
    availableinventory.ui \
    editteams.ui \
    returnitems.ui
