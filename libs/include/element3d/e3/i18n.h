#ifndef __E3_I18N__
#define __E3_I18N__

#include <map>
#include <string>
#include <functional>

#define _t(X) #X, true
#define _STRINGIZE(...) #__VA_ARGS__
#define _s(...) _STRINGIZE(__VA_ARGS__)

namespace e3 
{
	class i18n 
	{
	public:
		typedef std::function<void(const std::string& locale)> OnLanguageChangeCallback;

	public:
		static i18n* Get();

	public:
		void SetLocale(const std::string& locale);
		std::string GetString(const std::string& key);

		int AddCallback(OnLanguageChangeCallback callback);
		void RemoveCallback(int id);

	private:
		i18n();

	private:
		static i18n* sInstance;
		static int sCallbackCounter;

		std::string mLanguage;
		std::map<std::string, std::string> mFileMap;
		std::map<std::string, std::string> mStringMap;
		std::map<int, OnLanguageChangeCallback> mCallbacks;
	};
}

#endif __E3_I18N__
