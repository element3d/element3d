#ifndef  __CARBON_DRAWER__
#define  __CARBON_DRAWER__

#include "Shape.h"
#include <glm/gtc/matrix_transform.hpp>

namespace e3
{
    class Drawer : public Shape
    {
    public:
        Drawer() : Shape()
        {
            SetOrientation(EOrientation::Vertical);
            /*SetScaling(EScaling::Grow);
            setWidth(1);
            setHeight(1);*/
            mAnimationTimer = std::chrono::high_resolution_clock::now();
            mState = EViewState::Hidden;
        }

        void Show()
        {
            mState = EViewState::Appearing;
        }

        EViewState State() { return mState; }
        void SetState(EViewState state) {
            mState = state;
            if (mState == EViewState::Visible)
            {
                mPositionX = 0.0f;
            }
            if (mState ==EViewState::Hidden) {
                mPositionX = -mRect.width;
            }
        }
        void Hide() { mState = EViewState ::Disappearing; }

        virtual void Update() override
        {
            Shape::Update();
            if (mFirstFrame && mRect.width != 0.0f)
            {
                mPositionX = -mRect.width;
                mFirstFrame = false;
            }
        }

        void Render() override
        {
            glm::mat4 translate = glm::mat4(1);
            switch (mState)
            {
                case EViewState::Appearing:
                {
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<float> duration = end - mAnimationTimer;
                    float ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
                    if (ms > 10)
                    {
                        ALOGE("ANIMATION: %f", mPositionX);
                        mPositionX += mRect.width / 15.0f;
                        ALOGE("ANIMATION: %f", mPositionX);
                        if (mPositionX >= 0.0f)
                        {
                            mPositionX = 0.0f;
                            mState = EViewState ::Visible;
                            Render();
                            return;
                        }
                        mAnimationTimer = end;
                    }
                    translate = glm::translate(glm::mat4(1),
                                               glm::vec3(std::min(mPositionX, 0.0f), 0.0f, 0.0f));
                    /*mMainLayout->*/Shape::Render(/*translate*/);
                    break;
                }
                case EViewState::Sliding:
                {
                    translate = glm::translate(glm::mat4(1),
                                               glm::vec3(std::min(mPositionX, 0.0f), 0.0f, 0.0f));
                    /*mMainLayout->*/Shape::Render(/*translate*/);
                    break;
                }
                case EViewState::Visible:
                {
                    /*mMainLayout->*/Shape::Render();
                    break;
                }
                case EViewState::Disappearing:
                {
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<float> duration = end - mAnimationTimer;
                    float ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
                    if (ms > 10)
                    {
                        mPositionX -= mRect.width / 15.0f;
                        if (mPositionX <= -mRect.width)
                        {
                            mState = EViewState ::Hidden;
                            mPositionX = -mRect.width;
                            Render();
                            return;
                        }
                        mAnimationTimer = end;
                    }
                    translate = glm::translate(glm::mat4(1),
                                               glm::vec3(std::min(mPositionX, 0.0f), 0.0f, 0.0f));
                    /*mMainLayout->*/Shape::Render(/* translate*/);
                    break;

                }
                case EViewState::Hidden:
                {
                    break;
                }
                default:
                    break;
            }
        }

        void onMove(const glm::vec2 &distance, const glm::vec2& pos)
        {
            ALOGE("Drawer on move*****************");
            mState = EViewState::Sliding;
            float px = mPositionX - distance.x;
            if (px >= 0.0)
            {
                mPositionX = 0.0f;
                mState = EViewState::Visible;
                return;
            }
            if (px <= -mRect.width)
            {
                mState = EViewState::Hidden;
                mPositionX = -mRect.width;
                return;
            }
            mPositionX = px;
        }

        bool OnMouseUp(const glm::vec2 &pos)
        {
            if (mState != EViewState::Sliding) return true;
            if (mPositionX >= -0.5f * mRect.width)
            {
                mState = EViewState ::Appearing;
                return true;
            }
            if (mPositionX < -0.5f * mRect.width)
            {
                mState = EViewState ::Disappearing;
                return true;
            }

            return true;
        }

    private:
        EViewState mState = EViewState::Hidden;
        std::chrono::high_resolution_clock::time_point mAnimationTimer;
        float mPositionX;
        bool mFirstFrame = true;
    };
}

#endif // __CARBON_DRAWER__