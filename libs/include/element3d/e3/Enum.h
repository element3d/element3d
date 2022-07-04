#ifndef __E3_ENUM__
#define __E3_ENUM__

#include "CarbonKeys.h"

namespace e3
{
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

	enum class ERenderer
	{
		Element3D,
		NanoVG
	};

	enum class EElementType
	{
		Unknown = -1,
		Element,
		Input,
		TextArea,
		Text,
		ScrollView,
		Dropdown,
		DropdownLayout,
		FontIcon
	};


	enum class EElementState
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

	enum class EElementHoverState
	{
		Initial,
		MouseEnter,
		MouseHover,
		MouseLeave
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

	enum class ETransformAlignment
	{
		Center,
		Left,
		Right,
		Top,
		Bottom,
		TopLeft,
		TopRight,
		BottomRight,
		BottomLeft
	};

	enum class ETextAlignFlag 
	{
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

	enum class EBackgroundType 
	{
		Color,
		Image,
		LinearGradient,
		RadialGradient
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
		Dp,
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

	enum class EShapeType
	{
		Unknown,
		Circle,
		Rectangle,
		Hexagon,
		Triangle,
		Arc,
		Star,
		Custom,
	};

	enum class EBorderType 
	{
		Circular,
		Cut
	};
}
/*
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
*/


#endif // __E3_ENUM__
