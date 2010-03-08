/*

This file is part of Libtux4kidsadmin-tuxmath

Libtux4kidsadmin-tuxmath is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Libtux4kidsadmin-tuxmath is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Libtux4kidsadmin-tuxmath.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef TUXMATHOPTIONS_H
#define TUXMATHOPTIONS_H

#include <QObject>
#include "libtux4kidsadmin_tuxmath_global.h"

class TuxmathOptionsPrivate;

class LIBTUX4KIDSADMIN_TUXMATH_SHARED_EXPORT TuxmathOptions : public QObject
{
	Q_OBJECT
public:
	TuxmathOptions(QString path);
	~TuxmathOptions();

	bool additionAllowed() const;
	void setAdditionAllowed(bool allow);
	bool substractionAllowed() const;
	void setSubstractionAllowed(bool allow);

protected:
	TuxmathOptionsPrivate * const d_ptr;
	TuxmathOptions(TuxmathOptionsPrivate &dd);

private:
	Q_DECLARE_PRIVATE(TuxmathOptions)
	Q_DISABLE_COPY(TuxmathOptions)

};

#endif // TUXMATHOPTIONS_H
