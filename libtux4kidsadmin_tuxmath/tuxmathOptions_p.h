#ifndef TUXMATHOPTIONS_P_H
#define TUXMATHOPTIONS_P_H

#include <QtGlobal>
#include <QString>
#include <QHash>

class QSettings;

class  TuxmathOptionsPrivate
{
public:
	Q_DECLARE_PUBLIC(TuxmathOptions)

	TuxmathOptionsPrivate();
	virtual ~TuxmathOptionsPrivate();

	TuxmathOptions *q_ptr;

	//QSettings *optionsFile;
	QString path;
	QList<QString> lines;
	QHash<QString, int> linePos;

	void loadFile();
	void writeFile();
	void setValue(QString key, QVariant value);
	QString value(QString key) const;


};

#endif // TUXMATHOPTIONS_P_H
