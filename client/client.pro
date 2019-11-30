TEMPLATE = subdirs

SUBDIRS += \
    clientio \
    src

src.depends = clientio
