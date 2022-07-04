#ifndef __E3_ARC__
#define __E3_ARC__

#include "Element.h"

namespace e3 
{
	class Arc : public Element
	{
	public:
		Arc(Element* pParent = nullptr);

	public:
		void SetInnerRadius(const e3::Dim& radius);
		e3::Dim GetInnerRadius();

		void SetStartAngle(float degrees);
		float GetStartAngle();
		void SetEndAngle(float degrees);
		float GetEndAngle();
	};
}

#endif // __E3_ARC__
