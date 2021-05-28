#ifndef __CARBON_VIEW_FACTORY__
#define __CARBON_VIEW_FACTORY__


#include "Element.h"
#include "Arc.h"
#include "TextSpan.h"
#include "ScrollView.h"
#include "Text.h"
#include "Input.h"
#include "TextArea.h"
#include "Dropdown.h"
#include "FontIcon.h"
//#include "Element3D.h"

namespace e3
{
	class Text;

    class ViewFactory
    {
    public:
        static e3::Element* CreateShape(EOrientation orientation);
        static e3::ScrollView* CreateScrollView();
		static e3::Text* CreateText();
		static e3::Input* CreateInput();
		static e3::TextArea* CreateTextArea();
        static e3::FontIcon* CreateFontIcon();
		//static e3::Element3D* CreateElement3D();
		static Dropdown* CreateDropdown();
    };
}

#endif // __CARBON_VIEW_FACTORY__