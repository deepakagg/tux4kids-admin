TARGET = ../tux4kids-admin
TEMPLATE = app
INCLUDEPATH += ../plugins/ \
	       ../../libtux4kidsadmin \
	       ../../libtux4kidsadmin_tuxmath

SOURCES += main.cpp \
    mainWindow.cpp \
    mainController.cpp \
    pluginManager.cpp \
    pluginManagerDialog.cpp \
    applicationInfo.cpp \
    errorLog.cpp
HEADERS += mainWindow.h \
    mainController.h \
    pluginManager.h \
    pluginManagerDialog.h \
    applicationInfo.h \
    errorLog.h
FORMS += mainWindow.ui \
    pluginManagerDialog.ui
LIBS += -ltux4kidsadmin -L../../libtux4kidsadmin
LIBS += -ltux4kidsadmintuxmath -L../../libtux4kidsadmin_tuxmath

