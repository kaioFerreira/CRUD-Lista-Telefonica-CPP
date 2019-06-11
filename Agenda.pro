#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T09:21:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adicionar.cpp \
    contato.cpp \
    indice.cpp \
    contatomostrar.cpp \
    vetorobjeto.cpp

HEADERS  += mainwindow.h \
    adicionar.h \
    contato.h \
    indice.h \
    contatomostrar.h \
    vetorobjeto.h

FORMS    += mainwindow.ui \
    adicionar.ui \
    contatomostrar.ui

RESOURCES += \
    imagens.qrc

DISTFILES += \
    Kayn.jpg
