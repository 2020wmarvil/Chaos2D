#pragma once

#ifdef CH2_PLATFORM_WINDOWS
	#ifdef CH2_BUILD_DLL
		#define CHAOS2D_API __declspec(dllexport)
	#else
		#define CHAOS2D_API __declspec(dllimport)
	#endif
#else
	#error Chaos2D only supports Windows
#endif 

