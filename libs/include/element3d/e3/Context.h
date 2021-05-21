#ifndef __CARBON_CONTEXT__
#define __CARBON_CONTEXT__

#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <mutex>
#include <e3/Types.h>

typedef std::function<void(bool)> OnImageGalleryStateChangeCallback;
typedef std::function<void(const std::string& path)> OnImageGalleryResultCallback;
typedef std::function<void(const std::string& message)> OnInteractionCallback;

namespace e3
{
	typedef std::function<void(void)> UiThreadRunnable;
	typedef std::function<void(const std::string&)> OnCopyToClipboardCallback;
	typedef std::function<void(void)> OnGetClipboardStringCallback;
	typedef std::function<void(ECursor)> OnSetCursorCallback;


    class Context
    {
    public:
        Context() {}

		void SetApplicationName(const std::string& name);
		std::string GetApplicationName();

		void OpenImageGallery(OnImageGalleryResultCallback onImageGalleryResultCallback);
		void SetOnImageGalleryStateChangeCallback(OnImageGalleryStateChangeCallback onImageGalleryStateChangeCallback);
		void SetImageGalleryResultPath(const std::string& path);
        
		void SetOnInteractionCallback(OnInteractionCallback onOnInteractionCallback);
		void Interact(const std::string& message);

		void SetOnSetCursorCallback(OnSetCursorCallback onSetCursorCallback);
		void SetCursor(ECursor cursor);

		void SetOnCopyToClipboardCallback(OnCopyToClipboardCallback onCopyToClipboardCallback);
		void CopyToClipboard(const std::string& text);

		void SetOnGetClipboardStringCallback(OnGetClipboardStringCallback onGetClipboardStringCallback);
		std::string GetClipboardString();
		void SetClipboardString(const std::string& text);

		void RunOnUiThread(UiThreadRunnable runnable);
		void RunOnUiThread(Callback<void(void)>* runnable);

	protected:
		void RunUiThreadJobs();

    private:
		std::string mAppName;
        OnImageGalleryStateChangeCallback mOnImageGalleryStateChangeCallback = nullptr;
        OnImageGalleryResultCallback mOnImageGalleryResultCallback = nullptr;
        OnInteractionCallback mOnInteractionCallback = nullptr;

		std::queue<UiThreadRunnable> mUiThreadRunnables;

		std::queue<Callback<void(void)>*> mUiThreadCallbacks;

		std::mutex mUiThreadRunnablesMutex;

		OnCopyToClipboardCallback mOnCopyToClipboardCallback = nullptr;
		OnGetClipboardStringCallback mOnGetClipboardStringCallback = nullptr;
		OnSetCursorCallback mOnSetCursorCallback = nullptr;
		std::string mClipboardString = "";
    };
}

#endif // __CARBON_CONTEXT__