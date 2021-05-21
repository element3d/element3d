#ifndef __E3_CAROUSEL__
#define __E3_CAROUSEL__

#include <e3/Types.h>
#include <e3/ScrollView.h>
#include <e3/Template.h>
#include <e3/Animation.h>

namespace e3
{
    class Carousel : public Shape
    {
    public:
        Carousel();

    public:
        void Update() override;

        virtual void OnMove(const glm::vec2 &distance, const glm::vec2 &pos) override;
        virtual bool OnPointerUp(const glm::vec2 &pos) override;

        void Render() override
        {
           Shape::Render();

           e3::Rect2f r = mRealLayout->GetGeometry();
           ALOGE("");
        }

    public:
        void AddItem(e3::Template* pTemplate)
        {
            int* pIndex = new int(mRealLayout->GetNumChildren());
            pTemplate->SetUsrPtr(pIndex);
            mRealLayout->AddElement(pTemplate);
        }

        void SetLoop(bool loop) { mLoop = loop; }
    private:


    private:
        int mCurrentItemIndex = 0;
        e3::Element* mCurrentItem = nullptr;
        Container* mRealLayout = nullptr;
        Container* mCarouselLayout = nullptr;
        Container* mIndicatorLayout = nullptr;
        bool mCarouselLayoutUpdated = false;
        Animation* mSwipeAnimation = nullptr;
        bool mLoop = true;

    };
}

#endif // __E3_CAROUSEL__