#ifndef __E3_APPLICATION__
#define __E3_APPLICATION__

#include <e3.h>
#include "Context.h"
#include "AssetManager.h"
#include <e3/Types.h>
#include <functional>
#include <e3/MouseEvent.h>
#include <e3/ScaleEvent.h>
#include <e3/Image.h>
#include <e3/Enum.h>
#include <e3/Animation.h>
#if __E3_OS_ANDROID__
#include "Android/Application.h"
#endif

namespace e3
{
	

    struct MouseMoveEvent : public MouseEvent
    {
        float dx;
        float dy;
    };

    class Application : public e3::Context
#if __E3_OS_ANDROID__
, public e3::Android::Application
#endif
	{
    public:
		Application(const std::string& applicationName, EE3OS os, EE3Target target, e3::Size2i windowSize, e3::Size2i resolution);
        virtual ~Application();

    public:
        virtual void Render();
		e3::Image* RenderToImage();

        virtual void OnResize(float width, float height) = 0;
        void Resize(float width, float height);

	public:
		void PushElement(Element* pElement);
		void PushElement(Element* pElement, bool reversedOrder, e3::Animation* pTransitionAnimation);
		void PopElement();
		void PopElement(e3::Animation* pTransitionAnimation);
		Element* GetElement();

    public:
		void SetWindowSize(int width, int height);
		Size2i GetWindowSize();
		Size2i GetResolution();
		EE3Target GetE3Target();
		EE3OS GetE3OS();
		EDisplaySize GetDisplaySize();
		float GetDisplayDensity();
		AssetManager* GetAssetManager();

    public: // Events
        void OnMouseDown(MouseEvent* pEvent);
        void OnDoubleClick(MouseEvent* pEvent);
        void OnScale(ScaleEvent* pEvent);
        void OnMouseUp(MouseEvent* pEvent);
		void OnMouseHover(MouseEvent* pEvent);
        void OnScroll(MouseEvent* pEvent);
		void OnMouseWhell(MouseEvent* pEvent);
        void OnKey(e3::EKey key, int mods, char c);
        void OnKey(e3::EKey key, int mods, unsigned short c);
		virtual bool OnBack();
		virtual bool OnBack(e3::Animation* pTransitionAnimation);
		void OnDestroy();

	public:
        void AddOnResizeCallback(std::shared_ptr<OnResizeCallback> pCallback);

	public:
		void RequestUpdate();

		void SetRenderer(e3::ERenderer r);

	private:
		bool _OnMouseHover(e3::MouseEvent* pEvent, e3::Element* pElement, bool checkForHover);
    };
}

#endif // __E3_APPLICATION__
