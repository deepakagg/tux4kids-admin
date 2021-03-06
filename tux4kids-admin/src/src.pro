TARGET = ../tux4kids-admin
TEMPLATE = app
QT += sql
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
    studentTableModel.cpp \
    studentTableProxyModel.cpp \
    manageClassesWidget.cpp \
    classTableModel.cpp \
    manageTeachersWidget.cpp \
    teacherTableModel.cpp \
    classTableProxyModel.cpp \
    teacherTableProxyModel.cpp \
    editTeacherDialog.cpp \
    editClassDialog.cpp \
    selectStudentWidget.cpp \
    selectTeacherWidget.cpp \
    selectClassWidget.cpp \
    studentTableDelegate.cpp
HEADERS += mainWindow.h \
    mainController.h \
    pluginManager.h \
    pluginManagerDialog.h \
    applicationInfo.h \
    errorLog.h \
    manageStudentsWidget.h \
    addStudentDialog.h \
    studentTableModel.h \
    studentTableProxyModel.h \
    manageClassesWidget.h \
    classTableModel.h \
    manageTeachersWidget.h \
    teacherTableModel.h \
    classTableProxyModel.h \
    teacherTableProxyModel.h \
    editTeacherDialog.h \
    editClassDialog.h \
    selectStudentWidget.h \
    selectTeacherWidget.h \
    selectClassWidget.h \
    studentTableDelegate.h
FORMS += mainWindow.ui \
    pluginManagerDialog.ui \
    manageStudentsWidget.ui \
    addStudentDialog.ui \
    manageClassesWidget.ui \
    manageTeachersWidget.ui \
    editTeacherDialog.ui \
    editClassDialog.ui \
    selectStudentWidget.ui \
    selectTeacherWidget.ui \
    selectClassWidget.ui
LIBS += -ltux4kidsadmin \
    -L../../libtux4kidsadmin
