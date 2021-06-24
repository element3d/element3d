#ifndef __E3_ANDROID_JNIENV__
#define __E3_ANDROID_JNIENV__

#include <jni.h>
#include <string>

namespace e3
{
    namespace Android
    {
        class JniEnv
        {
        public:
            static JniEnv* Get();

        public:
            void SetEnv(JNIEnv* pEnv);
            JNIEnv* GetEnv();

        public:
            std::string JStringToStdString(jstring jstr);
            jstring StdStringToJString(const std::string& str);

        private:
            static JniEnv* sInstance;
            JNIEnv* mHandle = nullptr;
        };
    }
}

#endif // __E3_ANDROID_JNIENV__