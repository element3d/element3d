#ifndef __PUZL_ASSETMANAGER_H__
#define __PUZL_ASSETMANAGER_H__

#ifdef __E3_OS_ANDROID__ 
// #include <android_native_app_glue.h>
#include <Android/asset_manager.h>
#include <jni.h>
#include <pthread.h>
#endif // __E3_OS_ANDROID__

#include <string>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <map>
#include <memory>

namespace e3
{

	class AssetManager
	{
	private:
		AssetManager();

	public:
		// static AssetManager* sInstance;
		static AssetManager& get();

		static void Destroy()
		{
			//  delete sInstance;
		}

	public:
#ifdef __E3_OS_ANDROID__ 
		void init(JNIEnv* env, jobject obj, jobject assetManager, jstring internalDirj, jstring ExternalDir, jstring jExternalStorageDirectory);
#elif __E3_OS_WINDOWS__ || __E3_OS_LINUX__ || __E3_OS_WEB__
		void init(const std::string& internalDirj, const std::string& ExternalDir);
#endif
		~AssetManager();

	public:
		bool copyAsset(const std::string& assetName, const std::string& dst);



	public:
		std::string GetExternalStorageDirectory() { return mAExternalStorageDirectory; }
		std::string GetRoot();
		std::string getPath(const std::string& assetName);

	private:
		std::string cutFilename(const std::string& path);

	private:
		std::string    mAInternalPath;
		std::string    mAExternalPath;
		std::string    mAExternalStorageDirectory;
#ifdef __E3_OS_ANDROID__ 
		AAssetManager* mAAssetManager;
#endif
		// mutable pthread_mutex_t mMutex;
		std::mutex mMutex;

		/*std::mutex mAssetLoadMutex;
		std::condition_variable mCondVar;
		std::thread mAssetLoadThreads[4];
		std::map<int, bool> mLoadedAssets;*/

		//std::map<int, std::shared_ptr<e3::Image>> mLoadedImages;
	};
}
#endif // __PUZL_ASSETMANAGER_H__
