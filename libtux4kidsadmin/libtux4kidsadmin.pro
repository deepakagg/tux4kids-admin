QT -= gui
TARGET = tux4kidsadmin
TEMPLATE = lib
DEFINES += LIBTUX4KIDSADMIN_LIBRARY
SOURCES += libtux4kidsadmin.cpp \
    profileDir.cpp \
    schoolData.cpp \
    studentDir.cpp \
    profileDirFactory.cpp
HEADERS += libtux4kidsadmin.h \
    libtux4kidsadmin_global.h \
    profileDir.h \
    schoolData.h \
    schoolData_p.h \
    profileDir_p.h \
    studentDir.h \
    studentDir_p.h \
    profileDirFactory.h \
    profileDirFactory_p.h
