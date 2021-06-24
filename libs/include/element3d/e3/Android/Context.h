#ifndef __E3_ANDROID_CONTEXT__
#define __E3_ANDROID_CONTEXT__

#include <jni.h>
#include <string>

namespace e3
{
    namespace Android
    {
        class Context
        {
        public:
            Context();

        public:
            std::string GetFilesDir();
            std::string GetSDCardDir();
            jobject GetAssets();
            float GetDisplayDensity();

        private:
            jobject mHandle = nullptr;
            JNIEnv* mJniEnv = nullptr;

        private:
            std::string mFilesDir;
        };
    }
}

#endif // __E3_ANDROID_CONTEXT__