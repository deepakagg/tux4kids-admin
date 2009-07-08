TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../ \
	       ../../../libtux4kidsadmin \
	       ../../../libtux4kidsadmin_tuxmath
HEADERS = tuxmathPlugin.h \
    tuxmathMainWidget.h
SOURCES = tuxmathPlugin.cpp \
    tuxmathMainWidget.cpp
TARGET = $$qtLibraryTarget(TuxmathPlugin)
DESTDIR = ../
FORMS += tuxmathMainWidget.ui
LIBS += -ltux4kidsadmin -L../../../libtux4kidsadmin
LIBS += -ltux4kidsadmintuxmath -L../../../libtux4kidsadmin_tuxmath

