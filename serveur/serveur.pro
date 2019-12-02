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
    Henri/henri_scene.cpp \
    Henri/cadranthenri.cpp \
    Henri/jaugeclignotanthenri.cpp \
    Henri/jaugeessencehenri.cpp \
    Henri/jaugetemperaturehenri.cpp \
    Henri/jaugetoursminutehenri.cpp \
    Henri/scenedefondhenri.cpp \
    Hugo/hugo_compteur.cpp \
    Hugo/hugo_mygraphicsitem.cpp \
    Hugo/hugo_scene.cpp \
    Hugo/hugo_voyants_clignotant.cpp \
    Hugo/hugo_voyants_simples.cpp \
    Jonas/jonas_compteur.cpp \
    Jonas/jonas_scene.cpp \
    Leo/leo_scene.cpp \
    main.cpp \
    mainwindow.cpp \
    objet_virtuel.cpp \
    scene_globale.cpp \
    Florian/cadrantflorian.cpp \
    Florian/sceneflorian.cpp \
    Florian/voyant.cpp \
    Florian/clignotant.cpp \
    Henri/affichekmhenri.cpp \
    Henri/jaugebatteriehenri.cpp \
    Henri/warninghenri.cpp \
    Hugo/hugo_ecran.cpp \
    Hugo/hugo_voyant_warning.cpp \
    Henri/feuxhenri.cpp \
    Jonas/jonas_voyant_simple.cpp \
    Lea/deux_voyants_lea.cpp \
    Lea/fuelgauge_lea.cpp \
    Lea/lea_scene.cpp \
    Lea/phares_lea.cpp \
    Lea/quatre_voyants_lea.cpp \
    Lea/speedometer_lea.cpp \
    Lea/tachometergauge_lea.cpp \
    Lea/voyant_lea.cpp

HEADERS += \
    Henri/jaugeclignotanthenri.h \
    Henri/cadranthenri.h \
    Henri/henri_scene.h \
    Henri/jaugeclignotanthenri.h \
    Henri/jaugeessencehenri.h \
    Henri/jaugetemperaturehenri.h \
    Henri/jaugetoursminutehenri.h \
    Henri/scenedefondhenri.h \
    Hugo/hugo_compteur.h \
    Hugo/hugo_mygraphicsitem.h \
    Hugo/hugo_scene.h \
    Hugo/hugo_voyants_clignotant.h \
    Hugo/hugo_voyants_simples.h \
    Jonas/jonas_compteur.h \
    Jonas/jonas_scene.h \
    Leo/leo_scene.h \
    mainwindow.h \
    objet_virtuel.h \
    scene_globale.h \
    Florian/cadrantflorian.h \
    Florian/sceneflorian.h \
    Florian/voyant.h \
    Florian/clignotant.h \
    Henri/affichekmhenri.h \
    Henri/jaugebatteriehenri.h \
    Henri/warninghenri.h \
    Hugo/hugo_ecran.h \
    Hugo/hugo_voyant_warning.h \
    Henri/feuxhenri.h \
    Jonas/jonas_voyant_simple.h \
    Lea/deux_voyants_lea.h \
    Lea/fuelgauge_lea.h \
    Lea/lea_scene.h \
    Lea/phares_lea.h \
    Lea/quatre_voyants_lea.h \
    Lea/speedometer_lea.h \
    Lea/tachometergauge_lea.h \
    Lea/voyant_lea.h

FORMS += \
        mainwindow.ui \

RESOURCES += \
    Henri/images.qrc \
    Hugo/Icones/icones.qrc \
    florian.qrc \
    Lea/fuel.qrc

