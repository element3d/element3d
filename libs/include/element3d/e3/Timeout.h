#ifndef __E3_TIMEOUT__
#define __E3_TIMEOUT__

#include <chrono>
#include <map>
#include <functional>
#include <memory>
#include "Types.h"

namespace e3 
{
	

	class Timeout;
	class OnTimeoutCallback : public Callback<void()> 
	{
	public:
		OnTimeoutCallback(std::function<void()> f) : Callback(f) {}
		OnTimeoutCallback(e3::Element* pParent, std::function<void()> f) : Callback(pParent, f) {}
	private:
		~OnTimeoutCallback() {}

		friend class Timeout;
	};

	//typedef std::function<void(void)> OnTimeoutCallback;

	class Timeout 
	{
	public:
		Timeout();

	public:
		//void Start(float duration, OnTimeoutCallback onTimeoutCallback);
		void Start(float duration, OnTimeoutCallback* onTimeoutCallback);
		void Reset(float duration);
		void Reset();

		void Stop();

	public:
		void Tick();

	public:
		static void TickAll();

	private:
		float mDuration = 0.0f;
		std::chrono::time_point<std::chrono::system_clock> mBegin;
		bool mStop = false;
		OnTimeoutCallback* mOnTimeoutCallback = nullptr;

		static long sNumTimeouts;
		static std::map<long, Timeout*> sTimeouts;
	//	Callback<void(void)> mC;
	};
}

#endif // __E3_TIMEOUT__