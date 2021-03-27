#ifndef __GLTEXTVIEW__
#define __GLTEXTVIEW__

#include "View.h"
#include "Font.h"
#include "TextRenderer.h"

namespace e3
{
    class TextView : public View
    {
    public:
        TextView();

    public:
        void RenderText(std::string text, glm::mat4 projection, GLfloat x, GLfloat y, GLfloat scale,
                        glm::vec3 color);

        virtual void draw();

        virtual void update() override;

    public:
        void SetText(const std::string &text)
        {
            mText = text;
            mTextUpdated = true;
        }

        std::string getText() { return mText; }

        void setTextColor(const glm::vec3 &color) {
            mColor = color / 255.f;
        }

        void setTextColor(const glm::vec4 &color) {
            mColor = glm::vec3(color) / 255.f;
        }

        void setFontSize(int fontSize);

        void SetTextAlignVer(e3::EAlignment alignment);

        e3::EAlignment TextAlignVer();

        void SetTextAlignHor(e3::EAlignment alignment);

        e3::EAlignment TextAlignHor();

        int FontSize() { return mFontSize; }

        std::string Text() { return mText; }

        glm::vec3 TextColor() { return mColor; }

    private:
        e3::TextAlignFlags GetTextAlignFlags();

    private:
        e3::Font *mFont = NULL;
        int mFontSize = 0;
        float mTextWidth = 0;
        float mTextHeight = 0;
        std::string mText = "";
        glm::vec3 mColor;
        bool mTextUpdated = true;
        e3::TextAlignFlags mTextAlignFlags;
        e3::EAlignment mTextAlignVer;
        e3::EAlignment mTextAlignHor;
        std::vector<e3::TextLineParams> mLineParams;
        TextNode* mTextNode = nullptr;
        e3::TextRenderParams* mTextRenderParams = nullptr;
    };
}

#endif // __GLTEXTVIEW__
