#ifndef __CARBON_CONTEXT__
#define __CARBON_CONTEXT__

#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <mutex>
#include <memory>
#include <time.h>
#include <chrono>

#include <e3/GLBuffer.h>
#include <e3/Camera.h>
#include <e3/Types.h>
#include <e3/RenderTargetMultisample.h>
#include <e3/RenderTarget.h>
#include <e3/AssetManager.h>
#include <e3/Timeout.h>
typedef std::function<void(bool)> OnImageGalleryStateChangeCallback;
typedef std::function<void(const std::string& path)> OnImageGalleryResultCallback;
typedef std::function<void(const std::string& message)> OnInteractionCallback;

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

	typedef std::function<void(void)> UiThreadRunnable;
	typedef std::function<void(const std::string&)> OnCopyToClipboardCallback;
	typedef std::function<void(void)> OnGetClipboardStringCallback;
	typedef std::function<void(ECursor)> OnSetCursorCallback;
	typedef std::function<void(int width, int height)> OnSetWindowSizeCallback;
	typedef std::function<void(bool)> OnKeyboardStateChangeCallback;
	typedef Callback<void(int width, int height)> OnResizeCallback;

    class Context
    {
    public:
		Context(const std::string& applicationName, EE3OS os, EE3Target target, e3::Size2i windowSize, e3::Size2i resolution/*, float density*/);

		void SetApplicationName(const std::string& name);
		std::string GetApplicationName();

		void OpenImageGallery(OnImageGalleryResultCallback onImageGalleryResultCallback);
		void SetOnImageGalleryStateChangeCallback(OnImageGalleryStateChangeCallback onImageGalleryStateChangeCallback);
		void SetImageGalleryResultPath(const std::string& path);
        
		void SetOnInteractionCallback(OnInteractionCallback onOnInteractionCallback);
		void Interact(const std::string& message);

		void SetOnSetCursorCallback(OnSetCursorCallback onSetCursorCallback);
		void SetCursor(ECursor cursor);

		void SetOnSetWindowSizeCallback(OnSetWindowSizeCallback onSetWindowSizeCallback);

		void SetOnCopyToClipboardCallback(OnCopyToClipboardCallback onCopyToClipboardCallback);
		void CopyToClipboard(const std::string& text);

		void SetOnGetClipboardStringCallback(OnGetClipboardStringCallback onGetClipboardStringCallback);
		std::string GetClipboardString();
		void SetClipboardString(const std::string& text);

		//void RunOnUiThread(UiThreadRunnable runnable);
		void RunOnUiThread(Callback<void(void)>* runnable);

		void SetOnKeyboardStateChangeCallback(OnKeyboardStateChangeCallback onKeyboardStateChangeCallback);
		void SetKeyboardHeight(int height);

	protected:
		void RunUiThreadJobs();

	protected:
		void OnResizeSynched(float width, float height);
		void OnMouseDownSynched(MouseEvent* pEvent);
		void OnDoubleClickSynched(MouseEvent* pEvent);
		void OnScaleSynched(ScaleEvent* pEvent);
		void OnMouseLongDownSynched(MouseEvent* pEvent);
		void OnMouseUpSynched(MouseEvent* pEvent);
		void OnScrollSynched(MouseEvent* pEvent);
		
	protected:
		void Create();
		void Destroy();

	private:
		Element* _GetElement();

	protected:
		// Params
		std::string mAppName;
		float mDensity;
		float mWidth;
		float mHeight;
		e3::Size2i mWindowSize;
		e3::Size2i mResolution;
		EE3OS mE3Os;
		EE3Target mE3Target;

		// Layers
		e3::Element *mDropdownLayout = nullptr;
		e3::Element* mDialogContainer = nullptr;
		e3::Element *mMainLayout = nullptr;
		e3::Element *mSelectionLayer = nullptr;

		// Interactions
        OnImageGalleryStateChangeCallback mOnImageGalleryStateChangeCallback = nullptr;
        OnImageGalleryResultCallback mOnImageGalleryResultCallback = nullptr;
        OnInteractionCallback mOnInteractionCallback = nullptr;

		// UI thread
		std::queue<UiThreadRunnable> mUiThreadRunnables;
		std::queue<Callback<void(void)>*> mUiThreadCallbacks;
		std::mutex mUiThreadRunnablesMutex;

		// Clipboard
		OnCopyToClipboardCallback mOnCopyToClipboardCallback = nullptr;
		OnGetClipboardStringCallback mOnGetClipboardStringCallback = nullptr;
		std::string mClipboardString = "";

		// Keyboard
		int mKeyboardHeight = 0;
		bool mShowKeyboard = false;
		OnKeyboardStateChangeCallback mOnKeyboardStateChangeCallback = nullptr;

		// Events
		std::queue<MouseEvent*> mEvents;
		std::queue<KeyEvent*> mKeyEvents;
		std::queue<ResizeEvent*> mResizeEvents;
		std::mutex mEventMutex;
		struct
		{
			glm::vec2 LastDownPosition;
			clock_t LastDownTime;
			bool CheckForMouseLongDown;
			bool CheckForLongClick;
		} mMouseCurrentInfo;

		// Resize
		std::vector<std::shared_ptr<OnResizeCallback>> mOnResizeCallbacks;
		bool mResized = false;

		// OpenGL
		glm::mat4 mProjection;
		std::shared_ptr<Camera> mCamera = nullptr;
		GLuint mVAO = 0;
		e3::GLBuffer* mVertexBuffer = nullptr;
		e3::GLBuffer* mIndexBuffer = nullptr;
		e3::RenderTarget *mRenderTargetActivity = nullptr;

		// Misc
		OnSetCursorCallback mOnSetCursorCallback = nullptr;
		OnSetWindowSizeCallback mOnSetWindowSizeCallback;
		bool mFirstFrame = true;
		std::vector<Element*> mStack;
		e3::Element* mPendingElement = nullptr;
		bool mPendingElementReversed = false;
		bool mUpdateRequested = false;
		bool mBackButtonPressed = false;
		std::mutex mBackButtonMutex;

		// Platform
#if !__E3_OS_ANDROID__
        AssetManager* mAssetManager = nullptr;
#endif

        //e3::RenderTargetMultisample *mRenderTarget = nullptr;
		//e3::RenderTarget *mRenderTargetTmp = nullptr;
		/*e3::RenderTarget *mRenderTargetShadow = nullptr;
		e3::RenderTarget *mRenderTargetBloom = nullptr;
		e3::RenderTarget *mRenderTargetShadow1 = nullptr;*/
		/*e3::FXBlur *mFXBlur = nullptr;
		e3::FXBlur *mFXBlurBloom = nullptr;*/
		//std::mutex mActivityMutex;
		//e3::Picker mPicker;
		/*GLuint mFramebuffer = 0;
		GLuint mFramebufferMSAA = 0;
		GLuint mRenderbuffer = 0;
		GLuint mRenderbufferMSAA = 0;
		GLuint mRenderbufferDepth = 0;
		GLuint mRenderbufferDepthMSAA = 0;
		GLuint mTexture = 0;*/
    };
}

#endif // __CARBON_CONTEXT__