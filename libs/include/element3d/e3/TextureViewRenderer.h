#ifndef __CARBON_TEXTUREVIEW_RENDERER__
#define __CARBON_TEXTUREVIEW_RENDERER__

#include <Carbon.h>

namespace e3
{
    class TextureViewRenderer
    {
    public:
        static TextureViewRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new TextureViewRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Bind();
        Carbon::Buffer* VertexBuffer() { return mQuad.vertexBuffer; }
        Carbon::Buffer* IndexBuffer() { return mQuad.indexBuffer; }
        Carbon::ShaderProgram* ShaderProgram() { return mQuad.Program; }
        void Render();

    private:
        TextureViewRenderer();
        ~TextureViewRenderer();

    private:
        void InitQuad();

    private:
        static TextureViewRenderer* sInstance;

        struct
        {
            GLuint VAO = 0;
            Carbon::Buffer* vertexBuffer = NULL;
            Carbon::Buffer* indexBuffer = NULL;
            Carbon::ShaderProgram* Program = NULL;
        } mQuad;
    };
}

#endif // __CARBON_TEXTUREVIEW_RENDERER__