#ifndef __PUZL_ASSETMANAGER_H__
#define __PUZL_ASSETMANAGER_H__

#ifdef __E3_OS_ANDROID__ 
#include <android/asset_manager.h>
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

#if __E3_OS_ANDROID__
#include "Android/Context.h"
#endif

namespace e3
{
	class AssetManager
	{
	public:
#if __E3_OS_ANDROID__
		AssetManager(e3::Android::Context* pContext);
#else
		AssetManager();
#endif
	public:
		~AssetManager();

	public:
		std::string GetAssetPath(const std::string& assetName);

	private:
		std::string _CutFilename(const std::string& path);
		bool _CopyAsset(const std::string& assetName, const std::string& dst);

	private:
#ifdef __E3_OS_ANDROID__
		AAssetManager* mAAssetManager;
		e3::Android::Context* mContext = nullptr;
#endif
//		std::mutex mMutex;
	};
}
#endif // __PUZL_ASSETMANAGER_H__
