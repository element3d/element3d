#ifndef __E3_LOCALE_BASE__
#define __E3_LOCALE_BASE__

#include <string>
#include <map>

namespace e3 
{
	class LocaleBase
	{
	public:
		LocaleBase() {}

	public:
		std::string GetLocalePath(int locale);

	protected:
		std::map<int, std::string> mLocales;
	};
}

#endif // __E3_LOCALE_BASE__