#ifndef __CARBON_SHADOW_RENDERER__
#define __CARBON_SHADOW_RENDERER__

#include <Carbon.h>

namespace e3
{
    class ShadowRenderer
    {
    public:
        static ShadowRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new ShadowRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        Carbon::ShaderProgram* GetShaderProgram() { return mProgram; }

    private:
        ShadowRenderer();
        ~ShadowRenderer() {}

    private:
        static ShadowRenderer* sInstance;
        Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __CARBON_SHADOW_RENDERER__