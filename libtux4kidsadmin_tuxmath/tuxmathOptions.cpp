#include "tuxmathOptions.h"
#include "tuxmathOptions_p.h"

TuxmathOptionsPrivate::TuxmathOptionsPrivate()
{


}

TuxmathOptionsPrivate::~TuxmathOptionsPrivate()
{

}

/****************************** TuxmathOptionsPrivate *******************/


/*************************** TuxmathOptions *******************/

TuxmathOptions::TuxmathOptions(QString path)
		: d_ptr(new TuxmathOptionsPrivate())
{
	Q_D(TuxmathOptions);
	d->q_ptr = this;
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

