#ifndef __E3_I18N__
#define __E3_I18N__

#include <map>
#include <string>
#include <functional>
#include "LocaleBase.h"
#define _t(X) #X, true
#define _s(X) std::string(#X)

namespace e3 
{
	class i18n 
	{
	public:
		typedef std::function<void(const std::string& locale)> OnLanguageChangeCallback;

	public:
		static i18n* Get();

		void Init(LocaleBase* pLocale);
		//void SetLanguage(const std::string& language);
		void SetLocale(const std::string& locale);
		// void SetLocale(int locale);
		int AddCallback(OnLanguageChangeCallback callback);
		void RemoveCallback(int id);
		std::string GetString(const std::string& key);

	private:
		i18n();
	private:
		static i18n* sInstance;
		static int sCallbackCounter;

		e3::LocaleBase* mLocale = nullptr;
		std::string mLanguage;
		//int mLanguage;
		std::map<std::string, std::string> mFileMap;
		std::map<std::string, std::string> mStringMap;
		std::map<int, OnLanguageChangeCallback> mCallbacks;
	};
}

#endif __E3_I18N__