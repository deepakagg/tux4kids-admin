#ifndef TUXMATHOPTIONS_H
#define TUXMATHOPTIONS_H

#include <QObject>

class TuxmathOptionsPrivate;

class TuxmathOptions : public QObject
{
	Q_OBJECT
public:
	TuxmathOptions(QString path);
	~TuxmathOptions();

protected:
	TuxmathOptionsPrivate *d_ptr;
	TuxmathOptions(TuxmathOptionsPrivate &dd);

private:
	Q_DECLARE_PRIVATE(TuxmathOptions)

};

#endif // TUXMATHOPTIONS_H
