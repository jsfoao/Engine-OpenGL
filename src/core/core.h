#pragma once

#ifdef NT_PLATFORM_WINDOWS
	#ifdef NT_BUILD_DLL
		#define NATA_API __declspec(dllexport)
	#else
		#define NATA_API __declspec(dllimport)
	#endif
#else
	#error Nata only supports Windows!
#endif