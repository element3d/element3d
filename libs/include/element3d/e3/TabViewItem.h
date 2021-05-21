#ifndef __CARBON_TAB_VIEW_ITEM__
#define __CARBON_TAB_VIEW_ITEM__

#include "Template.h"
#include "LinearLayout.h"
#include "TextView.h"

namespace e3
{
    template<class T>
    class TabViewItem : public LinearLayout
    {
    public:
        TabViewItem() : LinearLayout()
        {
            mType = EViewType::TabViewItem;
            mTemplate = new T();

            mTitleTextView = new e3::TextView();
            addView(mTitleTextView);
        }

    public:
        void SetTitle(const std::string& title)
        {
            mTitleTextView->SetText(title);
            mTitleTextView->setTextColor(glm::vec3(255, 255, 255));
            mTitleTextView->setFontSize(30);
            mTitleTextView->SetTextAlignHor(EAlignment::Center);
        }

        T* Template()
        {
            return mTemplate;
        }

        bool onClick(const glm::vec2& pos) override
        {
//            if(mOnClickCallback) mOnClickCallback();
            return  View::onClick(pos);
        }

    private:
        e3::TextView* mTitleTextView = nullptr;
        T* mTemplate = nullptr;
    };
}

#endif // __CARBON_TAB_VIEW_ITEM__