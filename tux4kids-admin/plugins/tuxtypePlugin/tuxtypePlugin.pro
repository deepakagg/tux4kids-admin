TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../ \
    ../../../libtux4kidsadmin \
    ../../../libtux4kidsadmin_tuxtype \
    ../../src
HEADERS = tuxtypePlugin.h \
    tuxtypeMainWidget.h \
    editWordListDialog.h
SOURCES = tuxtypePlugin.cpp \
    tuxtypeMainWidget.cpp \
    editWordListDialog.cpp
TARGET = $$qtLibraryTarget(TuxtypePlugin)
DESTDIR = ../
FORMS += tuxtypeMainWidget.ui \
    editWordListDialog.ui
LIBS += -ltux4kidsadmin \
    -L../../../libtux4kidsadmin
LIBS += -ltux4kidsadmintuxtype \
    -L../../../libtux4kidsadmin_tuxtype
