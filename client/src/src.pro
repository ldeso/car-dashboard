TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

LIBS += -L$$OUT_PWD/../clientio/ -lclientio

INCLUDEPATH += $$PWD/../clientio
DEPENDPATH += $$PWD/../clientio

TARGET = ../client
