#ifndef __CARBON_LIST_VIEW__
#define __CARBON_LIST_VIEW__

#include "ScrollView.h"

namespace e3
{
    template <class A>
    class ListView : public e3::ScrollView
    {
    public:
        ListView() : ScrollView()
        {
            SetAlignItemsVer(e3::EAlignment::Start);
            SetAlignItemsHor(e3::EAlignment::Start);
        }

      //  void draw(const glm::mat4& projection) override;
    public:
        void AddItem(A* pItem)
        {
            addView(pItem);
        }
    };
}

#endif // __CARBON_LIST_VIEW__