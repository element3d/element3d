#ifndef __CARBON_VIEW_FACTORY__
#define __CARBON_VIEW_FACTORY__


#include "Element.h"
#include "TextSpan.h"
//#include "Rectangle.h"
//#include "Circle.h"
#include "ScrollView.h"
//#include "Button.h"
//#include "TextureView.h"
//#include "Icon.h"
#include "Text.h"
#include "Input.h"
#include "TextArea.h"
//#include "EditText.h"
//#include "../../GLView3D.h"
//#include "CarbonListView.h"
#include "RecyclerView.h"
//#include "TabView.h"
//#include "GridView.h"
//#include "CarbonExpandView.h"
#include "Dropdown.h"

//#include "Checkbox.h"
//#include "ProgressBar.h"
//#include "Slider.h"
//#include "Svg.h"
#include "FontIcon.h"
//#include "Carousel.h"
#include "Element3D.h"

namespace e3
{
	class Text;

    class ViewFactory
    {
    public:
        static e3::Element* CreateShape(EOrientation orientation);
		/*static e3::Rectangle* CreateRectangle(EOrientation orientation);
		static e3::Circle* CreateCircle(EOrientation orientation);*/
        static e3::ScrollView* CreateScrollView();
        //static e3::TextureView* CreateTextureView();
        //static e3::Icon* CreateIcon();
        //static e3::EditText* CreateEditText();
       // static e3::TextView* CreateTextView();
		static e3::Text* CreateText();
		static e3::Input* CreateInput();
		static e3::TextArea* CreateTextArea();
        //static e3::Button* CreateButton();
        //static e3::Checkbox* CreateCheckbox();
        //static e3::ProgressBar* CreateProgressBar();
        //static e3::Slider* CreateSlider();
        static e3::FontIcon* CreateFontIcon();
//        static e3::Svg* CreateSvg();
     //   static e3::Carousel* CreateCarousel();
		static e3::Element3D* CreateElement3D();

        //static GLView3D* CreateModelView3D();

        /*template<class H, class B>
        static e3::ExpandView<H, B>* CreateExpandView()
        {
            return new e3::ExpandView<H, B>();
        }*/

        static Dropdown* CreateDropdown()
        {
            return new e3::Dropdown();
        }

        /*template<class T>
        static e3::ListView<T>* CreateListView()
        {
            e3::ListView<T>* pLV = new e3::ListView<T>();
            return pLV;
        }*/

        template<class T>
        static e3::RecyclerView<T>* CreateRecyclerView()
        {
            e3::RecyclerView<T>* pRV = new e3::RecyclerView<T>();
            return pRV;
        }

//        template<class T>
//        static e3::GridView<T>* CreateGridView()
//        {
//            e3::GridView<T>* pGV = new e3::GridView<T>();
//            return pGV;
//        }

//        static e3::TabView* CreateTabView();
//
//        template<class T>
//        static e3::TabViewItem<T>* CreateTabViewItem()
//        {
//            e3::TabViewItem<T>* pTV = new e3::TabViewItem<T>();
//            return pTV;
//        }

    public:
        static void Init(float screenWidth, float screenHeight);

    private:
        static float mScreenWidth;
        static float mScreenHeight;
    };
}

#endif // __CARBON_VIEW_FACTORY__