TEMPLATE = lib
CONFIG += unversioned_libname unversioned_soname
CONFIG -= qt

SOURCES += \
    clientio.c

HEADERS += \
    clientio.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
