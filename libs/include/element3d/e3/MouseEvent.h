#ifndef __E3_MOUSE_EVENT__
#define __E3_MOUSE_EVENT__

#include "Event.h"
namespace e3
{
	class MouseEvent : public Event
	{
	public:
		MouseEvent();

		void SetX(float x);
		void SetY(float y);

		float GetX();
		float GetY();

		void SetDistanceX(float distanceX);
		void SetDistanceY(float distanceY);

		float GetDistanceX();
		float GetDistanceY();

	private:
		float mX;
		float mY;
		float mDistanceX;
		float mDistanceY;
	};
}

#endif // __E3_MOUSE_EVENT__