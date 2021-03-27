#ifndef __CARBON_TAB_VIEW__
#define __CARBON_TAB_VIEW__

#include "LinearLayout.h"
#include "TabViewItem.h"
#include <functional>
#include "Activity.h"

namespace e3
{
    typedef std::function<void(int, View*)> OnTabViewItemClickCallback;

    class TabView: public LinearLayout
    {
    public:
        TabView();

    public:
        template <class T>
        void AddItem(TabViewItem<T>* pItem)
        {
            int index = mHeader->NumChildren();
            bool first = !mHeader->NumChildren();
            pItem->setHeight(1);
            mHeader->addView(pItem);

            pItem->setOnClickCallback([this, index, pItem](){
                if(this->mOnTabViewItemClickCallback) this->mOnTabViewItemClickCallback(index, pItem);

                Activity* pActivity = GetActivity();
                if (!pActivity)
                    return;

                pActivity->RunOnUiThread([this, pItem](){
                    ALOGE("RUN ON UI THRAD\n");
                    mBody->PopView();
                    mBody->addView(pItem->Template());
                });

            });

            for (int i = 0; i < mHeader->NumChildren(); ++i)
            {
                LinearLayout* pLayout = (LinearLayout*)mHeader->Children()[i];
                pLayout->setWidth(1.0f / mHeader->NumChildren());
            }

            if (first)
            {
                Activity* pActivity = GetActivity();
                if (!pActivity)
                    return;

                pActivity->RunOnUiThread([this, pItem](){
                    ALOGE("RUN ON UI THRAD\n");
                    mBody->addView(pItem->Template());
                    mHeader->Children()[0]->Focus();
                });

            }
        }
        bool onClick(const glm::vec2& pos) override;
        void SetOnItemClickCallback(OnTabViewItemClickCallback callback)
        {
            mOnTabViewItemClickCallback = callback;
        }

    private:
        LinearLayout* mHeader = nullptr;
        LinearLayout* mBody = nullptr;
        OnTabViewItemClickCallback mOnTabViewItemClickCallback = nullptr;
        int mSelectedTabIndex = 0;
    };
}

#endif // __CARBON_TAB_VIEW__