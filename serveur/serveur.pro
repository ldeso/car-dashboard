#-------------------------------------------------
#
# Project created by QtCreator 2019-11-12T17:29:26
#
#-------------------------------------------------

QT       += core gui network

QT += testlib

linux-buildroot-g++ {
    target.path     = root
    INSTALLS       += target
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serveur
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


SOURCES += \
    Hugo/hugo_aiguille.cpp \
    Hugo/hugo_compteur.cpp \
    Hugo/hugo_mygraphicsitem.cpp \
    Hugo/hugo_scene.cpp \
    Hugo/hugo_verre.cpp \
    Henri/cadranthenri.cpp \
    Henri/cardantvirtuel.cpp \
    Henri/jaugeclignotant.cpp \
    Henri/jaugeessencehenri.cpp \
    Henri/jaugetemperature.cpp \
    Henri/jaugetemperaturehenri.cpp \
    Henri/jaugetoursminutehenri.cpp \
    Henri/jaugevirtuel.cpp \
    Henri/scenedefond.cpp \
    Henri/scenedefondhenri.cpp \
    Henri/sceneglobale.cpp \
    compteur.cpp \
    main.cpp \
    mainwindow.cpp \
    Hugo/hugo_voyants.cpp \
    Hugo/hugo_voyants_clignotant.cpp \
    Hugo/hugo_voyants_simples.cpp \
    scene_globale.cpp

HEADERS += \
    compteur.h \
    Hugo/hugo_aiguille.h \
    Hugo/hugo_compteur.h \
    Hugo/hugo_mygraphicsitem.h \
    Hugo/hugo_scene.h \
    Hugo/hugo_verre.h \
    Henri/cadranthenri.h \
    Henri/cadrantvirtuel.h \
    Henri/jaugeclignotant.h \
    Henri/jaugeessencehenri.h \
    Henri/jaugetemperature.h \
    Henri/jaugetemperaturehenri.h \
    Henri/jaugetoursminutehenri.h \
    Henri/jaugevirtuel.h \
    Henri/scenedefond.h \
    Henri/scenedefondhenri.h \
    Henri/sceneglobale.h \
    compteur.h \
    mainwindow.h \
    Hugo/hugo_voyants.h \
    Hugo/hugo_voyants_clignotant.h \
    Hugo/hugo_voyants_simples.h \
    scene_globale.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    Henri/images.qrc

DISTFILES += \
    Henri/iconeEssence.png \
    Henri/iconeSurchaufe.png \
    Henri/liserMoi
