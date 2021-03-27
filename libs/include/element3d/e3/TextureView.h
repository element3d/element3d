#ifndef __GLTEXTUREVIEW__
#define __GLTEXTUREVIEW__

#include "Shape.h"
#include "ShapeRenderer.h"
#include "ShapeShadowRenderer.h"

namespace e3
{

    class TextureView : public Shape
    {
    public:
        TextureView();

        ~TextureView();

    public:
        virtual void Update() override;

        virtual void Render() override;

        virtual void RenderShadow() override;
//    virtual void DrawBloom(const glm::mat4& projection) override;

    public:
        void setSrcColor(const glm::vec3 &color) { mSrcColor = glm::vec4(color, 1.0f); }

        void setSrcColor(const glm::vec4 &color) { mSrcColor = glm::vec4(glm::vec3(color), 1.0f); }

        void setSrcImagePath(const std::string &filename);

        template<typename T>
        void setSrcImageId(T id) { setSrcImageIdPrivate(static_cast<int>(id)); }

        void SetSrcImageUrl(const std::string &url);
        void SetSrcImageUrl(const std::string &url, const std::vector<std::string>& headers);

    private:
        void setSrcImageIdPrivate(int id);

    private:
        Texture *mTexture = nullptr;
        glm::vec4 mSrcColor = glm::vec4(0);

        bool mFirstFrame = true;
        float mAspectRatioWidth = 1.0f;
        float mAspectRatioHeight = 1.0f;
        e3::ShapeRenderParams *mImageShapeRenderParams = nullptr;
        e3::ShapeShadowRenderParams *mShapeShadowRenderParams = nullptr;
    };
}
#endif // __GLTEXTUREVIEW__
