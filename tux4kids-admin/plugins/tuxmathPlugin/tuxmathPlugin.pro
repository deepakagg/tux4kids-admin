TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../ \
    ../../../libtux4kidsadmin \
    ../../../libtux4kidsadmin_tuxmath \
    ../../src
HEADERS = tuxmathPlugin.h \
    tuxmathMainWidget.h \
    editTuxmathOptions.h
SOURCES = tuxmathPlugin.cpp \
    tuxmathMainWidget.cpp \
    editTuxmathOptions.cpp
TARGET = $$qtLibraryTarget(TuxmathPlugin)
DESTDIR = ../
FORMS += tuxmathMainWidget.ui \
    editTuxmathOptions.ui
LIBS += -ltux4kidsadmin \
    -L../../../libtux4kidsadmin
LIBS += -ltux4kidsadmintuxmath \
    -L../../../libtux4kidsadmin_tuxmath
