#ifndef __E3_FONT_ICON__
#define __E3_FONT_ICON__

#include "Element.h"
#include "Font.h"
#include "AssetManager.h"
#include <Carbon/Texture.h>
#include "QuadRenderer.h"
#include "RenderTarget.h"
#include "FXBlur.h"

/*#include <freetype/ft2build.h>
#include FT_FREETYPE_H*/

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
        //void setFont(int id) { mFont = id; }
		void setFont(const std::string& font);
		void setCharcode(int charcode);
		void SetCharcode(const std::string& charcode); 
		void SetTextColor(const glm::vec4& color);
		glm::vec4 GetTextColor();

       /* virtual void RenderShadow() override
        {
            if (!texture || !mShadowParams)
                return;

            float scale = mShadowParams->Scale * 2;

            if (!mShadowRenderTarget)
            {
                RenderTargetParams p;
                p.Type = GL_UNSIGNED_BYTE;
                p.Width = GetGeometry().width * scale;
                p.Height = GetGeometry().height * scale;
                p.Format = ETextureFormat::R;
                p.InternalFormat = GLInternalFormat::R8;
                mShadowRenderTarget = new RenderTarget(&p);

                FXBlurParams bp;
                bp.SrcRenderTarget = mShadowRenderTarget;
                bp.BlurSize = mShadowParams->BlurSize;
                mBlur = new FXBlur(&bp);
            }
            if (mUpdateShadows)
            {
                mShadowRenderTarget->Bind();
                glClearColor(0, 1, 0, 1);
                glClear(GL_COLOR_BUFFER_BIT);
                //glEnable(GL_BLEND);
                glDisable(GL_BLEND);
                GLenum  err4 = glGetError();
                //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glViewport(0, 0, GetGeometry().width * scale, GetGeometry().height * scale);
                e3::QuadRenderer::Get().BindVertexArray();
                mProgramShadow->bind();
                GLenum  err3853 = glGetError();
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, texture);
                mProgramShadow->setFloat("uZ", GetZ() + 20);
                mProgramShadow->setFloat("uOpacity", mShadowParams->Opacity);
                mProgramShadow->setInt("uTexture", 0);

                e3::QuadRenderer::Get().Render();
                GLenum  err2 = glGetError();
                glDisable(GL_BLEND);
                mShadowRenderTarget->Unbind();
                mShadowTexture = mBlur->Apply();
                mUpdateShadows = false;
            }
        }*/

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
        e3::RenderTarget* mShadowRenderTarget = 0;
        FXBlur* mBlur = nullptr;
        //e3::RenderTarget* mShadowRenderTarget = 0;


    };
}

#endif // __E3_FONT_ICON__
