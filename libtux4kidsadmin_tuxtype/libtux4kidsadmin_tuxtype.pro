QT -= gui
TARGET = tux4kidsadmintuxtype
TEMPLATE = lib
DEFINES += LIBTUX4KIDSADMIN_TUXTYPE_LIBRARY
SOURCES += libtux4kidsadmin_tuxtype.cpp \
    profileDirTuxtype.cpp
HEADERS += libtux4kidsadmin_tuxtype.h \
    libtux4kidsadmin_tuxtype_global.h \
    profileDirTuxtype.h \
    profileDirTuxtype_p.h
INCLUDEPATH += ../libtux4kidsadmin
LIBS += -ltux4kidsadmin \
    -L../libtux4kidsadmin
