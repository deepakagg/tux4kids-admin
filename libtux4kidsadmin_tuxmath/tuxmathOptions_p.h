#ifndef TUXMATHOPTIONS_P_H
#define TUXMATHOPTIONS_P_H

#include <QtGlobal>
#include <QString>

class  TuxmathOptionsPrivate
{
public:
	Q_DECLARE_PUBLIC(TuxmathOptions)

	TuxmathOptionsPrivate();
	virtual ~TuxmathOptionsPrivate();

	TuxmathOptions *q_ptr;
};

#endif // TUXMATHOPTIONS_P_H
