#-------------------------------------------------
#
# Project created by QtCreator 2016-01-18T22:42:03
#
#-------------------------------------------------

QT       += core gui network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FuckAround
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formlabiel.cpp \
    pipethread.cpp \
    nudedude.cpp

HEADERS  += mainwindow.h \
    formlabiel.h \
    pipethread.h \
    nudedude.h

FORMS    += mainwindow.ui \
    formlabiel.ui \
    nudedudeForm.ui

INCLUDEPATH +=usr/local/lib
