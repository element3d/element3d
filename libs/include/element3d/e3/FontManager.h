#ifndef __E3_FONT_MANAGER__
#define __E3_FONT_MANAGER__

#include <string>
#include <vector>
#include <map>
#include <e3/Enum.h>
#include <e3/Font.h>
#include <e3/AssetManager.h>
//#include <e3/FontsBase.h>
#include <memory>

namespace e3 
{

	class FontManager
	{
	public:
		static FontManager* Get();
		//void Init(FontsBase* pFonts);

	public:
		void SetAssetManager(AssetManager* pAssetManager);
		std::shared_ptr<Font> FindFont(FontParams* pParams);
		std::shared_ptr<Font> FindFontByPath(const std::string& path, int fontSize);

	private:
		FontManager();
		static FontManager* sInstance;

	private:
		/*void ProcessFolder(const std::string& folder);
		void ProcessFont(const std::string& font);*/

		/*std::vector<std::string> mItalics;
		std::vector<std::string> mBolds;*/
		/*std::map<std::string, std::vector<FontParams>> mFonts;

		std::map<std::string, Font*> mLoadedFonts;*/

		//FontsBase* mFonts = nullptr;
		std::map<std::string, std::vector<FontParams>> mSystemFonts;
		AssetManager* mAssetManager = nullptr;
		std::map<std::string, std::map<int, std::shared_ptr<Font>>> mLoadedFonts;
	};
}

#endif // __E3_FONT_MANAGER__