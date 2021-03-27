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
    class Animation;
    typedef std::function<void(float)> OnAnimationTickCallback;
    typedef std::function<void(Animation*)> OnAnimationEndCallback;

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
    public:
		Animation();

		~Animation();

		void start(float duration, float min, float max, OnAnimationTickCallback callback, OnAnimationEndCallback endCallback);

		void Start(float duration, OnAnimationTickCallback callback, OnAnimationEndCallback endCallback);
		void Start(float duration, EAnimation animation, OnAnimationTickCallback callback, OnAnimationEndCallback endCallback);
		void Start(float duration, float min, float max, EAnimation animation, OnAnimationTickCallback callback, OnAnimationEndCallback endCallback);

		void Stop();

		void reset(float duration, float start, float end);

		void Reset(float duration);

    public:
		void Tick();

    public:
		static void TickAll();

    private:
        std::chrono::time_point<std::chrono::system_clock> mBegin;
        OnAnimationTickCallback mCallback;
        OnAnimationEndCallback mEndCallback;
        float mDuration = 0.0f;
        bool mStop = false;
        float mStartValue = 0.0f;
        float mEndValue = 1.0f;

        static long sNumAnimations;
        static std::map<long, Animation*> sAnimations;
        static std::recursive_mutex sMutex;

		EAnimation mAnimation = EAnimation::None;
    };
}

#endif // __E3_ANIMATION__