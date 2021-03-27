#ifndef __GLEDITTEXT__
#define __GLEDITTEXT__

#include "View.h"
#include <time.h>
#include <mutex>
#include <ctime>

namespace e3
{

    class EditText : public View
    {
    public:
        EditText();

    public:
        void initQuad();

        void initShaders();

        void setText(const std::string &text);

        std::string getText();

        void RenderText(std::string text, glm::mat4 projection, GLfloat x, GLfloat y, GLfloat scale,
                        glm::vec3 color);

        void RenderHint(std::string text, glm::mat4 projection, GLfloat x, GLfloat y, GLfloat scale,
                        glm::vec3 color);

        virtual void draw() override;

        //  virtual void update() {}
        virtual bool onClick(const glm::vec2 &pos) override;

        void onKey(e3::EKey key, char c);

        virtual void Unfocus() override {
            View::Unfocus();
            mUnderlineXScale = 0.0f;
            if (!mTextVec.size()) mShowHint = true;
        }

        void setTextColor(const glm::vec3 &textColor) { mTextColor = textColor; }

        void SetHint(const std::string &hint) { mHint = hint; }

        virtual void Focus() {
            View::Focus();
            mShowHint = false;
        }

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

        float mCursorPos = 0;
        std::vector<e3::Rect2f> mCharRects;
        std::string mHint = "";
        bool mShowHint = true;
        std::vector<char> mTextVec;
        glm::vec3 mTextColor;
        int cursor = 0;
        bool mTextUpdated = false;

        std::clock_t mAnimationTimerStart;
        float mUnderlineXScale = 0.0f;

        std::mutex mCursorMutex;

        std::clock_t mCursorAnimationTimerStart;
        bool mShowCursor = false;
    };
}

#endif // __GLEDITTEXT__
