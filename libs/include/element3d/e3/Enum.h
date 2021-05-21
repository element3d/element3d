#ifndef __ENUM__
#define __ENUM__

#ifndef __CARBON_MAKE__
#include <Carbon.h>
#include "CarbonKeys.h"
#endif

enum EActivityState
{
	Initial,
	OnCreate,
	OnResume,
	OnRender,
	OnStop,
	OnDestroy,
};

enum class EViewState
{
	Initial,
	Enabled,
	Disabled,
    Visible,
    Sliding,
    Scrolling,
    Hidden,
    Appearing,
    Disappearing,
    MouseDown,
    MouseUp,
    MouseMove,
	MouseEnter,
	MouseHover,
	MouseLeave,
    Clicked,
};

enum class EVisibility
{
	Visible,
	Gone,
	Hidden
};

enum class EOrientation
{
    Horizontal,
    Vertical
};


enum class EGravity
{
    Start,
    Center,
    End
};
#ifndef __CARBON_MAKE__
namespace e3
{
#endif
	struct Enum
	{
	public:
		Enum();
		explicit Enum(const int& x);
		const Enum& operator= (const int& x) const;
		operator int() const;

	protected:
		int Value;

	protected:
		static int sCount;
	};

	enum class EE3OS 
	{
		Android,
		IOS,
		Windows,
		Linux,
		MacOS,
		Web
	};

	enum class EE3Target 
	{
		Mobile,
		Desktop,
		MobileSimulator,
		Web
	};

	enum class EDisplaySize 
	{
		Small,
		Medium,
		Large
	};

	enum class ECursor 
	{
		Arrow,
		IBeam,
		Crosshair,
		Hand,
		HResize,
		VResize
	};

	enum class EAlignment 
	{
		Start,
		End,
		Center,
		SpaceBetween,
		SpaceAround
	};

	enum class ETextAlignFlag {
		StartHorizontal = 1,
		CenterHorizontal = 2,
		EndHorizontal = 4,
		StartVertical = 8,
		CenterVertical = 16,
		EndVertical = 32,
	};
	typedef unsigned int TextAlignFlags;

	enum class EOverflow
	{
		Hidden,
		Visible,
		Scroll,
	};

	enum class ETextOverflow
	{
		None,
		Clip,
		Ellipsis,
	};

	enum class EScaling 
	{
		None,
		Shrink,
		Grow
	};

	enum class EBackgroundSize 
	{
		Contain,
		Cover,
		ScaleToFit
	};

	enum class EBackgroundPosition
	{
		Start,
		Center,
		End
	};

	enum class EFXType
	{
		Shadow
	};

	enum class EPositionType
	{
		Relative,
		Absolute
	};

	enum class EDropdownState
	{
		Expanded,
		Collabsed
	};

	enum class EUnit
	{
		Pixel,
		Point,
		Percent,
	};

	enum class EWrap 
	{
		NoWrap,
		Wrap,
		WrapReverse
	};

	enum class EFontStyle
	{
		Normal = 0,
		Italic = (1 << 0),
		Bold = (1 << 1)
	};
#ifndef __CARBON_MAKE__
}
#endif


enum class EViewType
{
    Unknown = -1,
	Activity,
	AppBar,
	Drawer,
	NavigationMenu,
	NavigationMenuHeader,
	NavigationMenuItemGroup,
	NavigationMenuItem,
	TabNavigationMenu,
	TabNavigationMenuItem,
	Adapter,
    LinearLayout,
    ShapeView,
    TextureView,
	Icon,
    EditText,
	TextArea,
    Text,
    Button,
	ListView,
	RecyclerView,
	ScrollView,
	TabView,
	TabViewItem,
	GridView,
	ExpandView,
	Dropdown,
	DropdownHeader,
	DropdownLayout,
	ProgressBar,
	Slider,
	FontIcon,
	Checkbox,
    ModelView3D,
    Materials,
    DiffuseMap,
	CustomView
};

enum class EViewParamType
{
    Unknown = -1,

    ID,
	AppBar,
	Drawer,
	Base,
    Orientation,
    Width,
	MinWidth,
	MaxWidth,
    Height,
	MinHeight,
	MaxHeight,
	AlignItemsVer,
	AlignItemsHor,
	MarginTop,
	MarginBottom,
	MarginLeft,
	MarginRight,
    GravityHor,
    GravityVer,
    Text,
	TextArea,
	Hint,
    TextColor,
	TextAlignVer,
	TextAlignHor,
    FontSize,
    Src,
	SrcColor,
	SrcAlign,
	SrcScale,
    Scale,
    Rotate,
    Translate,
	ItemHeight,
	ItemWidth,
	Title,
	TitleFontSize,
	Icon,
	IconColor,
	TitleColor,
	BackgroundColor,
	BackgroundColorFocused,
	BackgroundImage,
	BackgroundImageOpacity,
	BackgroundSize,
	BackgroundPosition,
	BorderSize,
	BorderColor,
	BorderRadius,
	ShapeType,
	BorderType,
	NumColumns,
	RowHeight,
	Template,
	Scaling,
	HeaderTemplate,
	BodyTemplate,
	Value,
	ValueColor,
	AspectRatio,
	PositionType,
	Top,
	Bottom, 
	Left,
	Right,
	Visibility,
	Opacity,
};

enum class EMaterialType
{
    Unknown,
    DiffuseMap
};

enum class EMaterialParamType
{
    Unknown,
    MeshName,
    Src
};

#ifndef __CARBON_MAKE__

enum class EAttachment
{
    ColorAttachment0 = GL_COLOR_ATTACHMENT0,
    DepthAttachment = GL_DEPTH_ATTACHMENT,
};

#endif

enum class EShapeType
{
    Unknown,
    Circle,
    Rectangle,
    Hexagon,
	Triangle,
    Custom,
};

enum class EBorderType
{
    Unknown,
    Circle,
    Rectangle,
    Hexagon,
};

#endif
