#ifndef __E3_TEXT__
#define __E3_TEXT__

#include "Element.h"
#include "Font.h"
#include <memory>
#include <e3/i18n.h>

namespace ftgl
{
	struct vertex_buffer_t;
	struct texture_atlas_t;
	struct texture_font_t;
	struct font_manager_t;
	struct markup_t;
}

namespace Carbon 
{
	class ShaderProgram;
}

namespace e3 
{
	class Text : public Element
	{
	public:
		Text();
		~Text() {}

	public:
		virtual void Render() override;
		virtual void Build() override;
		virtual void RenderToTexture() override;
		virtual void Update() override;

	public:
		virtual void SetWidth(const Dim& width) override;
		virtual void SetHeight(const Dim& height) override;
		void SetText(const std::string& text);
		void SetText(const std::string& text, bool translate);
		std::string GetText();
		void SetFontSize(const Dim& fontSize);
		void SetFontFamily(const std::string& fontFamily);
		void SetFontStyle(EFontStyle fontStyle);
		void SetTextColor(const glm::vec4& color);

		// virtual void SetScale(const glm::vec3 &direction) override;

		void SetTextAlignVer(e3::EAlignment alignment);
		e3::EAlignment GetTextAlignVer();

		void SetTextAlignHor(e3::EAlignment alignment);
		e3::EAlignment GetTextAlignHor();

		void SetMaxNumLines(int maxNumLines);
		int GetMaxNumLines();

		void SetTextOverflow(ETextOverflow textOverflow);
	private:
		void InitFont();
		void UpdateTextBounds();
		void UpdateText();
		void InitTextRenderer();
		glm::vec4 GetLineBBox(char* text, glm::vec2* pen);
		glm::vec4 AddText(char *text, glm::vec4 * color, glm::vec2 * pen);
		e3::TextAlignFlags GetTextAlignFlags();
		void GenerateTextLines(const std::string& text, float maxLineWidth, ETextOverflow textOverflow);
		void GenerateLineCharacterRects(const std::string& line, std::vector<e3::Rect2f>& rects);
		void GenerateLineCharacterRects(int start, int size, std::vector<e3::Rect2f>& rects);

	private:
		std::mutex mTextMutex;
		bool mFontInitializing = false;
		ftgl::vertex_buffer_t* mBuffer;
	//	ftgl::texture_atlas_t* mAtlas;
		//ftgl::markup_t* mMarkup;
	//	ftgl::texture_font_t* font;

		std::shared_ptr<Font> mFont = nullptr;
		glm::vec4 mBBox;
		EFontStyle mFontStyle = EFontStyle::Normal;
		std::string mFontFamily;
		bool mFontUpdated = true;

		glm::vec2 mPen;
		float mFontSize = 0.0f;
		//glm::vec4 mBBox;
		bool mElementUpdated = false;
		bool mTextUpdated = false;
		bool mTextReady = false;
		glm::vec4 mColor = glm::vec4(0, 0, 0, 255);
		Carbon::ShaderProgram* mShaderProgram = nullptr;

		e3::TextAlignFlags mTextAlignFlags;
		e3::EAlignment mTextAlignVer;
		e3::EAlignment mTextAlignHor;
		ETextOverflow mTextOverflow = ETextOverflow::Clip;

		// std::string mText = "";
		bool mTranslate = false;
		int mMaxNumLines = 1;
		// std::vector<std::string> mLines;
		// std::vector<glm::ivec4> mLineBBoxes;
		// std::vector<Rect2f> mTextCharRects;

		bool mInternalBoundUpdate = false;

		int mI18Id = -1;

		struct TextParams
		{
			std::string Text;
			std::vector<std::string> Lines;
			std::vector<glm::ivec4>  LineBBoxes;
			std::vector<Rect2f> TextCharRects;
		};

		TextParams* mCurrentTextParams = nullptr;
		TextParams* mPendingTextParams = nullptr;

		struct 
		{
			bool HasFontSize = false;
			Dim FontSize;
		} mDims;
	};
}

#endif // __E3_TEXT__
