#ifndef __GLEDITTEXT__
#define __GLEDITTEXT__

#include "ScrollView.h"
#include <time.h>
#include <ctime>
#include <mutex>
#include <e3/TextHolder.h>

/*namespace ftgl {
    struct vertex_buffer_t;
    struct texture_atlas_t;
    struct texture_font_t;
}*/

#include "Carbon/ShaderProgram.h"


namespace e3
{
    typedef std::function<void(const std::string& text)> OnEditTextChangeCallback;

    class EditText : public e3::ScrollView, public e3::TextHolder
    {
    public:
        EditText();

        /*float GetLineWidth(const std::string& line);
        float AddGlyph(char* current, char* previous);*/

    public:
        void initQuad();

        void initShaders();

        void SetText(const std::string &text);

        std::string getText();

        void RenderText(std::string text, glm::mat4 projection, GLfloat x, GLfloat y, GLfloat scale,
                        glm::vec3 color);

        void RenderHint();

        void RenderHint(std::string text, glm::mat4 projection, GLfloat x, GLfloat y, GLfloat scale,
                        glm::vec3 color);

        virtual void Render() override;

        virtual void Update() override;
        virtual bool OnClick(const glm::vec2 &pos) override;
        virtual void OnMouseMove(const glm::vec2 &distance, const glm::vec2& pos) override;

        void onKey(e3::EKey key, char c);

        virtual void Unfocus() override {
            Element::Unfocus();
            /*if (!mTextVec.size())*/ mShowHint = true;
        }

        void setTextColor(const glm::vec3 &textColor) { mTextColor = glm::vec4(textColor, 255.0f); }
        void SetHintColor(const glm::vec4 &hintColor) { mHintColor = hintColor; }

        void setTextColor(const glm::vec4 &textColor) { mTextColor = textColor; }
        void SetCursorColor(const glm::vec4 &cursorColor) { mCursorColor = cursorColor; }

        virtual void SetMaxNumLines(int numMaxLines) override;

        void SetHint(const std::string &hint) { mHint = hint; mHindUpdated = true; }

        virtual void Focus() override {
            Element::Focus();
            mShowHint = false;
        }

        void setFontSize(int fontSize);

        void SetOnChangeCallback(OnEditTextChangeCallback onEditTextChangeCallback) { mOnEditTextChangeCallback = onEditTextChangeCallback; }

    private:
        bool hasScroll();
        void doScroll(float dx);

    private:
        GLuint mVAO = 0;
        Carbon::ShaderProgram *mShader;

        struct {
            Carbon::Buffer *vertexBuffer;
            Carbon::Buffer *indexBuffer;
        } mQuad;

        struct {
            Carbon::Buffer *vertexBuffer;
        } mCursor;

        glm::vec2 mCursorPos = glm::vec2(0);
        std::vector<e3::Rect2f> mCharRects;
        std::string mHint = "";
        bool mHindUpdated = false;
        bool mShowHint = true;
        std::string mText = "";
        std::vector<char> mTextVec;
        glm::vec4 mTextColor = glm::vec4(0, 0, 0, 255);
        glm::vec4 mHintColor = glm::vec4(0);
        glm::vec4 mCursorColor = glm::vec4(0, 0, 0, 255);

        bool mTextUpdated = false;

        std::clock_t mAnimationTimerStart;

        std::mutex mCursorMutex;

        std::clock_t mCursorAnimationTimerStart;
        bool mShowCursor = false;

        float mTextScroll = 0.0f;
        float mFirstCharPosition = -1.0f;


        // std::vector<std::string> mLines;
        // int mFontSize = 0;
        int mInputIndex = 0;
        size_t         cursor = 0;
        ftgl::vertex_buffer_t* pHintVertexBuffer = nullptr;
        //ftgl::texture_atlas_t *atlas = nullptr;
        glm::vec2           pen;
        //ftgl::texture_font_t * font = nullptr;
        Carbon::ShaderProgram* shader = nullptr;
        //float mFontBottomOffset = 0.0f;

        Container* mTextLayout = nullptr;
        int mClickedLine = -1;
        glm::vec2 mClickedPos = glm::vec2(0);

        OnEditTextChangeCallback mOnEditTextChangeCallback = nullptr;
    };
}

#endif // __GLEDITTEXT__
