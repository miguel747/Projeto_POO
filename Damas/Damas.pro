#-------------------------------------------------
#
# Project created by QtCreator 2013-01-20T14:26:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Damas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        pecasView.cpp \
        Casa.cpp \
        jogo.cpp \
        Peca.cpp \
        Tabuleiro.cpp

HEADERS  += mainwindow.h \
        pecasView.h \
        Casa.h \
        jogo.h \
        Peca.h \
        Tabuleiro.h

RESOURCES += \
    Resources.qrc

CONFIG += exceptions
