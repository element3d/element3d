#ifndef __E3_FONT_ICON__
#define __E3_FONT_ICON__

#include "Element.h"
#include "Font.h"
#include "AssetManager.h"
#include <Carbon/Texture.h>
//#include "RenderTarget.h"

namespace e3
{
    class FontIcon : public Element
    {
    public:
        FontIcon();

    public:
        void Update() override;
        void Render() override;

    public:
		void SetFlip(bool flip, EOrientation direction);
		void setFont(const std::string& font);
		void setCharcode(int charcode);
		void SetCharcode(const std::string& charcode); 
		void SetTextColor(const glm::vec4& color);
		glm::vec4 GetTextColor();

      

    private:
		bool reloadFont();

    private:
        glm::vec2 mFontScale = glm::vec2(1.0f);
		bool mFlip[2];
        std::string mFont = "";
		//int mFont = -1;
        int mCharcode = -1;
        Texture* mTexture = nullptr;
        Carbon::ShaderProgram* mProgram = nullptr;
        Carbon::ShaderProgram* mProgramShadow = nullptr;
        GLuint texture = 0;
        glm::vec4 mColor = glm::vec4(0);
        GLuint mShadowTexture = 0;
//        e3::RenderTarget* mShadowRenderTarget = 0;


    };
}

#endif // __E3_FONT_ICON__
