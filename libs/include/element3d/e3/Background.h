#ifndef __E3_BACKGROUND__
#define __E3_BACKGROUND__

#include "Enum.h"
#include "Image.h"

namespace e3
{
	struct Background
	{
		EBackgroundSize Size;
		EBackgroundPosition Position;
		glm::vec4 Color;
		glm::vec4 ImageColor;
		float ImageOpacity;
        std::shared_ptr<e3::Image> Image;
	};
}

#endif // __E3_BACKGROUND__
