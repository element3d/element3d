#ifndef __E3_ARC__
#define __E3_ARC__

#include "Element.h"

namespace e3 
{
	class Arc : public Element
	{
	public:
		Arc();

	public:
		void SetInnerRadius(const e3::Dim& radius);
		e3::Dim GetInnerRadius();
	};
}

#endif // __E3_ARC__
