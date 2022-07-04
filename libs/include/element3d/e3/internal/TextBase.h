#ifndef __E3_TEXT_BASE__
#define __E3_TEXT_BASE__

#include <e3/Element.h>
#include <e3/Font.h>
#include <e3/GLShaderProgram.h>

namespace ftgl
{
	struct vertex_buffer_t;
	struct texture_atlas_t;
	struct texture_font_t;
	struct font_manager_t;
	struct markup_t;
}

namespace _e3 
{
	class TextBase : public e3::Element
	{
	public:
		TextBase(Element* pParent = nullptr);

	protected:
		void UpdateTextBounds();
		glm::vec4 GetLineBBox(char* text, glm::vec2* pen);
		void GenerateTextLines(const std::string& text, float maxLineWidth, e3::ETextOverflow textOverflow);
		void GenerateLineCharacterRects(const std::string& line, std::vector<e3::Rect2f>& rects);
		void UpdateText();
		e3::TextAlignFlags GetTextAlignFlags();
		glm::vec4 AddText(char *text, glm::vec4 * color, glm::vec2 * pen);
		void InitTextRenderer();
		void InitFont();
		virtual void RenderToTexture() override;
		virtual void _RenderSnapshotOffscreen(e3::Element* pSnapshotElement, e3::Rect2f parentRect) override;
		void _UpdateFont();
	protected:
		std::mutex mTextMutex;
		bool mFontInitializing = false;
		ftgl::vertex_buffer_t* mBuffer;
		//	ftgl::texture_atlas_t* mAtlas;
		//ftgl::markup_t* mMarkup;
		//	ftgl::texture_font_t* font;

		std::shared_ptr<e3::Font> mFont = nullptr;
		std::string mFontPath;
		glm::vec4 mBBox;
		e3::EFontStyle mFontStyle = e3::EFontStyle::Normal;
		std::string mFontFamily;
		bool mFontUpdated = true;

		glm::vec2 mPen;
		float mFontSize = 12.0f;
		//glm::vec4 mBBox;
		bool mElementUpdated = false;
		bool mTextUpdated = false;
		bool mTextReady = false;
		glm::vec4 mColor = glm::vec4(0, 0, 0, 255);
		Carbon::ShaderProgram* mShaderProgram = nullptr;
		Carbon::ShaderProgram* mFinalShaderProgram = nullptr;

		e3::TextAlignFlags mTextAlignFlags;
		e3::EAlignment mTextAlignVer;
		e3::EAlignment mTextAlignHor;
		e3::ETextOverflow mTextOverflow = e3::ETextOverflow::Clip;

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
			std::vector<e3::Rect2f> TextCharRects;
		};

		TextParams* mCurrentTextParams = nullptr;
		//TextParams* mPendingTextParams = nullptr;

		struct
		{
			bool HasFontSize = false;
			e3::Dim FontSize;
		} mDims;
	};
}

#endif // __E3_TEXT_BASE__
