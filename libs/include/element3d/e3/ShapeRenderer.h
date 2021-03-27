#ifndef __CARBON_SHAPE_RENDERER__
#define __CARBON_SHAPE_RENDERER__

#include <Carbon.h>
#include "Enum.h"
#include <glm/glm.hpp>
#include <e3/Types.h>
#include "ShapeRectangle.h"
#include "ShapeCircle.h"
#include <e3/Style.h>

namespace e3
{
    struct ShapeRenderParams
    {
        glm::mat4  Projection;
        glm::mat4  Transform;
        glm::mat4  Scale;
        glm::mat4  Rotate;
        glm::mat4  Translate;
        //glm::vec4  BackgroundColor;
        //Image*     BackgroundImage;
		GLuint     ShapeTexture;
        //glm::vec4  BackgroundImageColor;
        //float      BackgroundImageOpacity;
        //e3::EBackgroundSize BackgroundSize;
        //e3::EBackgroundPosition BackgroundPosition;
        //float      BorderSize;
        //glm::vec4  BorderColor;
        //glm::vec4  BorderRadius;
        e3::Rect2f Rect;
        //float      Z = 0.0f;
        //float      Opacity;
      //  cv::Size   Resolution;
    };

    class ShapeRenderer
    {
    public:
        static ShapeRenderer* Get() {
            if (sInstance)
                return sInstance;

            sInstance = new ShapeRenderer();
            return sInstance;
        }

        static void Destroy() { delete sInstance; }

    public:
        void Render(Style* pStyle, ShapeRenderParams* pParams, ShadowParams* pShadowParams = nullptr, GLuint shadowTexture = 0);
		void Render2D(Style* pStyle, ShapeRenderParams* pParams, ShadowParams* pShadowParams = nullptr, GLuint shadowTexture = 0);
		void RenderToTexture(Style* pStyle, ShapeRenderParams* pParams, ShadowParams* pShadowParams);
        void Recreate();
    private:
        ShapeRenderer();
        ~ShapeRenderer();

    private:
        static ShapeRenderer* sInstance;

        float mBorderZDiff = 1.0f;
        float mBackgroundColorZDiff = 2.0f;
        float mBackgroundImageZDiff = 3.0f;

  
        Carbon::ShaderProgram* mShaderProgram = nullptr;
		Carbon::ShaderProgram* mShaderProgram2D = nullptr;
		Carbon::ShaderProgram* mOffscreenProgram = nullptr;
		Carbon::ShaderProgram* mShadowProgram = nullptr;
		

    };
}

#endif // __CARBON_SHAPE_RENDERER__