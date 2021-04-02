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

        void OpenImageGallery(OnImageGalleryResultCallback onImageGalleryResultCallback)
        {
            mOnImageGalleryResultCallback = onImageGalleryResultCallback;
            if (mOnImageGalleryStateChangeCallback) mOnImageGalleryStateChangeCallback(true);
        }
        void SetOnImageGalleryStateChangeCallback(OnImageGalleryStateChangeCallback onImageGalleryStateChangeCallback) { mOnImageGalleryStateChangeCallback = onImageGalleryStateChangeCallback; }
        void SetOnInteractionCallback(OnInteractionCallback onOnInteractionCallback) { mOnInteractionCallback = onOnInteractionCallback; }
        void interact(const std::string& message)
        {
            if (mOnInteractionCallback) mOnInteractionCallback(message);
        }
        void SetImageGalleryResultPath(const std::string& path)
        {
            if (mOnImageGalleryResultCallback) mOnImageGalleryResultCallback(path);
            mOnImageGalleryResultCallback = nullptr;
        }

		void SetOnSetCursorCallback(OnSetCursorCallback onSetCursorCallback) { mOnSetCursorCallback = onSetCursorCallback; }
		void SetCursor(ECursor cursor) { if (mOnSetCursorCallback) mOnSetCursorCallback(cursor); }

		void runUiThreadJobs() 
		{
			std::lock_guard<std::mutex> lock(mUiThreadRunnablesMutex);
			if (!mUiThreadRunnables.empty())
			{
				UiThreadRunnable runnable = mUiThreadRunnables.front();
				mUiThreadRunnables.pop();
				if (runnable) runnable();
				//RequestUpdate();
				return;
			}
			if (!mUiThreadCallbacks.empty())
			{
				Callback<void(void)>* runnable = mUiThreadCallbacks.front();
				mUiThreadCallbacks.pop();
				if (runnable->GetSubscribed()) 
				{
					runnable->f();
					// delete runnable;
				}
				//RequestUpdate();
				return;
			}
		}
		void RunOnUiThread(UiThreadRunnable runnable) 
		{
			std::lock_guard<std::mutex> lock(mUiThreadRunnablesMutex);
			mUiThreadRunnables.push(runnable);
		}

		void RunOnUiThread(Callback<void(void)>* runnable)
		{
			std::lock_guard<std::mutex> lock(mUiThreadRunnablesMutex);
			mUiThreadCallbacks.push(runnable);
		}

		void SetOnCopyToClipboardCallback(OnCopyToClipboardCallback onCopyToClipboardCallback) { mOnCopyToClipboardCallback = onCopyToClipboardCallback; }
		void CopyToClipboard(const std::string& text) { mOnCopyToClipboardCallback(text); }

		void SetOnGetClipboardStringCallback(OnGetClipboardStringCallback onGetClipboardStringCallback) {
			mOnGetClipboardStringCallback
				= onGetClipboardStringCallback;
		}
		std::string GetClipboardString() { mOnGetClipboardStringCallback(); return mClipboardString; }
		void SetClipboardStringInternal(const std::string& text) { mClipboardString = text; }
    private:
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