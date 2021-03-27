#ifndef __CARBON_OS__
#define __CARBON_OS__

#include <e3.h>
#include "Context.h"
// #include "Activity.h"
#include "AssetManager.h"
//#include "GLMainView.h"
// #include "../../../AppAssets.h"
//#include "Container.h"
//#include <e3/CarbonKeyboard.h>
#include <e3/Types.h>
#include <e3/RenderTargetMultisample.h>
#include <e3/RenderTarget.h>
#include <functional>
#include <e3/FXBlur.h>
//#include <e3/CarbonPicker.h>
#include <e3/DropdownLayout.h>
#include <e3/SelectionLayer.h>
#include <Carbon/Buffer.h>
#include <e3/Camera.h>
#include <e3/FontsBase.h>
#include <e3/LocaleBase.h>
#include <e3/ApplicationSharedData.h>
#include <e3/MouseEvent.h>
#include <e3/ScaleEvent.h>

namespace e3
{

	struct KeyEvent 
	{
		EKey Key;
		int Mods;
		char Char;
		unsigned short C;
	};

	struct ResizeEvent
    {
	    float Width;
	    float Height;
    };

    struct MouseMoveEvent : public MouseEvent
    {
        float dx;
        float dy;
    };

    struct MouseCurrentInfo
    {
        glm::vec2 LastDownPosition;
		std::clock_t LastDownTime;
		bool CheckForMouseLongDown;
		bool CheckForLongClick;
      //  View* LastDownView;
    };


    typedef std::function<void(bool)> OnKeyboardStateChangeCallback;

    class Application : public e3::Context 
	{
    public:
	    typedef Callback<void(int width, int height)> OnResizeCallback;
		Application(EE3OS os, EE3Target target, float width, float height);

        virtual ~Application();

    public:
        void render2();
        void render();

        virtual void OnResize(float width, float height) = 0;
        void resize(float width, float height);


    public:
        float Width() { return mWidth; }

        float Height() { return mHeight; }

		EE3Target GetE3Target() { return mE3Target; }
		 
		EDisplaySize GetDisplaySize();
    public:
        void SetKeyboardHeight(int height);

    public:
        void PushElement(Element* pElement);
        void Pop() {}
        Element* GetElement();

        void RequestUpdate() { mUpdateRequested = true; }
		bool GetRequestUpdated() { return mUpdateRequested; }
    public:
        void OnResizeSynched(float width, float height);

        void OnMouseDownSynched(MouseEvent* pEvent);
        void OnMouseDown(MouseEvent* pEvent);
        void OnDoubleClick(MouseEvent* pEvent);
        void OnDoubleClickSynched(MouseEvent* pEvent);

        void OnScale(ScaleEvent* pEvent);
        void OnScaleSynched(ScaleEvent* pEvent);

		void OnMouseLongDownSynched(MouseEvent* pEvent);

        void OnMouseUpSynched(MouseEvent* pEvent);
        void OnMouseUp(MouseEvent* pEvent);

		void OnMouseHover(MouseEvent* pEvent);

        void OnScrollSynched(MouseEvent* pEvent);
        void OnScroll(MouseEvent* pEvent);

		void OnMouseWhell(MouseEvent* pEvent);

        bool OnBack();

        void OnDestroy();

        void OnKey(e3::EKey key, int mods, char c);
        void OnKey(e3::EKey key, int mods, unsigned short c);

        void SetOnKeyboardStateChangeCallback(
                OnKeyboardStateChangeCallback onKeyboardStateChangeCallback) { mOnKeyboardStateChangeCallback = onKeyboardStateChangeCallback; }
        void AddOnResizeCallback(std::shared_ptr<OnResizeCallback> pCallback);

		static void SetOptimalScreenSize(float width, float height);
		static void SetResolution(float width, float height);
		static void SetWidnowSize(float width, float height);

	private:
		void Create();
        void Destroy();
    protected:
//    virtual void OnSideNavigationMenuItemClick(Carbon::NavigationMenuItem* pItem) {}
        bool mInitialized = false;

    protected:
        std::vector<std::shared_ptr<OnResizeCallback>> mOnResizeCallbacks;
        bool mResized = false;

        bool mFirstFrame = true;
        e3::DropdownLayout *mDropdownLayout = nullptr;
        e3::Element* mDialogContainer = nullptr;
        e3::Element *mMainLayout = nullptr;
        e3::Element *mDrawerLayout = nullptr;
		e3::SelectionLayer *mSelectionLayer = nullptr;
        /*AppAssets *mAppAssets = nullptr;
		FontsBase* mFonts = nullptr;
		LocaleBase* mLocale = nullptr;*/

        bool mOpenNavigationMenu = false;
        float mWidth;
        float mHeight;
		e3::Size2i mWindowSize;
        // Carbon::Keyboard* mKeyboard;
        int mKeyboardHeight = 0;
		bool mShowKeyboard = false;
        glm::mat4 mProjection;
        OnKeyboardStateChangeCallback mOnKeyboardStateChangeCallback = nullptr;

        //e3::RenderTargetMultisample *mRenderTarget = nullptr;
        e3::RenderTarget *mRenderTargetActivity = nullptr;
		e3::RenderTarget *mRenderTargetTmp = nullptr;
        /*e3::RenderTarget *mRenderTargetShadow = nullptr;
        e3::RenderTarget *mRenderTargetBloom = nullptr;
        e3::RenderTarget *mRenderTargetShadow1 = nullptr;*/
        /*e3::FXBlur *mFXBlur = nullptr;
        e3::FXBlur *mFXBlurBloom = nullptr;*/
        std::mutex mActivityMutex;
        //e3::Picker mPicker;
        /*GLuint mFramebuffer = 0;
        GLuint mFramebufferMSAA = 0;
        GLuint mRenderbuffer = 0;
        GLuint mRenderbufferMSAA = 0;
        GLuint mRenderbufferDepth = 0;
        GLuint mRenderbufferDepthMSAA = 0;
        GLuint mTexture = 0;*/
        MouseCurrentInfo mMouseCurrentInfo;
        std::queue<MouseEvent*> mEvents;
		std::queue<KeyEvent*> mKeyEvents;
		std::queue<ResizeEvent*> mResizeEvents;
        std::mutex mEventMutex;

        std::shared_ptr<Camera> mCamera = nullptr;
        GLuint mVAO = 0;
        Carbon::Buffer* mVertexBuffer = nullptr;
        Carbon::Buffer* mIndexBuffer = nullptr;

        std::vector<Element*> mStack;
        bool mUpdateRequested = false;

        EE3OS mE3Os;
        EE3Target mE3Target;
    };
}

#endif // __CARBON_OS__
