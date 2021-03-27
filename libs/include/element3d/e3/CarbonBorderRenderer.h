#ifndef __CARBON_BORDER_RENDERER__
#define __CARBON_BORDER_RENDERER__

#include <Carbon.h>
#include "Enum.h"
#include <glm.hpp>
#include <e3/Types.h>
//#include <opencv2/core/types.hpp>

namespace Carbon
{
    struct BorderRenderParams
    {
        EBorderType BorderType;
        glm::mat4 Projection;
        glm::mat4 Transform;
        glm::vec3 Color;
        e3::Rect2f  Rect;
//        cv::Size  Resolution;
    };

    class BorderRenderer
    {
    public:
        static BorderRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new BorderRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Render(BorderRenderParams* pParams);

    private:
        BorderRenderer();
        ~BorderRenderer();

    private:
        void initHexagon();
        void InitRectangle();
        void InitCircle();
        void initShaderProgram();
        void RenderRectangle(BorderRenderParams* pParams);
        void RenderHexagon(BorderRenderParams* pParams);
        void RenderCircle(BorderRenderParams* pParams);

    private:
        static BorderRenderer* sInstance;

        GLuint mVAO = 0;

        struct
        {
            Carbon::Buffer* VertexBuffer = nullptr;
            int NumVertices = 0;
        } mRectangle;

        struct
        {
            Buffer* VertexBuffer = nullptr;
            int NumVertices = 0;
        } mHexagon;

        struct
        {
            Buffer* VertexBuffer = nullptr;
            int NumVertices = 0;
        } mCircle;

        Carbon::ShaderProgram* mProgram = nullptr;

    };
}

#endif // __CARBON_BORDER_RENDERER__