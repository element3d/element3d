#ifndef __CARBON_RENDER_TARGET__
#define __CARBON_RENDER_TARGET__

#include <e3/GLTexture.h>

namespace e3
{
    struct RenderTargetParams
    {
        int Width;
        int Height;
        GLenum Type;
        ETextureFormat Format;
        GLInternalFormat InternalFormat;
    };

    class RenderTarget
    {
    public:
        RenderTarget(const RenderTargetParams* pParams);
        ~RenderTarget();

	public:
        void Bind();
        void Unbind();
        GLuint GetTexture() { return mTexture; }
        int GetWidth() { return mParams->Width; }
        int GetHeight() { return mParams->Height; }
//        Texture* GetTexture();

    private:
        RenderTargetParams* mParams = nullptr;
        GLuint mFramebuffer = 0;
        GLuint mDepthRenderBuffer = 0;
        GLuint mTexture = 0;
        GLuint mTexture2 = 0;
        GLuint mDepthTexture = 0;
//        Texture* mTexture = nullptr;
    };
}

#endif // __CARBON_RENDER_TARGET__
