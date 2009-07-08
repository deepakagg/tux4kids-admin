#ifndef LIBTUX4KIDSADMIN_TUXMATH_GLOBAL_H
#define LIBTUX4KIDSADMIN_TUXMATH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBTUX4KIDSADMIN_TUXMATH_LIBRARY)
#  define LIBTUX4KIDSADMIN_TUXMATHSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBTUX4KIDSADMIN_TUXMATHSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBTUX4KIDSADMIN_TUXMATH_GLOBAL_H
