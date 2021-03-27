#ifndef __CARBON_SHAPE_RENDERER__
#define __CARBON_SHAPE_RENDERER__

#include <Carbon.h>
#include "Enum.h"
#include <glm.hpp>
#include <e3/Types.h>
#include "ShapeRectangle.h"
#include "ShapeCircle.h"

namespace e3
{
    struct ShapeRenderParams
    {
        EShapeType ShapeType;
        glm::mat4  Projection;
        glm::mat4  Transform;
        glm::mat4  Scale;
        glm::mat4  Rotate;
        glm::mat4  Translate;
        glm::vec4  BackgroundColor;
        Image*     BackgroundImage;
		GLuint     ShapeTexture;
        glm::vec4  BackgroundImageColor;
        float      BackgroundImageOpacity;
        e3::EBackgroundSize BackgroundSize;
        e3::EBackgroundPosition BackgroundPosition;
        float      BorderSize;
        glm::vec4  BorderColor;
        glm::vec4  BorderRadius;
        e3::Rect2f Rect;
        float      Z = 0.0f;
        float      Opacity;
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
        ShapeGeometry* GetShape(EShapeType type);
        void Render(ShapeRenderParams* pParams, ShadowParams* pShadowParams = nullptr, GLuint shadowTexture = 0);
        void RenderShadow(ShapeRenderParams* pParams, ShadowParams* pShadowParams);

    private:
        ShapeRenderer();
        ~ShapeRenderer();

    private:
        void InitRectangle();
        void InitRoundedRectangleVS();
        void initHexagon();
        void InitCircle();
        void initShaderProgram();
        void RenderRectangle(ShapeRenderParams* pParams);
        void RenderRoundedRectangle(ShapeRenderParams* pParams);
        void RenderRoundedRectangleVS(ShapeRenderParams* pParams);
        void RenderHexagon(ShapeRenderParams* pParams);
        void RenderCircle(ShapeRenderParams* pParams, ShadowParams* pShadowParams = nullptr, GLuint shadowTexture = 0);
        void RenderCircleShadow(ShapeRenderParams* pParams, ShadowParams* pShadowParams);
        void RenderCustomShape(ShapeRenderParams* pParams);

    private:
        static ShapeRenderer* sInstance;

        GLuint mVAO = 0;
        float mBorderZDiff = 1.0f;
        float mBackgroundColorZDiff = 2.0f;
        float mBackgroundImageZDiff = 3.0f;

        struct
        {
            ShapeRectangle* Shape = nullptr;
            Carbon::ShaderProgram* Program = nullptr;
        } mRectangle;

        struct
        {
            Carbon::Buffer* VertexBuffer = nullptr;
            Carbon::Buffer* IndexBuffer = nullptr;
            int NumIndices = 0;
            int NumCornerPoints = 30;
            int NumVertices = 4 * 30;
            Carbon::ShaderProgram* Program = nullptr;
        } mRoundedRectangleVS;


        struct
        {
            Carbon::Buffer* VertexBuffer = nullptr;
            Carbon::Buffer* IndexBuffer = nullptr;
            int NumIndices = 0;
            Carbon::ShaderProgram* Program = nullptr;
        } mHexagon;

        struct
        {
            ShapeCircle* Shape = nullptr;
            Carbon::ShaderProgram* Program = nullptr;
        } mCircle;

        struct
        {
            Carbon::ShaderProgram* Program = nullptr;
        } mBorder;

        struct
        {
            Carbon::ShaderProgram* RectangleColorProgram = nullptr;
            Carbon::ShaderProgram* CircleColorProgram = nullptr;
            Carbon::ShaderProgram* CircleColorShadowProgram = nullptr;
        } mBackground;

        struct
        {
            Carbon::ShaderProgram* Program = nullptr;
        } mShadow;
        Carbon::ShaderProgram* mProgram = nullptr;

    };
}

#endif // __CARBON_SHAPE_RENDERER__