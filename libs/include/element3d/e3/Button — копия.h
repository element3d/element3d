#ifndef __GLBUTTON__
#define __GLBUTTON__

#include "TextView.h"
#include <ctime>

namespace Carbon
{
    enum class EButtonState
    {
        Pressed,
        Released
    };
};

namespace e3
{

    class Button : public LinearLayout
    {
    public:
        Button();

    public:
        virtual void draw(/*const glm::mat4 &projection*/) override ;

        virtual void update() override;

        virtual bool onClick(const glm::vec2 &pos) override;

        virtual bool OnPointerUp(const glm::vec2 &pos) override;

    public:
        void setSrcColor(const glm::vec3 &color);
        void setSrcColor(const glm::vec4 &color);

        void setSrcAlign(const e3::EAlignment align) { mSrcAlign = align; }


        void setSrcImagePath(const std::string &filename);

        template<typename T>
        void setSrcImageId(T id) { setSrcImageIdPrivate(static_cast<int>(id)); }

        void SetSrcImageUrl(const std::string &url);

        void SetSrcScale(float srcScale) { mSrcScale = srcScale; }

    private:
        void setSrcImageIdPrivate(int id);

    private:
//    void initQuad();
        void InitRectangle();
//    void initShaders();


    private:
//    GLuint mVAO = 0;
//    ShaderProgram* mShader;
        Texture *mTexture = NULL;
        Texture *mTextureMask = nullptr;
        glm::vec4 mSrcColor;
        e3::EAlignment mSrcAlign = e3::EAlignment::Center;
        float mSrcScale = 1.0f;

        /*struct
        {
            Buffer* vertexBuffer;
            Buffer* indexBuffer;
        } mQuad;*/

        struct {
            Carbon::Buffer *vertexBuffer;
        } mRectangle;

        std::clock_t mClickAnimationTimerStart;
        Carbon::EButtonState mState = Carbon::EButtonState::Released;
        float mBrightness = 1.0f;
    };
}
#endif // __GLBUTTON__
