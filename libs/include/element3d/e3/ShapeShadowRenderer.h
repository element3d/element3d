#ifndef __CARBON_SHAPE_SHADOW_RENDERER__
#define __CARBON_SHAPE_SHADOW_RENDERER__

#include "Carbon.h"
#include "Enum.h"
#include <glm.hpp>
#include <e3/Types.h>
#include <Carbon/Texture.h>
#include <Carbon/ShaderProgram.h>

namespace e3
{
    struct ShapeShadowRenderParams
    {
        EShapeType ShapeType;
        glm::mat4  Projection;
        glm::mat4  Scale;
        glm::mat4  Rotate;
        glm::mat4  Translate;
        glm::vec4  Color;
        float      Opacity;
        Texture* BackgroundMaskImage;
        e3::EBackgroundSize BackgroundSize;
        e3::EBackgroundPosition BackgroundPosition;
        glm::vec4  BorderRadius;
        e3::Rect2f Rect;
    };

    class ShapeShadowRenderer
    {
    public:
        static ShapeShadowRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new ShapeShadowRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Render(ShapeShadowRenderParams* pParams);

    private:
        ShapeShadowRenderer();
        ~ShapeShadowRenderer();

    private:
        void InitRectangle();
        void InitCircle();
        void RenderRectangle(ShapeShadowRenderParams* pParams);
        void RenderCircle(ShapeShadowRenderParams* pParams);

    private:
        static ShapeShadowRenderer* sInstance;

        GLuint mVAO = 0;

        struct
        {
            Carbon::ShaderProgram* Program = nullptr;
        } mRectangle;

        struct
        {
            Carbon::ShaderProgram* Program = nullptr;
        } mCircle;

    };
}

#endif // __CARBON_SHAPE_SHADOW_RENDERER__