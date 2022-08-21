#pragma once
#include "core/core.h"
#include "mathf.h"
#include "vector.h"
#include <iostream>

namespace Nata
{
	struct Matrix4
	{
		static const Matrix4 identity;

		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;

		Matrix4();
		Matrix4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33) :
			m00(m00), m01(m01), m02(m02), m03(m03),
			m10(m10), m11(m11), m12(m12), m13(m13),
			m20(m20), m21(m21), m22(m22), m23(m23),
			m30(m30), m31(m31), m32(m32), m33(m33) {}

		Matrix4(const Vector3& v0, const Vector3& v1, const Vector3& v2, const Vector3& v3) :
			m00(v0.x), m01(v0.y), m02(v0.z), m03(0.f),
			m10(v1.x), m11(v1.y), m12(v1.z), m13(0.f),
			m20(v2.x), m21(v2.y), m22(v2.z), m23(0.f),
			m30(v3.x), m31(v3.y), m32(v3.z), m33(1.f) {}
		
		Matrix4 Ortographic(float l, float r, float b, float t, float n, float f) const;
		Matrix4 Perspective(float fov, float aspect, float n, float f) const;
		Matrix4 Translation(const Vector3& t) const;
		Matrix4 Scale(const Vector3& s) const;
		Matrix4 Rotation(float angle, const Vector3& axis) const;
		Vector4 GetColumn(const unsigned int column);
		Vector4 GetRow(const unsigned int row);

		Matrix4 operator*(const Matrix4& r) const
		{
			Matrix4 result;

			result.m00 = m00 * r.m00 + m10 * r.m01 + m20 * r.m02 + m30 * r.m03;
			result.m01 = m01 * r.m00 + m11 * r.m01 + m21 * r.m02 + m31 * r.m03;
			result.m02 = m02 * r.m00 + m12 * r.m01 + m22 * r.m02 + m32 * r.m03;
			result.m03 = m03 * r.m00 + m13 * r.m01 + m23 * r.m02 + m33 * r.m03;

			result.m10 = m00 * r.m10 + m10 * r.m11 + m20 * r.m12 + m30 * r.m13;
			result.m11 = m01 * r.m10 + m11 * r.m11 + m21 * r.m12 + m31 * r.m13;
			result.m12 = m02 * r.m10 + m12 * r.m11 + m22 * r.m12 + m32 * r.m13;
			result.m13 = m03 * r.m10 + m13 * r.m11 + m23 * r.m12 + m33 * r.m13;


			result.m20 = m00 * r.m20 + m10 * r.m21 + m20 * r.m22 + m30 * r.m23;
			result.m21 = m01 * r.m20 + m11 * r.m21 + m21 * r.m22 + m31 * r.m23;
			result.m22 = m02 * r.m20 + m12 * r.m21 + m22 * r.m22 + m32 * r.m23;
			result.m23 = m03 * r.m20 + m13 * r.m21 + m23 * r.m22 + m33 * r.m23;

			result.m30 = m00 * r.m30 + m10 * r.m31 + m20 * r.m32 + m30 * r.m33;
			result.m31 = m01 * r.m30 + m11 * r.m31 + m21 * r.m32 + m31 * r.m33;
			result.m33 = m03 * r.m30 + m13 * r.m31 + m23 * r.m32 + m33 * r.m33;

			return result;
		}

		Vector3 operator*(const Vector3& v) const
		{
			Vector3 x = Vector3(m00 * v.x, m01 * v.x, m02 * v.x);
			Vector3 y = Vector3(m10 * v.y, m11 * v.y, m12 * v.y);
			Vector3 z = Vector3(m20 * v.z, m21 * v.z, m22 * v.z);
			Vector3 w = Vector3(m30, m31, m32);

			return x + y + z + w;
		}

		Vector4 operator*(const Vector4& v) const
		{
			Vector4 x = Vector4(m00 * v.x, m01 * v.x, m02 * v.x, m03 * v.x);
			Vector4 y = Vector4(m10 * v.y, m11 * v.y, m12 * v.y, m13 * v.y);
			Vector4 z = Vector4(m20 * v.z, m21 * v.z, m22 * v.z, m23 * v.z);
			Vector4 w = Vector4(m30 * v.w, m31 * v.w, m32 * v.w, m33 * v.w);

			return x + y + z + w;
		}
	};
}