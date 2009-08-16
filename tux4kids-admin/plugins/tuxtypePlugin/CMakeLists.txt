PROJECT(tuxtypePlugin)
cmake_minimum_required(VERSION 2.6)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )

# enable warnings
ADD_DEFINITIONS(-Wall -DQT_PLUGIN -DQT_SHARED)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)

SET(TUXTYPE_PLUGIN_MOC_HEADERS 
	tuxtypePlugin.h
	tuxtypeMainWidget.h
	editWordListDialog.h )

SET(TUXTYPE_PLUGIN_SOURCES 
	tuxtypePlugin.cpp 
	tuxtypeMainWidget.cpp
	editWordListDialog.cpp )

SET(TUXTYPE_PLUGIN_UIS 
	tuxtypeMainWidget.ui
	editWordListDialog.ui )
	
SET(TUX4KIDS_ADMIN_SOURCES
	../../src/studentTableModel.cpp
	../../src/selectStudentWidget.cpp 
	../../src/studentTableProxyModel.cpp )

SET(TUX4KIDS_ADMIN_UIS
	../../src/selectStudentWidget.ui )	
	
SET(TUX4KIDS_ADMIN_MOC_HEADERS
	../../src/selectStudentWidget.h
	../../src/studentTableModel.h
	../../src/studentTableProxyModel.h )

FIND_PACKAGE( Qt4 REQUIRED )
INCLUDE( ${QT_USE_FILE} )
INCLUDE_DIRECTORIES( ../ ../../src ../../../libtux4kidsadmin_tuxtype ../../../libtux4kidsadmin ${CMAKE_CURRENT_BINARY_DIR} )

QT4_WRAP_UI( TUXTYPE_PLUGIN_UI_HEADERS ${TUXTYPE_PLUGIN_UIS} )
QT4_WRAP_UI( TUX4KIDS_ADMIN_UI_HEADERS ${TUX4KIDS_ADMIN_UIS} )
QT4_WRAP_CPP( TUXTYPE_PLUGIN_MOC_SOURCES ${TUXTYPE_PLUGIN_MOC_HEADERS} )
QT4_WRAP_CPP( TUX4KIDS_ADMIN_MOC_SOURCES ${TUX4KIDS_ADMIN_MOC_HEADERS} )

ADD_LIBRARY(TuxtypePlugin SHARED ${TUXTYPE_PLUGIN_MOC_SOURCES} ${TUXTYPE_PLUGIN_SOURCES} ${TUXTYPE_PLUGIN_UI_HEADERS} ${TUX4KIDS_ADMIN_SOURCES} ${TUX4KIDS_ADMIN_MOC_SOURCES} ${TUX4KIDS_ADMIN_UI_HEADERS} )
TARGET_LINK_LIBRARIES( TuxtypePlugin ${QT_LIBRARIES} tux4kidsadmin_tuxtype tux4kidsadmin )

