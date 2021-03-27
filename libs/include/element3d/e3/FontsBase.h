#ifndef __E3_FONTS_BASE__
#define __E3_FONTS_BASE__

#include <string>
#include <memory>
#include <e3/Font.h>

namespace e3 
{
	class FontsBase 
	{
	public:
		FontsBase() {}

	public:
		std::shared_ptr<Font> FindFont(FontParams* pParams);

	protected:
		std::map<std::string, std::vector<FontParams>> mFonts;
		std::map<std::string, Font*> mLoadedFonts;
	};
}

#endif // __E3_FONTS_BASE__