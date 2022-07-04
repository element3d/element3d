#ifndef __E3_IMAGE__
#define __E3_IMAGE__

// e3
 #include <e3/Types.h>

#include "e3.h"
// std
#include <string>
#include <map>
#include <memory>
#include <future>

class Texture;

namespace e3 
{
	class Image;
	
	typedef std::function<void(std::shared_ptr<e3::Image>)> OnImageLoadCallback;
	typedef std::function<void()> OnImageLoadCallback1;

	enum class EImageFormat
	{
		RGB,
		RGBA
	};

	// class OnLoadCallback : public
	typedef Callback<void(void)> OnLoadCallback;

	class Image
	{
	public:
		Image();
		~Image();
		Image(float w, float h, EImageFormat format, unsigned char* pData);

	public:
		Texture* GetTexture() { return mTexture; }

	public:
		void SetData(float width, float height, EImageFormat format, void* pData);

	public:
		bool Load(const std::string& filename);
		void LoadAsync(const std::string& filename, OnLoadCallback* callback);

		void LoadFile(const std::string& filename, std::shared_ptr<OnLoadCallback> callback);
		static std::shared_ptr<e3::Image> LoadAssetAsync(const std::string& filename);

		static std::future<std::shared_ptr<e3::Image>> LoadAsset(const std::string& filename);
		static void Load(const std::string& filename, OnImageLoadCallback callback);
		void Save(const std::string& filename);
		//static std::shared_ptr<e3::Image> LoadAsset(int id);

	public:
		int GetNVGImage() { return mNVGImage; }
		bool empty() { return mEmpty; }
		float GetWidth();
		float GetHeight();
		int GetNumChannels();
		unsigned char* GetData() { return mData; }
		void SetOpacity(float opacity) { mOpacity = opacity; }
		float GetOpacity() { return mOpacity; }

	private:
		void LoadThreadWorker2(const std::string& filename, std::shared_ptr<OnLoadCallback> callback);
		void LoadAssetAsyncWorker(const std::string& filename);
		static void LoadThreadWorker(const std::string& filename, OnImageLoadCallback callback);
		static std::shared_ptr<e3::Image> ImageLoadThreadWorker(const std::string& filename);

                //void LoadThreadWorker1(const std::string& filename, OnImageLoadCallback1 callback);

	private:
		unsigned char* mData = nullptr;
		std::string mFilename;
		int mWidth = 0;
		int mHeight = 0;
		int mNumChannels;
		bool mEmpty = true;
		Texture* mTexture = nullptr;

	private:
		// static std::map<std::string, std::shared_ptr<e3::Image>> mLoadedUrls;
		static std::map<std::string, std::shared_ptr<e3::Image>> mLoadedAssets;
		std::function<void()> mUiRunnable;
		Callback<void()>* mUiThreadRunnable = nullptr;
		std::thread mThread;
        OnLoadCallback* mCall = nullptr;
		float mOpacity = 1.0f;

		int mNVGImage = -1;
		bool mDestructing = false;

		friend class NVGRenderer;
	};
}

#endif 
