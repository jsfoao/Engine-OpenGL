#pragma once
#include "core/core.h"
#include "mathf.h"
#include "vector.h"
#include <iostream>

namespace Nata
{
	struct Matrix4
	{

		float elements[16];

		Matrix4();
		Matrix4(float diagonal);
		
		static Matrix4 Identity();

		Matrix4& Multiply(const Matrix4& other);
		friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
		Matrix4& operator*=(const Matrix4& other);
		
		
		static Matrix4 Ortographic(float left, float right, float bottom, float top, float near, float far);
		static Matrix4 Perspective(float fov, float aspectRatio, float near, float far);

		static Matrix4 Translation(const Vector3& translation);
		static Matrix4 Rotation(float angle, const Vector3& axis);
		static Matrix4 Scale(const Vector3& scale);

		
	};
}