#-------------------------------------------------
#
# Project created by QtCreator 2014-11-04T01:43:02
#
#-------------------------------------------------
include(qtpropertybrowser/qtpropertybrowser.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DoroboroEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tabeditor.cpp \
    newlevel.cpp \
    tile.cpp

HEADERS  += mainwindow.h \
    tabeditor.h \
    newlevel.h \
    tile.h

FORMS    += mainwindow.ui \
    tabeditor.ui \
    newlevel.ui

RESOURCES += \
    icons.qrc
