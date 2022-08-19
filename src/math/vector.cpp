#pragma once
#include "vector.h"

namespace Nata
{
	const Vector2 Vector2::zero(0.f, 0.f);
	const Vector2 Vector2::one(1.f, 1.f);
	const Vector2 Vector2::right(1.f, 0.f);
	const Vector2 Vector2::up(0.f, 1.f);

	const Vector3 Vector3::zero(0.f, 0.f, 0.f);
	const Vector3 Vector3::one(1.f, 1.f, 1.f);
	const Vector3 Vector3::right(1.f, 0.f, 0.f);
	const Vector3 Vector3::forward(0.f, 1.f, 0.f);
	const Vector3 Vector3::up(0.f, 1.f, 0.f);

	const Vector4 Vector4::zero(0.f, 0.f, 0.f, 0.f);
	const Vector4 Vector4::one(1.f, 1.f, 1.f, 1.f);
}
