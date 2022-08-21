#pragma once
#include <cmath>
#include "core/core.h"

namespace Nata
{
	struct Vector2
	{
		static const Vector2 zero;
		static const Vector2 one;
		static const Vector2 right;
		static const Vector2 up;

		float x, y;

		Vector2() : x(0.f), y(0.f) {}
		Vector2(float v) : x(v), y(v) {}
		Vector2(float x, float y) : x(x), y(y) {};

		Vector2 operator+() const { return Vector2(x, y); }
		Vector2 operator-() const { return Vector2(-x, -y); }

		friend Vector2 operator*(const Vector2& lhs, const float& rhs) { return Vector2(lhs.x * rhs, lhs.y * rhs); }
		friend Vector2 operator*(const float& lhs, const Vector2& rhs) { return Vector2(rhs.x * lhs, rhs.y * lhs); }
		Vector2 operator+(Vector2& r) const { return Vector2(x + r.x, y + r.y); }
		Vector2 operator-(Vector2& r) const { return Vector2(x - r.x, y - r.y); }
		Vector2 operator/(float v) const { return Vector2(x / v, y / v); }

		Vector2 operator+=(const Vector2& r) { x += r.x; y += r.y; return *this; }
		Vector2 operator-=(const Vector2& r) { x -= r.x; y -= r.y; return *this; }
		Vector2& operator*=(float v) { x *= v; y *= v; return *this; }
		Vector2& operator/=(float v) { x /= v; y /= v; return *this; }

		float Magnitude() const { return sqrt(x * x + y * y); };
		Vector2 Normalized() const { return Vector2(x / Magnitude(), y / Magnitude()); };
		

		static float Dot(const Vector2& v1, const Vector2& v2) { return (v1.x * v2.x) + (v1.y * v2.y); };
	};

	struct Vector3
	{
		static const Vector3 zero;
		static const Vector3 one;
		static const Vector3 right;
		static const Vector3 forward;
		static const Vector3 up;

		float x, y, z;

		Vector3() : x(0.f), y(0.f), z(0.f) {}
		Vector3(float v) : x(v), y(v), z(v) {}
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {};
			  
		Vector3 operator+() const { return Vector3(x, y, z); }
		Vector3 operator-() const { return Vector3(-x, -y, -z); }
			  
		Vector3 operator+(Vector3& r) const { return Vector3(x + r.x, y + r.y, z + r.z); }
		Vector3 operator-(Vector3& r) const { return Vector3(x - r.x, y - r.y, z + r.z); }
		//friend Vector3 operator*(const Vector3& lhs, const float& rhs) { return Vector3(lhs.x * rhs, lhs.y * rhs); }
		//friend Vector3 operator*(const float& lhs, const Vector2& rhs) { return Vector3(rhs.x * lhs, rhs.y * lhs); }
		Vector3 operator/(float v) const { return Vector3(x / v, y / v, z / v); }
			  
		Vector3 operator+=(const Vector3& r) { x += r.x; y += r.y; z += r.z; return *this; }
		Vector3 operator-=(const Vector3& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }
		Vector3& operator*=(float v) { x *= v; y *= v; z *= v; return *this; }
		Vector3& operator/=(float v) { x /= v; y /= v; z /= v; return *this; }
	};

	struct Vector4
	{
		static const Vector4 zero;
		static const Vector4 one;

		float x, y, z, w;

		Vector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}
		Vector4(float v) : x(v), y(v), z(v), w(v) {}
		Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
			  
		Vector4 operator+() const { return Vector4(x, y, z, w); }
		Vector4 operator-() const { return Vector4(-x, -y, -z, -w); }
			  
		Vector4 operator+(Vector4& r) const { return Vector4(x + r.x, y + r.y, z + r.z, w + r.w); }
		Vector4 operator-(Vector4& r) const { return Vector4(x - r.x, y - r.y, z + r.z, w + r.w); }
		Vector4 operator*(float v) const { return Vector4(x * v, y * v, z * v, w * v); }
		Vector4 operator/(float v) const { return Vector4(x / v, y / v, z / v, w / v); }
			  
		Vector4& operator/=(float v) { x /= v; y /= v; z /= v; return *this; }
	};


}