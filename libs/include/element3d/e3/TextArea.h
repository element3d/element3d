#ifndef __E3_TEXTAREA__
#define __E3_TEXTAREA__

#include "Element.h"
#include "ScrollView.h"

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
		TextArea();

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
		bool OnClick(MouseEvent* pEvent) override;
		bool OnMouseLongDown(MouseEvent* pEvent) override;

	public:
		virtual void Focus() override;
		virtual void Unfocus() override;

	private:
		void GenerateTextLines(const std::string& text);
		void GenerateSubLines(const std::string& line);
		void GenerateLineCharacterRects(const std::string& line, std::vector<e3::Rect2f>& rects);
		void CreateTextBuffer();
		void UpdateCursorPosition();
		std::vector<std::string>& GetLinesRef();
		glm::vec4 GetLineBBox(char* text, int size, glm::vec2* pen);
		glm::vec4 AddText(char *text, glm::vec4 * color, glm::vec2 * pen);
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
	private:
		ScrollView* mScrollView = nullptr;
		Element* mTextLayout = nullptr;
		Element* mTextSelectionBackgroundsParent;
		std::vector<Element*> mTextSelectionBackgrounds;

		std::string mText = "";
		int mMaxNumLines = 5;
		struct Line 
		{
			int StartIndex;
			int EndIndex;

			int Size() { return EndIndex - StartIndex; }
		};
		std::vector<Line> mLineIndices;
		std::vector<std::string> mLines;
		std::vector<glm::ivec4> mLineBBoxes;
		std::vector<std::vector<e3::Rect2f>> mCharRects;


		ftgl::vertex_buffer_t* mBuffer;
		ftgl::texture_atlas_t* mAtlas;
		ftgl::markup_t* mMarkup;
		ftgl::texture_font_t* font;

		struct
		{
			Carbon::Buffer *vertexBuffer;
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