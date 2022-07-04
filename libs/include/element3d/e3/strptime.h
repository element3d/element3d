#ifndef __E3_STRPTIME__
#define __E3_STRPTIME__

#ifdef WIN32

#include <time.h>
#include <iomanip>
#include <sstream>

extern "C" char* strptime
(
	const char* s,
	const char* f,
	struct tm* tm
);

#endif

#endif