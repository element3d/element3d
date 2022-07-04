#ifndef __E3_TEXT_HOLDER__
#define __E3_TEXT_HOLDER__

#include <vector>
#include <string>
#include <glm.hpp>
#include <e3/Types.h>
#include <e3/Enum.h>

namespace ftgl
{
    struct vertex_buffer_t;
    struct texture_atlas_t;
    struct texture_font_t;
	struct font_manager_t;
}

namespace e3
{
    class TextHolder
    {
    public:
        TextHolder();

    public:
        int FontSize() { return mFontSize; }
        virtual void setFontSize(int fontSize);

        void setTextColor(const glm::vec3 &color);
        void setTextColor(const glm::vec4 &color);
        glm::vec4 TextColor() { return mColor; }

        ftgl::vertex_buffer_t* GetFtGlBuffer() { return buffer; }
		ftgl::texture_atlas_t* GetFtGlTextureAtlas();

        void SetFont(int id);
        ftgl::texture_font_t* GetFont() { return font; }

        virtual void SetMaxNumLines(int numMaxLines);
        int GetMaxNumLines() { return mMaxNumLines; }
    protected:
        void AddLine(const std::string& line) { mLines.push_back(line); }
        float AddGlyph(char* current, char* previous, glm::vec2& pen);
        static float AddGlyph(ftgl::vertex_buffer_t* pBuffer, char* current, char* previous, glm::vec2& pen, ftgl::texture_font_t* pFont, int fontSize, float& fontBottomOffset);
        void GenerateRects(const std::string& line, std::vector<e3::Rect2f>& rects);
        void GenerateTextLines(const std::string& text, float maxLineWidth, ETextOverflow textOverflow);
        float GetLineWidth(const std::string& line);

        const std::vector<std::string>& GetLines() { return mLines; }
        std::vector<std::string>& GetLinesRef() { return mLines; }
        std::vector<float>& GetLineWidths() { return mLinesWidths; }
        float GetFontBottomOffset() { return mFontBottomOffset; }

        void ClearLines();
    protected:
        std::vector<std::string> mLines;
        std::vector<float> mLinesWidths;
        ftgl::vertex_buffer_t * buffer;
        ftgl::texture_atlas_t *atlas;
		ftgl::font_manager_t * font_manager_rgb;
//        glm::vec2           pen;
        int mFontSize = 0;
        glm::vec4 mColor;
        float mFontBottomOffset = 0.0f;
        ftgl::texture_font_t * font = nullptr;
        int mMaxNumLines = 1;
    };
}

#endif // __E3_TEXT_HOLDER__