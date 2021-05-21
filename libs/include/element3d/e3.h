#ifndef __E3__
#define __E3__

#if defined(_MSC_VER)
//  Microsoft
#ifdef __E3_EXPORTING__
#define E3_EXPORT __declspec(dllexport)
#else
#define E3_EXPORT __declspec(dllimport)
#endif // __E3_EXPORTING__
#elif defined(__GNUC__)
//  GCC
#define E3_EXPORT __attribute__((visibility("default")))
#define E3_IMPORT
#else
//  do nothing and hope for the best?
#define E3_EXPORT
#define E3_IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#include <e3/strptime.h>
#include <e3/Log.h>

typedef char CHAR;
typedef unsigned char UCHAR;

#endif // __E3__