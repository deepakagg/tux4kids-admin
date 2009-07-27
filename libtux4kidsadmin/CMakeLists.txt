project(libtux4kidsadmin)
cmake_minimum_required(VERSION 2.6)

SET(LIBTUX4KIDSADMIN_SOURCES 
	libtux4kidsadmin.cpp
	profileDir.cpp 
	schoolData.cpp
	studentDir.cpp 
	profileDirFactory.cpp 
	schoolDatabase.cpp 
	class.cpp 
	teacher.cpp )

SET(LIBTUX4KIDSADMIN_MOC_HEADERS 
	profileDir.h 
	schoolData.h
	studentDir.h 
	schoolDatabase.h )

# enable warnings
ADD_DEFINITIONS( -Wall -DLIBTUX4KIDSADMIN_LIBRARY )
#ADD_DEFINITIONS(-DQT_NO_DEBUG)

FIND_PACKAGE( Qt4 REQUIRED )
SET(QT_DONT_USE_QTGUI 1)
SET(QT_USE_QTSQL 1)
INCLUDE( ${QT_USE_FILE} )

QT4_WRAP_CPP( LIBTUX4KIDSADMIN_MOC_SOURCES ${LIBTUX4KIDSADMIN_MOC_HEADERS} )

ADD_LIBRARY(tux4kidsadmin SHARED ${LIBTUX4KIDSADMIN_SOURCES} ${LIBTUX4KIDSADMIN_MOC_SOURCES} )
TARGET_LINK_LIBRARIES( tux4kidsadmin ${QT_LIBRARIES} )
