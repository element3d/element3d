#ifndef __CARBON_RENDER_TARGET_MULTISAMPLE__
#define __CARBON_RENDER_TARGET_MULTISAMPLE__

//#include "Carbon.h"
#include <e3/GLTexture.h>

namespace e3
{
    struct RenderTargetMultisampleParams
    {
        int Width;
        int Height;
        int NumSamples;
    };

    class RenderTargetMultisample
    {
    public:
        RenderTargetMultisample(const RenderTargetMultisampleParams* pParams);
		~RenderTargetMultisample();

	public:
        void Bind();
        void Unbind();
        void Resolve();
        GLuint GetTexture() { return mTexture; }
//        Texture* GetTexture();

    private:
        GLuint mFramebuffer = 0;
        GLuint mFramebufferMSAA = 0;
        GLuint mDepthRenderBuffer = 0;
        GLuint mRenderBufferMSAA = 0;
        GLuint mDepthRenderBufferMSAA = 0;
        GLuint mTexture = 0;
        RenderTargetMultisampleParams* mParams = nullptr;
//        Texture* mTexture = nullptr;
    };
}

#endif // __CARBON_RENDER_TARGET_MULTISAMPLE__