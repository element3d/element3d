#ifndef __CARBON_QUAD_RENDERER__
#define __CARBON_QUAD_RENDERER__

#include <Carbon/Buffer.h>
#include <Carbon/ShaderProgram.h>


namespace e3
{
    /*extern */class QuadRenderer
    {
    public:
        static QuadRenderer& Get();
		//static QuadRenderer* Get();
        void Destroy();

    public:
        void Recreate();
        void Bind();
		void BindVertexArray1();
        void BindVertexArray();
        void Unbind();
        void UnindVertexArray();
        Carbon::Buffer* GetVertexBuffer() { return mVertexBuffer; }
        Carbon::Buffer* GetIndexBuffer() { return mIndexBuffer; }
        Carbon::ShaderProgram* GetShaderProgram() { return mProgram; }
        void Render();

    public:
        QuadRenderer();
        ~QuadRenderer();

    private:
        void Init();

    private:
     //   static QuadRenderer* sInstance;
        GLuint mVAO = 0;
        Carbon::Buffer* mVertexBuffer = nullptr;
        Carbon::Buffer* mIndexBuffer = nullptr;
        Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __CARBON_QUAD_RENDERER__
