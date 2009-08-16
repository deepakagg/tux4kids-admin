PROJECT(tuxmathPlugin)
cmake_minimum_required(VERSION 2.6)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )

# enable warnings
ADD_DEFINITIONS(-Wall -DQT_PLUGIN -DQT_SHARED)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)

SET(TUXMATH_PLUGIN_MOC_HEADERS 
	tuxmathPlugin.h
	tuxmathMainWidget.h
	editTuxmathOptions.h )

SET(TUXMATH_PLUGIN_SOURCES 
	tuxmathPlugin.cpp 
	tuxmathMainWidget.cpp
	editTuxmathOptions.cpp )

SET(TUXMATH_PLUGIN_UIS 
	tuxmathMainWidget.ui
	editTuxmathOptions.ui )

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
INCLUDE_DIRECTORIES( ../ ../../src ../../../libtux4kidsadmin_tuxmath ../../../libtux4kidsadmin ${CMAKE_CURRENT_BINARY_DIR} )

QT4_WRAP_UI( TUXMATH_PLUGIN_UI_HEADERS ${TUXMATH_PLUGIN_UIS} )
QT4_WRAP_UI( TUX4KIDS_ADMIN_UI_HEADERS ${TUX4KIDS_ADMIN_UIS} )
QT4_WRAP_CPP( TUXMATH_PLUGIN_MOC_SOURCES ${TUXMATH_PLUGIN_MOC_HEADERS} )
QT4_WRAP_CPP( TUX4KIDS_ADMIN_MOC_SOURCES ${TUX4KIDS_ADMIN_MOC_HEADERS} )

ADD_LIBRARY(TuxmathPlugin SHARED ${TUXMATH_PLUGIN_MOC_SOURCES} ${TUXMATH_PLUGIN_SOURCES} ${TUXMATH_PLUGIN_UI_HEADERS} ${TUX4KIDS_ADMIN_SOURCES} ${TUX4KIDS_ADMIN_MOC_SOURCES} ${TUX4KIDS_ADMIN_UI_HEADERS} )
TARGET_LINK_LIBRARIES( TuxmathPlugin ${QT_LIBRARIES} tux4kidsadmin_tuxmath tux4kidsadmin )

