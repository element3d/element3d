#ifndef __CARBON_FX_BLUR__
#define __CARBON_FX_BLUR__

#include <Carbon.h>
#include "RenderTarget.h"

namespace e3
{
    struct FXBlurParams
    {
        int BlurSize;
        RenderTarget* SrcRenderTarget;
    };

    class FXBlur
    {
    public:
        FXBlur(const FXBlurParams* pParams);
		~FXBlur();

    public:
        GLuint Apply();
        void SetBlurSize(int blurSize) { mParams->BlurSize = blurSize; }

    private:
        FXBlurParams* mParams = nullptr;
        e3::RenderTarget* mRenderTargetsBlur[2];

    };
}

#endif // __CARBON_FX_BLUR__