#pragma once

#ifdef ABK_PLATFORM_WINDOWS
	#ifdef ABK_BUILD_DLL
		#define ABSTRAK_API __declspec(dllexport)
	#else
		#define ABSTRAK_API __declspec(dllimport)
	#endif // ABK_BULD_DLL
#else
	#error Abtrak only supports Windows
#endif // ABK_PLATFORM_WINDOWS


#define BIT(x) (1 << x)