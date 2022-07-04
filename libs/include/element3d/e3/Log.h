#ifndef __E3_LOG__
#define __E3_LOG__

#define DEBUG 1
#define LOG_TAG "Element 3D:"

#ifdef __E3_OS_ANDROID__ 

#include <android/log.h>

#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif

#elif __EMSCRIPTEN__

#define ALOGE(...) printf(__VA_ARGS__)
#if DEBUG
#define ALOGV(...) printf(__VA_ARGS__)
#else
#define ALOGV(...)
#endif

#elif __E3_OS_WINDOWS__ || __E3_OS_LINUX__

#define ALOGE(...) printf(__VA_ARGS__)
#if DEBUG
#define ALOGV(...) printf(__VA_ARGS__)
#else
#define ALOGV(...)
#endif

#endif // __E3_OS_ANDROID__

#endif // __E3_LOG__
