#pragma once
#define PI (3.14159265359f)
#define HALF_PI (1.57079632679f)
#define TAU (6.28318530718f)
#define KINDA_SMALL_NUMBER (0.0001f)
#define SMALL_NUMBER (0.0000001f)
#define BIG_NUMBER (3.4e+38f)

namespace Nata
{
	static inline float ToRadians(float deg)
	{
		return deg * (PI / 180.f);
	}

	static inline float ToDeg(float rad)
	{
		return rad * (180.f / PI);
	}
}