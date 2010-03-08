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

#include "tuxmathOptions.h"
#include "tuxmathOptions_p.h"

#include <QSettings>
#include <QStringList>
#include <QFile>
#include <QVariant>
#include <QDebug>

/****************************** TuxmathOptionsPrivate *******************/

TuxmathOptionsPrivate::TuxmathOptionsPrivate()
{
}

TuxmathOptionsPrivate::~TuxmathOptionsPrivate()
{
}

void TuxmathOptionsPrivate::loadFile()
{
	lines.clear();
	linePos.clear();

	QFile optionsFile(path);
	if (!optionsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}
	QTextStream stream(&optionsFile);

	while (!stream.atEnd()) {
		QString line = stream.readLine();
		if (!line.startsWith("#") && !line.isEmpty()) {
			line = line.simplified();
			QStringList fields = line.split("=", QString::SkipEmptyParts);
			if (fields.size() == 2) {
				fields[0] = fields[0].simplified();
				linePos[fields[0]] = lines.size();
			}
			//qDebug() << "found" << fields[0] << fields[1];
		}
		lines.append(line);
	}
}

void TuxmathOptionsPrivate::writeFile()
{
	QFile optionsFile(path);
	if (!optionsFile.open(QIODevice::WriteOnly | QFile::Truncate | QIODevice::Text)) {
		return;
	}
	optionsFile.resize(0);
	QTextStream stream(&optionsFile);

	for (int i = 0; i < lines.size(); ++i) {
		stream << lines.at(i) << "\n";
	}
}

void TuxmathOptionsPrivate::setValue(QString key, QVariant value)
{
	if (!linePos.contains(key)) {
		return;
	}

	int index = linePos[key];
	QStringList fields = lines[index].split("=", QString::SkipEmptyParts);

	switch (value.type()) {
	case QVariant::Bool:
		if (value.toBool()) {
			fields[1] = "1";
		} else {
			fields[1] = "0";
		}
		break;
	case QVariant::Int:
		fields[1] = QString::number(value.toInt());
		break;
	default: ;
	};
	lines[index] = fields.join(" = ");
}

QString TuxmathOptionsPrivate::value(QString key) const
{
	if (!linePos.contains(key)) {
		return QString();
	}

	int index = linePos[key];
	QStringList fields = lines[index].split("=", QString::SkipEmptyParts);

	return fields[1].trimmed();
}

/*************************** TuxmathOptions *******************/

TuxmathOptions::TuxmathOptions(QString path)
		: d_ptr(new TuxmathOptionsPrivate())
{
	Q_D(TuxmathOptions);
	d->q_ptr = this;

	d->path = path;
	d->loadFile();
/*	d->writeFile();

	qDebug() << additionAllowed() << substractionAllowed();
	setAdditionAllowed(false);
	qDebug() << additionAllowed() << substractionAllowed();*/
}

TuxmathOptions::TuxmathOptions(TuxmathOptionsPrivate &dd)
		: d_ptr(&dd)
{
	d_ptr->q_ptr = this;
}

TuxmathOptions::~TuxmathOptions()
{
	Q_D(TuxmathOptions);
	delete d;
}

bool TuxmathOptions::additionAllowed() const
{
	Q_D(const TuxmathOptions);
	if (d->value("ADDITION_ALLOWED") == "1") {
		return true;
	} else {
		return false;
	}
}

void TuxmathOptions::setAdditionAllowed(bool allow)
{
	Q_D(TuxmathOptions);
	d->setValue("ADDITION_ALLOWED", allow);
	d->writeFile();
}

bool TuxmathOptions::substractionAllowed() const
{
	Q_D(const TuxmathOptions);
	if (d->value("SUBTRACTION_ALLOWED") == "1") {
		return true;
	} else {
		return false;
	}
}

void TuxmathOptions::setSubstractionAllowed(bool allow)
{
	Q_D(TuxmathOptions);
	d->setValue("SUBTRACTION_ALLOWED", allow);
	d->writeFile();
}


