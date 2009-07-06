TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../
HEADERS = tuxmathPlugin.h \
    tuxmathMainWidget.h
SOURCES = tuxmathPlugin.cpp \
    tuxmathMainWidget.cpp
TARGET = $$qtLibraryTarget(TuxmathPlugin)
DESTDIR = ../
FORMS += tuxmathMainWidget.ui
