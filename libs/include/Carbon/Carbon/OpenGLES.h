#ifndef __CARBON_OPENGLES__
#define __CARBON_OPENGLES__


#define DEBUG 1
#define LOG_TAG "Element 3D:"

#ifdef __E3_OS_ANDROID__ 
#if __ANDROID_API__ >= 24
#include <GLES3/gl32.h>
#elif __ANDROID_API__ >= 21
#include <GLES3/gl32.h>
#else
#include <GLES3/gl3.h>
#endif

#include <android/log.h>

#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#if DEBUG
#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
#define ALOGV(...)
#endif

#elif __EMSCRIPTEN__

#include <GLES3/gl31.h>

#define ALOGE(...) printf(__VA_ARGS__)
#if DEBUG
#define ALOGV(...) printf(__VA_ARGS__)
#else
#define ALOGV(...)
#endif

#elif __E3_OS_WINDOWS__ || __E3_OS_LINUX__

#include <GL/glew.h>

#define ALOGE(...) printf(__VA_ARGS__)
#if DEBUG
#define ALOGV(...) printf(__VA_ARGS__)
#else
#define ALOGV(...)
#endif

#endif // __E3_OS_ANDROID__

#endif // __CARBON_OPENGLES__
