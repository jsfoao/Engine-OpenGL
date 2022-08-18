#pragma once
#define M_PI   3.14159265358979323846264338327950288

namespace Nata
{
	namespace Math
	{
		static inline float ToRadians(float deg)
		{
			return deg * (M_PI / 180.f);
		}

		static inline float ToDeg(float rad)
		{
			return rad * (180.f / M_PI);
		}
	}
}