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
		std::vector<std::shared_ptr<Image>> Images;
	};
}

#endif // __E3_BACKGROUND__