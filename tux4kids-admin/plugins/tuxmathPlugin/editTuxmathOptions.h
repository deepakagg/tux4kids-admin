/*

This file is part of Tux4kids-admin Tuxmath plugin

Tux4kids-admin Tuxmath plugin is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or any later version.

Tux4kids-admin Tuxmath plugin is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tux4kids-admin Tuxmath plugin.  If not, see <http://www.gnu.org/licenses/>.

Author: Michał Świtakowski <tux4kids at_here switakowski.com>, Copyright (C) 2009

*/

#ifndef EDITTUXMATHOPTIONS_H
#define EDITTUXMATHOPTIONS_H

#include <QtGui/QDialog>

namespace Ui {
	class EditTuxmathOptions;
}

class EditTuxmathOptions : public QDialog
{
	Q_OBJECT
public:
	EditTuxmathOptions(QWidget *parent = 0);
	~EditTuxmathOptions();

	bool allowAddition() const;
	bool allowSubstraction() const;

private:
	Ui::EditTuxmathOptions *m_ui;
};

#endif // EDITTUXMATHOPTIONS_H
