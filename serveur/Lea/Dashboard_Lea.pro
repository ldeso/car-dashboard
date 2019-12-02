#-------------------------------------------------
#
# Project created by QtCreator 2019-11-25T10:03:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dashboard_Lea
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mygraphicitem.cpp \
    speedometer_lea.cpp \
    tachometergauge_lea.cpp \
    voyant_lea.cpp \
    aiguille_lea.cpp \
    lea_scene.cpp \
    lea_scenedefond.cpp \
    deux_voyants_lea.cpp \
    fuelgauge_lea.cpp \
    quatre_voyants_lea.cpp

HEADERS += \
        mainwindow.h \
    mygraphicitem.h \
    speedometer_lea.h \
    tachometergauge_lea.h \
    voyant_lea.h \
    aiguille_lea.h \
    lea_scene.h \
    lea_scenedefond.h \
    quatre_voyants_lea.h \
    deux_voyants_lea.h \
    fuelgauge_lea.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    fuel.qrc

DISTFILES +=
