cmake_minimum_required(VERSION 2.6)

add_subdirectory( src/ )
add_subdirectory( plugins/dummy/ )
add_subdirectory( plugins/tuxmathPlugin )
add_subdirectory( plugins/tuxtypePlugin )

find_package( Qt4 REQUIRED )
#INCLUDE_DIRECTORIES( tux4kids-admin/plugins ../libtux4kidsadmin_tuxmath ../libtux4kidsadmin )

SET(TS_FILES translations/tux4kids-admin_pl.ts )

QT4_ADD_TRANSLATION(QM_FILES ${TS_FILES})

