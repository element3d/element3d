#ifndef __E3_IMAGE__
#define __E3_IMAGE__

// e3
 #include <e3/Types.h>

#include "e3.h"
// std
#include <string>
#include <map>
#include <memory>

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

	class Image
	{
		typedef Callback<void(void)> OnLoadCallback;
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
		void Load(const std::string& filename, OnImageLoadCallback1 callback);
		void LoadFile(const std::string& filename, std::shared_ptr<OnLoadCallback> callback);
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
		static void LoadThreadWorker(const std::string& filename, OnImageLoadCallback callback);
                //void LoadThreadWorker1(const std::string& filename, OnImageLoadCallback1 callback);

	private:
		unsigned char* mData = nullptr;
		int mWidth = 0;
		int mHeight = 0;
		int mNumChannels;
		bool mEmpty = true;
		Texture* mTexture = nullptr;

	private:
		// static std::map<std::string, std::shared_ptr<e3::Image>> mLoadedUrls;
		static std::map<int, std::shared_ptr<e3::Image>> mLoadedAssets;
		std::function<void()> mUiRunnable;
		//std::thread mThread;
        OnLoadCallback* mCall = nullptr;
		float mOpacity = 1.0f;

		int mNVGImage = -1;

		friend class NVGRenderer;
	};
}

#endif 
