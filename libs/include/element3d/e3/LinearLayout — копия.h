#ifndef __GLLINEARLAYOUT__
#define __GLLINEARLAYOUT__

#include "View.h"
#include <vector>
#include <mutex>
#include "ShapeRenderer.h"
#include "Animation.h"

namespace e3
{

    enum class EScrollState
    {
        None,
        Started,
        Scrolling,
        ScrollingOutOfRange,
        StoppedOutofRange,
        Ended,
    };

    enum class EScrollDirection
    {
        None,
        Up,
        Down
    };

    class LinearLayout : public e3::View
    {
    public:
        LinearLayout();

        virtual ~LinearLayout();

        virtual void draw() override;

        virtual void DrawShadow() override;

        virtual void DrawBloom() override;

        virtual void addView(View *pView);

        virtual void insertView(int index, View *pView);

        virtual void insertViewBefore(int id, View *pView);

        void RemoveViewById(int id);

        void PopView() {
//        std::lock_guard<std::recursive_mutex> lock(mRenderMutex);
            if (!mChilds.size())
                return;
            YGNodeRemoveChild(mNode, mChilds[mChilds.size() - 1]->Node());
            mChilds.pop_back();
        }

        void SetAlignItemsVer(e3::EAlignment alignment);

        void SetAlignItemsHor(e3::EAlignment alignment);

        void setOrientation(EOrientation orientation);

        EOrientation orientation() { return mOrientation; }


        virtual float GetMaxZ() override;

        void update();

        View *FindViewById(int id);

        void Translate(const glm::vec3 &direction) override {
            View::Translate(direction);

            for (auto pView : mChilds) {
                pView->Translate(direction);
            }
        }

        void Scale(const glm::vec3 &direction) override {
            View::Scale(direction);

            for (auto pView : mChilds) {
                pView->Scale(direction);
            }
        }

        virtual void SetScale(const glm::vec3 &direction) {
            View::SetScale(direction);
            for (auto pView : mChilds) {
                pView->SetScale(direction);
            }
        }

        void SetTranslation(const glm::vec3 &direction) override {
            View::SetTranslation(direction);

            for (auto pView : mChilds) {
                pView->SetTranslation(direction);
            }
        }

        void setOpacity(float opacity) override {
            View::setOpacity(opacity);
            for (auto pView : mChilds)
                pView->setOpacity(opacity);
        }

    public:
        bool onClick(const glm::vec2 &pos) override;

        virtual bool OnPointerUp(const glm::vec2 &pos) override;

        virtual void onMove(const glm::vec2 &distance, const glm::vec2 &pos) override;

        /*virtual void SetScrollTransform(const glm::mat4& transform) override {
            View::SetScrollTransform(transform);
            for (auto v : mChilds) v->SetScrollTransform(transform);
        }*/
        virtual void SetScrollDirection(float value, EOrientation orientation) override {
            View::SetScrollDirection(value, orientation);
            for (auto v : mChilds) v->SetScrollDirection(value, orientation);
        }

        virtual void OnScroll(const glm::vec2 &distance) {}

        int NumChildren() { return mChilds.size(); }

        View **Children() { return mChilds.data(); }

        void RemoveAllViews() {
            while (NumChildren()) { PopView(); }
        }

    private:
        void DoScrollUp(float dy);

        void DoScrollDown(float dy);

        int FindViewIndexById(int id);

        float getMaxZ(float maxZ, View *pView);

    private:
        std::vector<View *> mChilds;
        EOrientation mOrientation;

        Carbon::Animation *mBackScrollAnimation = nullptr;
        bool mEnableScroll = false;
        e3::ShapeRenderParams *mBackgroundShapeRenderParam = nullptr;

        //  glm::mat4 mScrollTransform = glm::mat4(1);

        e3::EAlignment mAlignItemsVer = e3::EAlignment::Center;
        e3::EAlignment mAlignItemsHor = e3::EAlignment::Center;

        float mOutOfRangleScroll = 0.f;
        EScrollState mScrollState = EScrollState::None;
        Carbon::Animation *mOutOfRangeBackScrollAnimation = nullptr;
        float mOutOfRangeBackScrollValue = 0.0f;
        EScrollDirection mScrollDirection = EScrollDirection::None;
//    std::recursive_mutex mRenderMutex;
    };
}

#endif // __GLLINEARLAYOUT__
