#ifndef __CARBON_DROPDOWN_LAYOUT__
#define __CARBON_DROPDOWN_LAYOUT__

#include "Dropdown.h"
#include "Element.h"
// #include "Template.h"
#include "Enum.h"

namespace e3
{
    typedef std::function<void(e3::EDropdownState)> OnDropdownLayoutStateChangeCallback;

    class DropdownLayout : public Element
    {
    public:
		void Render() override;
        DropdownLayout();
        void Expand(OnDropdownLayoutStateChangeCallback onDropdownLayoutStateChangeCallback);
        void Collapse();
        e3::EDropdownState GetDropdownState();
        void SetDropdownState(e3::EDropdownState state);
		Dropdown* GetDropdown();

	public:
		bool OnClick(MouseEvent* pEvent) override;


    private:
        e3::EDropdownState mDropdownState = e3::EDropdownState ::Collabsed;
        OnDropdownLayoutStateChangeCallback mOnDropdownLayoutStateChangeCallback = nullptr;
    };
}


#endif // __CARBON_DROPDOWN_LAYOUT__