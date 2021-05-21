#ifndef __E3_EVENT__
#define __E3_EVENT__

namespace e3 
{
	enum EEventType
	{
		MouseDown,
		MouseLongDown,
		MouseUp,
		MouseMove,
		MouseHover,
		MouseWhell,
		DoubleClick,
		Scale,
	};

	class Event 
	{
	public:
		Event();

		void Stop();
		bool IsStopped();

		void SetType(EEventType type);
		EEventType GetType();
	private:
		bool mStopped = false;
		EEventType mType;
	};
}

#endif // __E3_EVENT__
