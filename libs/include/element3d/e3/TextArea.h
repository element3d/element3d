#ifndef __E3_TEXTAREA__
#define __E3_TEXTAREA__

#include "Element.h"
#include <e3/Font.h>
#include <e3/GLBuffer.h>
#include <e3/GLShaderProgram.h>

namespace ftgl
{
	struct vertex_buffer_t;
	struct texture_atlas_t;
	struct texture_font_t;
	struct font_manager_t;
	struct markup_t;
}

namespace e3 
{
	class TextArea : public Element
	{
	public:
		TextArea(Element* pParent = nullptr);

	public:
		virtual void Render() override;
		virtual void Update() override;

	public:
	//	void SetHeight(float height) override;
		void SetText(const std::string& text);
		void SetFontSize(float fontSize);
		float GetFontSize();

		void SetMaxNumLines(int maxNumLines);
		int GetMaxNumLines();

	public:
		void OnKey(e3::EKey key, char c);
		void OnKey(e3::EKey key, int mods, unsigned short c);

		bool OnClick(MouseEvent* pEvent) override;
		bool OnMouseLongDown(MouseEvent* pEvent) override;

	public:
		virtual void Focus() override;
		virtual void Unfocus() override;

	private:
		void GenerateTextLines(const std::wstring& text);
		void _UpdateTextLines();
		void GenerateSubLines(const std::wstring& line);
		void GenerateLineCharacterRects(const std::wstring& line, std::vector<e3::Rect2f>& rects);
		void CreateTextBuffer();
		void UpdateCursorPosition();
		std::vector<std::wstring>& GetLinesRef();
		glm::vec4 GetLineBBox(wchar_t* text, int size, glm::vec2* pen);
		glm::vec4 AddText(wchar_t *text, glm::vec4 * color, glm::vec2 * pen);
		void RenderCursor();
		int GetCursorFromClick(glm::vec2 pos);
		struct LineSelectionInfo 
		{
			int LineIndex;
			int StartIndex;
			int EndIndex;
		};
		LineSelectionInfo FindEndOfLineSelection(int lineIndex, int startIndex);
		LineSelectionInfo FindStartOfLineSelection(int lineIndex, int startIndex);
		void SelectionStartMoveUp();
		void SelectionStartMoveDown();
		void SelectionEndMoveUp();
		void SelectionEndMoveDown();
		void UpdateSelectionLeftDropPosition();
		void UpdateSelectionRightDropPosition();
		void _SetText(const std::wstring& text);
	private:
		e3::Element* mScrollView = nullptr;
		Element* mTextLayout = nullptr;
		Element* mTextSelectionBackgroundsParent;
		std::vector<Element*> mTextSelectionBackgrounds;

		std::wstring mText = L"";
		int mMaxNumLines = -1;
		int mLineHeight;
		struct Line 
		{
			int StartIndex;
			int EndIndex;

			int Size() { return EndIndex - StartIndex; }
		};
		std::vector<Line> mLineIndices;
		std::vector<std::wstring> mLines;
		std::vector<glm::ivec4> mLineBBoxes;
		std::vector<std::vector<e3::Rect2f>> mCharRects;


		ftgl::vertex_buffer_t* mBuffer;
		//ftgl::texture_atlas_t* mAtlas;
		ftgl::markup_t* mMarkup;
		std::shared_ptr<e3::Font> mFont = nullptr;
		//ftgl::texture_font_t* font;

		struct
		{
			e3::GLBuffer *vertexBuffer;
			Carbon::ShaderProgram* ShaderProgram = nullptr;
			float LastDiffX;
			float LastDiffY;
		} mCursor;

		glm::vec4 mColor = glm::vec4(0, 0, 0, 255);
		glm::vec4 mCursorColor = glm::vec4(100, 100, 100, 255);

		glm::vec2           pen;
		glm::vec2 mCursorPos = glm::vec2(0);
		int mClickedLine = -1;
		glm::vec2 mClickedPos = glm::vec2(0);

		bool mTextUpdated = false;
		int mInputIndex = 0;
		size_t         cursor = 0;
		bool mShowCursor = false;
		std::clock_t mCursorAnimationTimerStart;
		float mFontSize = 0.0f;

		Carbon::ShaderProgram* mShaderProgram = nullptr;

		bool mHideCursorDropOnScroll = true;

		struct
		{
			std::vector<LineSelectionInfo> mLineSelections;
			int StartLine;
			int EndLine;
			float LastDiffX;
			float LastDiffY;
		} mSelections;
		bool mSelectionEnabled = false;
		bool mFirstFrame = true;
		bool mSimulateScroll = false;
		/*struct
		{
			int StartLine;
			int StartIndex;
			int EndLine;
			int EndIndex;
			float LastDiffX;
			float LastDiffY;
		} mSelection;*/
	};
}

#endif // __E3_TEXTAREA__