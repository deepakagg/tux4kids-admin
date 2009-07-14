TARGET = ../tux4kids-admin
TEMPLATE = app
INCLUDEPATH += ../plugins/ \
    ../../libtux4kidsadmin/
SOURCES += main.cpp \
    mainWindow.cpp \
    mainController.cpp \
    pluginManager.cpp \
    pluginManagerDialog.cpp \
    applicationInfo.cpp \
    errorLog.cpp \
    manageStudentsWidget.cpp \
    addStudentDialog.cpp \
    studentTableModel.cpp
HEADERS += mainWindow.h \
    mainController.h \
    pluginManager.h \
    pluginManagerDialog.h \
    applicationInfo.h \
    errorLog.h \
    manageStudentsWidget.h \
    addStudentDialog.h \
    studentTableModel.h
FORMS += mainWindow.ui \
    pluginManagerDialog.ui \
    manageStudentsWidget.ui \
    addStudentDialog.ui
