#ifndef __E3_SCALE_EVENT__
#define __E3_SCALE_EVENT__

#include "MouseEvent.h"

namespace e3 
{
	class ScaleEvent : public MouseEvent
	{
	public:
		ScaleEvent();

		void SetScaleFactor(float scaleFactor);
		float GetScaleFactor();

	private:
		float mScaleFactor;
	};
}

#endif // __E3_SCALE_EVENT__