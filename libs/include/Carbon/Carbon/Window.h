#ifndef __CARBON_WINDOW__
#define __CARBON_WINDOW__

#include <GLFW/glfw3.h>

namespace Carbon 
{
	struct WindowCreateInfo
	{
		float Width;
		float Height;
		const char* Title;
	};

	class Window 
	{
	public:
		Window(const WindowCreateInfo* pInfo);
		~Window() {}

		void Show();
	public:
		virtual void OnRender() = 0;

	protected:
		GLFWwindow* mWindow = nullptr;
		float mWidth = 0.0f;
		float mHeight = 0.0f;
	};
}

#endif // __CARBON_WINDOW__