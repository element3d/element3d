#ifndef __E3_FONT__
#define __E3_FONT__

#include <string>
#include <e3/Enum.h>
#include <vector>

namespace ftgl
{
	struct vertex_buffer_t;
	struct texture_atlas_t;
	struct texture_glyph_t;
	struct texture_font_t;
	struct font_manager_t;
	struct markup_t;
}

namespace e3 
{
	struct FontParams
	{
		int FontSize = 12;
		std::string Path;
		std::string Family;
		EFontStyle  Style;

	};

	struct FontTextureAtlas
	{
		unsigned int TextureHandle;
		int Width;
		int Height;
		int Depth;
		void* Data;
	};

	class Font 
	{
	public:
		Font();
		~Font();

	public:
		ftgl::texture_font_t* GetFtglFont() { return mFont; }
		bool Load(int fontSize, const std::string& path);
		ftgl::texture_glyph_t* GetGlyph(const wchar_t* codepoint);
		FontTextureAtlas GetTextureAtlas();

	private:
		void InitParams();

	private:
		int mFontSize = 0;
		std::string mPath;
		int mFontStyleFlags = 0;
		std::string mFontFamily;

		ftgl::texture_atlas_t* mAtlas;
		ftgl::markup_t* mMarkup;
		ftgl::texture_font_t* mFont = nullptr;
	};
}

#endif // __E3_FONT__