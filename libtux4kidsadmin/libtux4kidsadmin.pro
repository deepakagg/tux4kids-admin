QT -= gui
TARGET = tux4kidsadmin
TEMPLATE = lib
DEFINES += LIBTUX4KIDSADMIN_LIBRARY
SOURCES += libtux4kidsadmin.cpp \
    profileDir.cpp \
    profileDirPrivate.cpp \
    schoolData.cpp \
    schoolDataPrivate.cpp
HEADERS += libtux4kidsadmin.h \
    libtux4kidsadmin_global.h \
    profileDir.h \
    profileDirPrivate_p.h \
    schoolData.h \
    schoolDataPrivate_p.h
