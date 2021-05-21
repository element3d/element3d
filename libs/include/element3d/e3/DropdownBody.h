#ifndef __E3_DROPDOWN_BODY__
#define __E3_DROPDOWN_BODY__

#include "Element.h"
//#include "Dropdown.h"

namespace e3 
{
	class Dropdown;
	class DropdownBody : public Element
	{
	public:
		DropdownBody();

		Dropdown* GetDropdown();

	private:
		friend class Dropdown;
		Dropdown* mDropdown = nullptr;
	};
}

#endif // __E3_DROPDOWN_BODY__