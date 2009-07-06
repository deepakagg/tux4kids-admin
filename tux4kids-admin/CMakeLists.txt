cmake_minimum_required(VERSION 2.6)

add_subdirectory( src/ )
add_subdirectory( plugins/dummy/ )
add_subdirectory( plugins/tuxmathPlugin )

find_package( Qt4 REQUIRED )

SET(TS_FILES translations/tux4kids-admin_pl.ts )

QT4_ADD_TRANSLATION(QM_FILES ${TS_FILES})

