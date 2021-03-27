#ifndef __GLEDITTEXT__
#define __GLEDITTEXT__

#include "e3ShapeView.h"
#include "e3ShapeView.h"
#include <time.h>
#include <mutex>

namespace e3
{
    class EditText : public e3::ShapeView {
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
        virtual void onMove(const glm::vec2 &distance, const glm::vec2& pos) override;

        void onKey(e3::EKey key, char c);

        virtual void Unfocus() override {
            View::Unfocus();
            if (!mTextVec.size()) mShowHint = true;
        }

        void setTextColor(const glm::vec3 &textColor) { mTextColor = textColor; }

        void setTextColor(const glm::vec4 &textColor) { mTextColor = glm::vec3(textColor); }

        void SetHint(const std::string &hint) { mHint = hint; }

        virtual void Focus() {
            View::Focus();
            mShowHint = false;
        }

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

        float mCursorPos = 0;
        std::vector<cv::Rect2f> mCharRects;
        std::string mHint = "";
        bool mShowHint = true;
        std::vector<char> mTextVec;
        glm::vec3 mTextColor;
        int cursor = 0;
        bool mTextUpdated = false;

        std::clock_t mAnimationTimerStart;

        std::mutex mCursorMutex;

        std::clock_t mCursorAnimationTimerStart;
        bool mShowCursor = false;

        float mTextScroll = 0.0f;
        float mFirstCharPosition = -1.0f;
    };
}

#endif // __GLEDITTEXT__
