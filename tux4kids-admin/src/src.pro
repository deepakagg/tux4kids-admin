TARGET = ../tux4kids-admin
TEMPLATE = app
INCLUDEPATH += ../plugins/
SOURCES += main.cpp \
    mainWindow.cpp \
    mainController.cpp \
    pluginManager.cpp \
    pluginManagerDialog.cpp
HEADERS += mainWindow.h \
    mainController.h \
    pluginManager.h \
    pluginManagerDialog.h
FORMS += mainWindow.ui \
    pluginManagerDialog.ui
