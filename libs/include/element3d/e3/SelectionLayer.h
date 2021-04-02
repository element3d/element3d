#ifndef __E3_SELECTION_LAYER__
#define __E3_SELECTION_LAYER__

#include <e3/Element.h>


namespace e3 
{
	class Input;

	class SelectionLayer : public Element
	{
		typedef std::function<void(float x, float y, float dx, float dy)> OnLeftValueChange;
		typedef std::function<void(float x, float y, float dx, float dy)> OnRightValueChange;
		typedef std::function<void(float x, float y, float dx, float dy)> OnCursorChangeCallback;
		typedef std::function<void(void)> OnClearSelectionCallback;
		typedef std::function<void(void)> OnCutSelectionCallback;
		typedef std::function<void(void)> OnCopySelectionCallback;
		typedef std::function<void(void)> OnPasteSelectionCallback;
		typedef std::function<void(void)> OnPasteCallback;
		typedef std::function<void(void)> OnCancelCallback;
		typedef std::function<void(void)> OnSelectAllCallback;
	public:
		SelectionLayer();
		void Render() override;
	public:
		bool OnMouseDown(MouseEvent* pEvent) override;
		bool OnMouseLongDown(MouseEvent* pEvent) override;
		bool OnClick(MouseEvent* pEvent) override;
		void OnMouseMove(MouseEvent* pEvent) override;
		void OnCursorDropClick();
		void SetInputRect(const e3::Rect2f& inputRect) { mInputRect = inputRect; }
		void SetTextAreaRect(const e3::Rect2f& textAreaRect) { mTextAreaRect = textAreaRect; }
		void SetCursorColor(const glm::vec4& color);
		bool GetEnabled() { return mCopyEnabled || mPasteEnabled; }
		bool GetCursorEnabled() { return mCursorEnabled; }
		void EnableTextAreaSelection
		(
			const glm::vec2& startPosition,
			const glm::vec2& endPosition,
			const glm::vec2& copyBoardPosition,
			OnLeftValueChange onLeftValueChange,
			OnRightValueChange onRightValueChange,
			OnClearSelectionCallback onClearSelectionCallback,
			OnCutSelectionCallback onCutSelectionCallback,
			OnCopySelectionCallback onCopySelectionCallback
		);
		void EnableSelection
		(
			Input* pInput,
			//const e3::Rect2f& inputRect,
			const e3::Rect2f& selectionRect,
			OnLeftValueChange onLeftValueChange,
			OnRightValueChange onRightValueChange,
			OnClearSelectionCallback onClearSelectionCallback,
			OnCutSelectionCallback onCutSelectionCallback,
			OnCopySelectionCallback onCopySelectionCallback,
			OnPasteSelectionCallback onPasteSelectionCallback
		);
		void SetCursorPosition(const glm::vec2& position);
		void SetCursorPositionTextArea(const glm::vec2& position);

		void ShowCursorDrop(const glm::vec2& position, const Rect2f& cursorAreaRect, OnCursorChangeCallback onCursorChangeCallback);
		void HideCursorDrop();
		void TranslateLeftDrop(const glm::vec2& d);
		void TranslateRightDrop(float x);
		void TranslateCursorDrop(float x);
		void SetOnPasteCallback(OnPasteCallback onPasteCallback) { mOnPasteCallback = onPasteCallback; }
		void SetOnCancelCallback(OnCancelCallback onCancelCallback);
		void SetOnSelectAllCallback(OnSelectAllCallback onSelectAllCallback);

		void ClearSelection();
		void ClosePasteBoard();

		Element* GetLeftDrop() { return mLeftDrop; }
		Element* GetRightDrop() { return mRightDrop; }
	private:
		void CreateCopyBoard();
		void CreatePasteBoard();

	private:
		e3::Dim mDropDimInitial;
		e3::Dim mDropDimScaled;

		e3::Animation* mCursorDropAnimation = nullptr;
		e3::Animation* mDropAnimation = nullptr;

		Element* mCopyBoard = nullptr;
		bool mCopyBoardPicked = false;

		Element* mPasteBoard = nullptr;
		bool mPasteBoardPicked = false;

		Element* mCursorDrop = nullptr;
		bool mCursorDropPicked = false;

		Element* mLeftDrop = nullptr;
		bool mLeftDropPicked = false;

		Element* mRightDrop = nullptr;
		bool mRightDropPicked = false;

		glm::vec4 mCursorColor = glm::vec4(0.0, 0.0, 0.0, 255.0);
		Rect2f mInputRect;
		Input* mInput = nullptr;
		Rect2f mTextAreaRect;
		Rect2f mCursorAreaRect;
		glm::vec2 mCursorPosition;
		glm::vec2 mLeftDropPosition;
		glm::vec2 mRightDropPosition;
		float mCursorTranslation = 0.0f;
		bool mCopyEnabled = false;
		bool mPasteEnabled = false;
		bool mCursorEnabled = false;
		e3::Timeout* mTimeout = nullptr;
		OnLeftValueChange mOnLeftValueChange = nullptr;
		OnRightValueChange mOnRightValueChange = nullptr;
		OnCursorChangeCallback mOnCursorChangeCallback = nullptr;
		OnClearSelectionCallback mOnClearSelectionCallback = nullptr;
		OnCutSelectionCallback mOnCutSelectionCallback = nullptr;
		OnCopySelectionCallback mOnCopySelectionCallback = nullptr;
		OnPasteSelectionCallback mOnPasteSelectionCallback = nullptr;
		OnPasteCallback mOnPasteCallback = nullptr;
		OnCancelCallback mOnCancelCallback = nullptr;
		OnSelectAllCallback mOnSelectAllCallback = nullptr;

		std::map<std::string, std::string> mSystemLocale;
	};
}

#endif // __E3_SELECTION_LAYER__