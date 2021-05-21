#ifndef __CARBON_CHECKBOX_RENDERER__
#define __CARBON_CHECKBOX_RENDERER__

#include <Carbon.h>
#include <glm.hpp>
#include <e3/Types.h>
//#include <opencv2/core/types.hpp>

namespace e3
{
    struct CheckboxRenderParams
    {
        glm::mat4 Projection;
        glm::mat4 Translate;
        glm::mat4 Rotate;
        glm::mat4 Scale;
        glm::vec4 Color;
        e3::Rect2f  Rect;
       // cv::Size  Resolution;
    };

    class CheckboxRenderer
    {
    public:
        static CheckboxRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new CheckboxRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Render(CheckboxRenderParams* pParams);

    private:
        CheckboxRenderer();
        ~CheckboxRenderer() {}

    private:
        static CheckboxRenderer* sInstance;

    private:
        GLuint mVAO = 0;
        Carbon::Buffer* mVertexBuffer = nullptr;
        Carbon::ShaderProgram* mProgram = nullptr;
    };
}

#endif // __CARBON_CHECKBOX_RENDERER__