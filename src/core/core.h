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

#define LOG(x) std::cout << x << std::endl;
#define LOGVEC(x, y) std::cout << "(" << x << ", " << y << ")" << std::endl;
