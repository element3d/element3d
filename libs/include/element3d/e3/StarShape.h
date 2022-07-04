#ifndef __E3_STAR_SHAPE__
#define __E3_STAR_SHAPE__

#include "Element.h"

namespace e3
{
	class StarShape : public Element
	{
	public:
		StarShape(Element* pParent = nullptr);

		void SetNumVertices(int numVertices);
		int GetNumVertices();

		void SetAngleDivisor(float angleDivisor);
		float GetAngleDivisor();
	};
}

#endif // __E3_ARC__