DISTFILES += \
    Henri/iconeEssence.png \
    Henri/iconeSurchaufe.png \
    Henri/liserMoi \
    Lea/Icones_Voyants/Oil_white.pix \
    Lea/Seven Segment.ttf \
    Lea/Icones_Voyants/4WD_blue.gif \
    Lea/Icones_Voyants/4WD_green.gif \
    Lea/Icones_Voyants/4WD_red.gif \
    Lea/Icones_Voyants/4WD_white.gif \
    Lea/Icones_Voyants/4WD_yellow.gif \
    Lea/Icones_Voyants/ABS_ON.gif \
    Lea/Icones_Voyants/adaptiveCruiseControl_green.gif \
    Lea/Icones_Voyants/adaptiveHeadlight.gif \
    Lea/Icones_Voyants/AdaptiveSuspensionDampers_red.gif \
    Lea/Icones_Voyants/AdaptiveSuspensionDampers_yellow.gif \
    Lea/Icones_Voyants/airBag.gif \
    Lea/Icones_Voyants/airSuspention_red.gif \
    Lea/Icones_Voyants/airSuspention_yellow.gif \
    Lea/Icones_Voyants/auto_D.gif \
    Lea/Icones_Voyants/auto_N.gif \
    Lea/Icones_Voyants/auto_P.gif \
    Lea/Icones_Voyants/auto_R.gif \
    Lea/Icones_Voyants/AWD_blue.gif \
    Lea/Icones_Voyants/AWD_green.gif \
    Lea/Icones_Voyants/AWD_red.gif \
    Lea/Icones_Voyants/AWD_white.gif \
    Lea/Icones_Voyants/AWD_yellow.gif \
    Lea/Icones_Voyants/backLeftDoorOpen.gif \
    Lea/Icones_Voyants/backrightDoorOpen.gif \
    Lea/Icones_Voyants/battery.gif \
    Lea/Icones_Voyants/bonnetOpen_red.gif \
    Lea/Icones_Voyants/bootOpen_red.gif \
    Lea/Icones_Voyants/brake_warning.gif \
    Lea/Icones_Voyants/brakeBulbFailure_yelow.gif \
    Lea/Icones_Voyants/brakeLiquid_red.gif \
    Lea/Icones_Voyants/brakePads.gif \
    Lea/Icones_Voyants/BulbFailure_yelow.gif \
    Lea/Icones_Voyants/checkEngine.gif \
    Lea/Icones_Voyants/dayLight.gif \
    Lea/Icones_Voyants/driverDoorOpen.gif \
    Lea/Icones_Voyants/engineT_blue.gif \
    Lea/Icones_Voyants/engineT_red.gif \
    Lea/Icones_Voyants/engineT_white.gif \
    Lea/Icones_Voyants/engineT_yellow.gif \
    Lea/Icones_Voyants/ExclamationPoint_red.gif \
    Lea/Icones_Voyants/ExclamationPoint_yellow.gif \
    Lea/Icones_Voyants/frontFogLight.gif \
    Lea/Icones_Voyants/frontRightDoorOpen.gif \
    Lea/Icones_Voyants/fuelL_red.gif \
    Lea/Icones_Voyants/fuelL_white.gif \
    Lea/Icones_Voyants/hazardLights.gif \
    Lea/Icones_Voyants/highBeam.gif \
    Lea/Icones_Voyants/lowBattery.gif \
    Lea/Icones_Voyants/lowBeam.gif \
    Lea/Icones_Voyants/OFF.gif \
    Lea/Icones_Voyants/Oil_t_white.gif \
    Lea/Icones_Voyants/Oil_white.gif \
    Lea/Icones_Voyants/powerSteering_red.gif \
    Lea/Icones_Voyants/powerSteering_yellow.gif \
    Lea/Icones_Voyants/rearFogLight.gif \
    Lea/Icones_Voyants/rearFogLight_blue.gif \
    Lea/Icones_Voyants/rearWindowHeating_yellow.gif \
    Lea/Icones_Voyants/scoda.gif \
    Lea/Icones_Voyants/seatBeltSign_red.gif \
    Lea/Icones_Voyants/securityLight_red.gif \
    Lea/Icones_Voyants/securityLight_yellow.gif \
    Lea/Icones_Voyants/tractionControl_blue.gif \
    Lea/Icones_Voyants/tractionControl_green.gif \
    Lea/Icones_Voyants/tractionControl_red.gif \
    Lea/Icones_Voyants/tractionControl_white.gif \
    Lea/Icones_Voyants/tractionControl_yellow.gif \
    Lea/Icones_Voyants/turnLeft.gif \
    Lea/Icones_Voyants/turnRight.gif \
    Lea/Icones_Voyants/tyrePressure_red.gif \
    Lea/Icones_Voyants/tyrePressure_yellow.gif \
    Lea/Icones_Voyants/washerLiquid_yellow.gif \
    Lea/Icones_Voyants/black-leather-texture-background.jpg \
    Lea/Icones_Voyants/bonnetOpen.png \
    Lea/Icones_Voyants/brake.png \
    Lea/Icones_Voyants/engineT_red.png \
    Lea/Icones_Voyants/gearProblem.png \
    Lea/Icones_Voyants/hand_brake.png \
    Lea/Icones_Voyants/Oil_red.png \
    Lea/Icones_Voyants/Oil_white.png \
    Lea/Icones_Voyants/seatBelt.png \
    Lea/ClignottantDroit.png \
    Lea/ClignottantGauche.png \
    Lea/fuel.png \
    Lea/fuel2.png \
    Lea/Oil.png \
    Lea/PorteOuverte.png \
    Lea/PorteOuverteConducteur.png \
    Lea/PorteOuvertePassagerD.png \
    Lea/PorteOuvertePassagerG.png \
    Lea/Seatbelt.png
