#ifndef __E3_ANDROID_APPICATION__
#define __E3_ANDROID_APPICATION__

#include <jni.h>
#include <string>
#include "../AssetManager.h"
#include "Context.h"

namespace e3
{
    namespace Android
    {
        class Application
        {
        public:
            Application();

        public:
            e3::Android::Context* GetContext();

        protected:
            e3::Android::Context* mContext = nullptr;
            AssetManager* mAssetManager = nullptr;
        };
    }
}

#endif // __E3_ANDROID_APPICATION__