#ifndef __E3_ANIMATION__
#define __E3_ANIMATION__

#include <thread>
#include <mutex>
#include <ctime>
#include <functional>
#include <map>
#include <cmath>
#include <vector>
#include <chrono>

namespace e3
{
//    class Animation;


	enum class EAnimation
	{
		EaseInSine,
		EaseOutSine,
		EaseInOutSine,
		EaseInQuad,
		EaseOutQuad,
		EaseInOutQuad,
		EaseInCubic,
		EaseOutCubic,
		EaseInOutCubic,
		EaseInQuart,
		EaseOutQuart,
		EaseInOutQuart,
		EaseInQuint,
		EaseOutQuint,
		EaseInOutQuint,
		EaseInExpo,
		EaseOutExpo,
		EaseInOutExpo,
		EaseInCirc,
		EaseOutCirc,
		EaseInOutCirc,
		EaseInBack,
		EaseOutBack,
		EaseInOutBack,
		EaseInElastic,
		EaseOutElastic,
		EaseInOutElastic,
		EaseInBounce,
		EaseOutBounce,
		EaseInOutBounce,

		None
	};

    class Animation
    {
		typedef std::function<void(float)> OnValueCallback;
		typedef std::function<void(void)> OnEndCallback;

    public:
		Animation();
		~Animation();

		void SetDuration(float duration);

		void Start();
		void Start(float duration, OnValueCallback callback, OnEndCallback endCallback);
		void Start(float duration, float min, float max, OnValueCallback callback, OnEndCallback endCallback);
		void Start(float duration, EAnimation animation, OnValueCallback callback, OnEndCallback endCallback);
		void Start(float duration, float min, float max, EAnimation animation, OnValueCallback callback, OnEndCallback endCallback);

		void Reset(float duration, float start, float end);
		void Reset(float duration);

		void Stop();

		void AddOnValueCallback(OnValueCallback c);
		void AddOnEndCallback(OnEndCallback c);
    public:
		void Tick();

    public:
		static void TickAll();

    private:
        std::chrono::time_point<std::chrono::system_clock> mBegin;
        std::vector<OnValueCallback> mCallbacks;
        std::vector<OnEndCallback> mEndCallbacks;
        float mDuration = 0.0f;
        bool mStop = true;
        float mStartValue = 0.0f;
        float mEndValue = 1.0f;

        static long sNumAnimations;
        static std::map<long, Animation*> sAnimations;
        static std::recursive_mutex sMutex;

		EAnimation mAnimation = EAnimation::None;
    };
}

#endif // __E3_ANIMATION__