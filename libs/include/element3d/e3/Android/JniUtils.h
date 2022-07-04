#ifndef __E3_ANDROID_JNIUTILS__
#define __E3_ANDROID_JNIUTILS__

#include <jni.h>
#include <string>

namespace e3
{
    namespace Android
    {
        namespace JniUtils
        {
            std::string JStringToStdString(JNIEnv* pEnv, jstring jstr);
            jstring StdStringToJString(JNIEnv* pEnv, const std::string& str);
        }
    }
}

#endif // __E3_ANDROID_JNIUTILS__