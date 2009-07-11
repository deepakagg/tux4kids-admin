QT -= gui
TARGET = tux4kidsadmin
TEMPLATE = lib
DEFINES += LIBTUX4KIDSADMIN_LIBRARY
SOURCES += libtux4kidsadmin.cpp \
    profileDir.cpp \
    profileDirPrivate.cpp
HEADERS += libtux4kidsadmin.h \
    libtux4kidsadmin_global.h \
    profileDir.h \
    profileDirPrivate.h
