#ifndef __CARBON_FX_BLUR_RENDERER__
#define __CARBON_FX_BLUR_RENDERER__

#include <Carbon.h>

namespace e3
{
    class FXBlurRenderer
    {
    public:
        static FXBlurRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new FXBlurRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        Carbon::ShaderProgram* GetShaderProgram() { return mProgram; }

    private:
        FXBlurRenderer();
        ~FXBlurRenderer() {}

    private:
        static FXBlurRenderer* sInstance;
        Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __CARBON_FX_BLUR_RENDERER__