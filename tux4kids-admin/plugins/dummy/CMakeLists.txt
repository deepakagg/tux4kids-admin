PROJECT(dummy_plugin)
cmake_minimum_required(VERSION 2.6)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../ )

# enable warnings
ADD_DEFINITIONS(-Wall -DQT_PLUGIN -DQT_SHARED)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)

SET(DUMMY_PLUGIN_MOC_HEADERS dummy.h)
SET(DUMMY_PLUGIN_SOURCES dummy.cpp)

FIND_PACKAGE( Qt4 REQUIRED )
INCLUDE( ${QT_USE_FILE} )
INCLUDE_DIRECTORIES( ../ ${CMAKE_CURRENT_BINARY_DIR} )

QT4_WRAP_CPP( DUMMY_PLUGIN_MOC_SOURCES ${DUMMY_PLUGIN_MOC_HEADERS} )

ADD_LIBRARY(DummyPlugin SHARED ${DUMMY_PLUGIN_MOC_SOURCES} ${DUMMY_PLUGIN_SOURCES} )
TARGET_LINK_LIBRARIES( DummyPlugin ${QT_LIBRARIES} )

