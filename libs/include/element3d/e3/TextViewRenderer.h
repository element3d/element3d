#ifndef __CARBON_TEXTUREVIEW_RENDERER__
#define __CARBON_TEXTUREVIEW_RENDERER__

#include <Carbon.h>

namespace e3
{
    class TextViewRenderer
    {
    public:
        static TextViewRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new TextViewRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Bind();
        Carbon::Buffer* VertexBuffer() { return mVertexBuffer; }
        Carbon::ShaderProgram* ShaderProgram() { return mProgram; }
        void Render();

    private:
        TextViewRenderer();
        ~TextViewRenderer();

    private:
        void Init();

    private:
        static TextViewRenderer* sInstance;

        GLuint mVAO = 0;
        Carbon::Buffer* mVertexBuffer = nullptr;
        Carbon::ShaderProgram* mProgram = nullptr;

    };
}

#endif // __CARBON_TEXTUREVIEW_RENDERER__