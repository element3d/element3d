#ifndef __E3_SHAPE__
#define __E3_SHAPE__

#include <e3/Element.h>
#include "ShapeRenderer.h"
#include <e3/RenderTarget.h>
#include <e3/FXBlur.h>
#include <cpr/cpr.h>

namespace e3
{
    class Shape : public Element
    {
    public:
        Shape();
        ~Shape();

    public:
        //virtual void Render() override;
        //virtual void RenderShadow() override;
		//virtual void RenderToTexture();
        // virtual void Update() override;

    public:
        /*void SetShapeType(EShapeType shapeType);
        const EShapeType GetShapeType() const;*/

        /*virtual void SetBorderRadius(float radius);
        virtual void SetBorderRadius(const glm::vec4 &radius);
        const glm::vec4& GetBorderRadius() const;

        void SetBorderSize(float borderSize);
        const float GetBorderSize() const;

		void SetBorderColor(const glm::vec4 &color);
		void SetBorderColor(const glm::vec3 &color);
		const glm::vec4& GetBorderColor() const;*/

        /*void SetBackgroundColor(const glm::vec4 &color);
        void SetBackgroundColor(const glm::vec3 &color);
        const glm::vec4& GetBackgroundColor() const;*/

    public:
       /* void SetBackgroundImagePath(const std::string &path);
        void SetBackgroundImage(int id);
        void SetBackgroundImageUrl(const std::string &url);
        void SetBackgroundImageUrl(const std::string &url, const cpr::Header& header);
        void SetBackgroundImageOpacity(float opacity);

        void SetBackgroundImageFit(EBackgroundSize fit);
        void SetBackgroundImagePosition(EBackgroundPosition position);*/

    /*protected:
        ShapeRenderParams* mParams = nullptr;
        glm::vec2 mChildrenScrollDirection = glm::vec2(0);*/

    private:
        //glm::vec4 mBackgroundColorCurrent = glm::vec4(0);
        //glm::vec4 mBackgroundColor = glm::vec4(0);

        /*GLuint mShadowTexture = 0;
        e3::RenderTarget* mShadowRenderTarget = 0;

		e3::EOverflow mOverflow = EOverflow::Clip;
		//e3::RenderTarget* mRenderTarget = 0;
        FXBlur* mBlur = nullptr;*/
    };
}

#endif // __E3_SHAPE__