TEMPLATE = lib
CONFIG += unversioned_libname
CONFIG -= qt

SOURCES += \
    clientio.c

HEADERS += \
    clientio.h

unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
