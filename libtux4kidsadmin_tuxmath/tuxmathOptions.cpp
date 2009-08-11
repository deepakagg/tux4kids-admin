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


