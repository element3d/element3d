#ifndef __CARBON_EXPAND_VIEW__
#define __CARBON_EXPAND_VIEW__

#include "LinearLayout.h"
#include "TextView.h"
#include "Template.h"

namespace e3
{
    template <class H, class B>
    class ExpandView : public LinearLayout
    {
    public:
        ExpandView() : LinearLayout()
        {
            setOrientation(EOrientation::Vertical);
            mHeaderTemplate = new H();
            addView(mHeaderTemplate);
            mBodyTemplate = new B();
            addView(mBodyTemplate);
        }

    private:
        H* mHeaderTemplate = nullptr;
        B* mBodyTemplate = nullptr;
    };
}

#endif // __CARBON_EXPAND_VIEW__