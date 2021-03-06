#ifndef __E3_STYLE__
#define __E3_STYLE__

#include <e3/Enum.h>
#include <e3/Image.h>
#include <memory>
#include "Background.h"

namespace e3 
{
	struct Padding
	{
		float Left;
		float Right;
		float Top;
		float Bottom;
	};

	struct Margin
	{
		float Left;
		float Right;
		float Top;
		float Bottom;
	};

	struct AbsoluteDistance
	{
		float Left;
		float Right;
		float Top;
		float Bottom;
	};

	struct Style
	{
		float Width;
		float Height;
		float MinWidth;
		float MinHeight;
		float MaxWidth;
		float MaxHeight;
		float Z;
		EShapeType ShapeType;
		float AspectRatio;
		e3::AbsoluteDistance AbsoluteDistance;
		e3::Padding Padding;
		e3::Margin Margin;
		float Opacity;
		EOverflow     Overflow = EOverflow::Visible;
		EScaling      Scaling = EScaling::None;
		EVisibility   Visibility = EVisibility::Visible;
		EPositionType PositionType = EPositionType::Relative;
		bool          Enabled = true;

		e3::Background Background;
		/*glm::vec4     BackgroundColor;
		std::shared_ptr<Image> BackgroundImage;
		glm::vec4  BackgroundImageColor;
		float      BackgroundImageOpacity;
		e3::EBackgroundSize BackgroundSize;
		e3::EBackgroundPosition BackgroundPosition;*/

		float      BorderSize;
		glm::vec4  BorderColor;
		glm::vec4  BorderRadius;

		EOrientation   Orientation;
		bool           Reversed = false;
		e3::EAlignment AlignItemsVer;
		e3::EAlignment AlignItemsHor;

		Style();
	};
}

#endif // __E3_STYLE__