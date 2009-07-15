TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../ \
	       ../../../libtux4kidsadmin \
	       ../../../libtux4kidsadmin_tuxtype
HEADERS = tuxtypePlugin.h \
    tuxtypeMainWidget.h
SOURCES = tuxtypePlugin.cpp \
    tuxtypeMainWidget.cpp
TARGET = $$qtLibraryTarget(TuxtypePlugin)
DESTDIR = ../
FORMS += tuxtypeMainWidget.ui
LIBS += -ltux4kidsadmin -L../../../libtux4kidsadmin
LIBS += -ltux4kidsadmintuxtype -L../../../libtux4kidsadmin_tuxtype

