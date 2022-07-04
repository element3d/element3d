#ifndef __E3_WINDOW__
#define __E3_WINDOW__

#include <iostream>
#include <cctype>
#include <functional>
#include <e3/OpenGLES.h>
#include <e3/CarbonKeys.h>
#include <e3/Types.h>
#include <e3/MouseEvent.h>
#include <e3/Application.h>

namespace e3 
{
	struct WindowCreateInfo 
	{
		std::string Name;
		e3::Size2i Size;
		e3::Size2i Resoluction;
	};
	typedef WindowCreateInfo WindowParams;

	class Window 
	{
		typedef std::function<void(int width, int height)> OnResizeCallback;
		typedef std::function<void(MouseEvent* pEvent)> OnMouseDownCallback;
		typedef std::function<void(MouseEvent* pEvent)> OnMouseUpCallback;
		typedef std::function<void(MouseEvent* pEvent)> OnMouseHoverCallback;
		typedef std::function<void(MouseEvent* pEvent)> OnScrollCallback;
		typedef std::function<void(MouseEvent* pEvent)> OnMouseWhellCallback;

	public:
		Window(WindowCreateInfo* pWindowCreateInfo);

	public:
		void SetApplication(e3::Application* pApplication);
		void Show();

	public:
		void SetSize(int width, int height);
		Size2i GetSize() { return mParams.Size; }
		Size2i GetResolution() { return mParams.Resoluction; }

	public:
		void SetClipboardString(const std::string& str);
		std::string GetClipboardString();

		void SetCursor(ECursor cursor);
	public:
		void SetOnResizeCallback(OnResizeCallback onResizeCallback);
		void SetOnMouseDownCallback(OnMouseDownCallback onMouseDownCallback);
		void SetOnMouseUpCallback(OnMouseUpCallback onMouseUpCallback);
		void SetOnMouseHoverCallback(OnMouseHoverCallback onMouseHoverCallback);
		void SetOnScrollCallback(OnScrollCallback onScrollCallback);
		void SetOnMouseWhellCallback(OnMouseWhellCallback onMouseWhellCallback);

	public:
		virtual void OnRender() = 0;
		virtual void OnResize(int width, int height);
		virtual void OnMouseDown(MouseEvent* pEvent);
		virtual void OnMouseUp(MouseEvent* pEvent);
		virtual void OnMouseHover(MouseEvent* pEvent);
		virtual void OnScroll(MouseEvent* pEvent);
		virtual void OnMouseWhell(MouseEvent* pEvent);
		virtual void OnKey(e3::EKey key, int mods, unsigned short c);

	private:
		void* mGLFWWindow = nullptr;
		e3::Application* mApplication = nullptr;

		std::map<ECursor, void*> mCursors;
		WindowParams mParams;
		OnResizeCallback mOnResizeCallback = nullptr;
		OnMouseHoverCallback mOnMouseHoverCallback = nullptr;
		OnScrollCallback mOnScrollCallback = nullptr;
		OnMouseDownCallback mOnMouseDownCallback = nullptr;
		OnMouseUpCallback mOnMouseUpCallback = nullptr;
		OnMouseWhellCallback mOnMouseWhellCallback = nullptr;
	};
}

#endif // __E3_WINDOW__