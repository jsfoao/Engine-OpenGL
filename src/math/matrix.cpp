#pragma once
#include "matrix.h"

namespace Nata
{
	const Matrix4 Matrix4::identity(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);

	Matrix4::Matrix4() {};

	Matrix4 Matrix4::Ortographic(float l, float r, float b, float t, float n, float f) const
	{
		return Matrix4(
			2 / (r - l), 0.f, 0.f, -(r + l) / (r - l),
			0.f, 2 / (t - b), 0.f, -(t + b) / (t - b),
			0.f, 0.f, -2 / (f - n), -(f + n) / (f - n),
			0.f, 0.f, 0.f, 1.f
		);
	}

	Matrix4 Matrix4::Perspective(float fov, float aspect, float n, float f) const
	{
		// TODO: Maybe to radians?
		return Matrix4(
			1 / (aspect * tan(fov / 2)), 0.f, 0.f, 0.f,
			0.f, 1 / (tan(fov / 2)), 0.f, 0.f,
			0.f, 0.f, -(f + n) / (f - n), (2 * f * n) / (f - n),
			0.f, 0.f, 0.f, 1.f
		);
	}

	Matrix4 Matrix4::Translation(const Vector3& t) const
	{
		return Matrix4(
			1.f, 0.f, 0.f, t.x,
			0.f, 1.f, 0.f, t.y,
			0.f, 0.f, 1.f, t.z,
			0.f, 0.f, 0.f, 1.f
		);
	}

	Matrix4 Matrix4::Scale(const Vector3& s) const
	{
		return Matrix4(
			s.x, 0.f, 0.f, 0.f,
			0.f, s.y, 0.f, 0.f,
			0.f, 0.f, s.z, 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}
	Matrix4 Matrix4::Rotation(const float angle, const Vector3& axis) const
	{
		float r = ToRadians(angle);
		float c = cos(r);
		float s = sin(r);

		float o = 1 - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		return Matrix4(
			c + x * x * o, x * y * o - z * s, x * z * o + y * s, 0.f,
			y * x * o + z * s, c + y * y * o, y * z * o - x * s, 0.f,
			z * x * o - y * s, z * y * o + x * s, c + z * z * o, 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}

	Vector4 Matrix4::GetColumn(const unsigned int column)
	{
		if (column > 3)
			return Vector4::zero;

		float* offset = &m00 + column;

		return Vector4(
			*(offset),
			*(offset + 4),
			*(offset + 8),
			*(offset + 12)
			);
	}

	Vector4 Matrix4::GetRow(const unsigned int row)
	{
		if (row > 3)
			return Vector4::zero;

		float* offset = &m00 + (4 * row);
		return Vector4(
			*offset,
			*(offset + 1),
			*(offset + 2),
			*(offset + 3)
		);
	}
}
