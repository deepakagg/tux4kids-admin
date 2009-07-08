TARGET = ../tux4kids-admin
TEMPLATE = app
INCLUDEPATH += ../plugins/

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


