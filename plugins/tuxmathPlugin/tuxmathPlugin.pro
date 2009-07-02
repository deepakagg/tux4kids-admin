TEMPLATE	= lib
CONFIG		+= plugin
INCLUDEPATH	+= ../

HEADERS		= tuxmathPlugin.h \

SOURCES		= tuxmathPlugin.cpp \

TARGET		= $$qtLibraryTarget(TuxmathPlugin)
DESTDIR		= ../

# Uncomment to use GCOV
# QMAKE_CXXFLAGS+=-fprofile-arcs -ftest-coverage

