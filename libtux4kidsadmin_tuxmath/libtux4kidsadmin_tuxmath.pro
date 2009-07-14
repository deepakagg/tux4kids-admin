QT -= gui
TARGET = tux4kidsadmintuxmath
TEMPLATE = lib
DEFINES += LIBTUX4KIDSADMIN_TUXMATH_LIBRARY
SOURCES += libtux4kidsadmin_tuxmath.cpp \
    profileDirTuxmath.cpp
HEADERS += libtux4kidsadmin_tuxmath.h \
    libtux4kidsadmin_tuxmath_global.h \
    profileDirTuxmath.h \
    profileDirTuxmath_p.h
INCLUDEPATH += ../libtux4kidsadmin
LIBS += -ltux4kidsadmin \
    -L../libtux4kidsadmin
