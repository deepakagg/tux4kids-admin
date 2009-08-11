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
