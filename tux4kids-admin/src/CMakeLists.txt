PROJECT(tux4kids-admin)
cmake_minimum_required(VERSION 2.6)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )

SET(TUX4KIDS-ADMIN_SOURCES 
	main.cpp
	mainWindow.cpp
	mainController.cpp
	pluginManager.cpp 
	pluginManagerDialog.cpp 
	manageStudentsWidget.cpp
	addStudentDialog.cpp
	studentTableModel.cpp 
	studentTableProxyModel.cpp 
	manageClassesWidget.cpp 
	classTableModel.cpp
	manageTeachersWidget.cpp 
	teacherTableModel.cpp 
	classTableProxyModel.cpp 
	teacherTableProxyModel.cpp 
	editClassDialog.cpp 
	editTeacherDialog.cpp
	selectStudentWidget.cpp
	selectTeacherWidget.cpp
	selectClassWidget.cpp )

SET(TUX4KIDS-ADMIN_MOC_HEADERS 
	mainWindow.h
	mainController.h 
	pluginManager.h 
	pluginManagerDialog.h 
	manageStudentsWidget.h
	addStudentDialog.h
	studentTableModel.h 
	studentTableProxyModel.h 
	manageClassesWidget.h 
	classTableModel.h 
	manageTeachersWidget.h
	teacherTableModel.h 
	classTableProxyModel.h 
	teacherTableProxyModel.h 
	editClassDialog.h 
	editTeacherDialog.h
	selectStudentWidget.h
	selectTeacherWidget.h
	selectClassWidget.h )

SET(TUX4KIDS-ADMIN_UIS 
	mainWindow.ui 
	pluginManagerDialog.ui 
	manageStudentsWidget.ui 
	addStudentDialog.ui
	manageClassesWidget.ui 
	manageTeachersWidget.ui 
	editClassDialog.ui 
	editTeacherDialog.ui
	selectStudentWidget.ui
	selectTeacherWidget.ui
	selectClassWidget.ui )

# enable warnings
ADD_DEFINITIONS( -Wall )

FIND_PACKAGE( Qt4 REQUIRED )
SET(QT_USE_QTSQL 1)
INCLUDE( ${QT_USE_FILE} )
INCLUDE_DIRECTORIES( ../plugins/ ../../libtux4kidsadmin/ ${CMAKE_CURRENT_BINARY_DIR} )

QT4_WRAP_UI( TUX4KIDS-ADMIN_UI_HEADERS ${TUX4KIDS-ADMIN_UIS} )
QT4_WRAP_CPP( TUX4KIDS-ADMIN_MOC_SOURCES ${TUX4KIDS-ADMIN_MOC_HEADERS} )

ADD_EXECUTABLE( tux4kids-admin ${TUX4KIDS-ADMIN_SOURCES} ${TUX4KIDS-ADMIN_MOC_SOURCES} ${TUX4KIDS-ADMIN_UI_HEADERS} )
TARGET_LINK_LIBRARIES( tux4kids-admin ${QT_LIBRARIES} tux4kidsadmin)
