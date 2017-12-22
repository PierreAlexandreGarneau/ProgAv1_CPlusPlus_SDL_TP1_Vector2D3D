#include <math.h>
#include "Vector2D.h"

Vector2D Add(const Vector2D* const left, const Vector2D* const right)
{
	Vector2D v;
	v.x = left->x + right->x;
	v.y = left->y + right->y;
	return v;
}

Vector2D Substract(const Vector2D* const left, const Vector2D* const right)
{
	return Add(left, &Scale(right, -1));
}

Vector2D Scale(const Vector2D* const vect, const float const scale)
{
	Vector2D v;
	v.x = vect->x * scale;
	v.y = vect->y * scale;
	return v;
}

void MoveBy(const Vector2D* const by, Vector2D* const toMove)
{
	*toMove = Add(by, toMove);
}

float GetPolarAngleDeg(Vector2D* const vect)
{
	float angleDeg = 0.f;
	if (Normalize(vect))
	{
		float angleRad = acos(vect->x);
		angleDeg = angleRad * 180 / PI;
	}
	return angleDeg;
}

float AngleBetweenDeg(Vector2D* const left, Vector2D* const right)
{
	float angleLeft = GetPolarAngleDeg(left);
	float angleRight = GetPolarAngleDeg(right);
	float angle = angleLeft - angleRight;
	if (angle < 0)
		angle *= -1;
	return angle;
}

float Length(const Vector2D* const vect)
{
	return sqrt(LengthSq(vect));
}

float LengthSq(const Vector2D* const vect)
{
	return vect->x * vect->x + vect->y * vect->y;
}

bool Normalize(Vector2D* const vect)
{
	float len = Length(vect);
	if (len == 0)
		return false;
	vect->x = vect->x / len;
	vect->y = vect->y / len;
	return true;
}

void ScaleBy(Vector2D* const vect, const float const scale)
{
	*vect = Scale(vect, scale);
}

Vector2D GetVectorByAngleDeg(const float const angle)
{
	float angleRad = angle * PI / 180;
	Vector2D v;
	v.x = cosf(angleRad);
	v.y = sinf(angleRad);
	return v;
}

bool Equals(const Vector2D* const  left, 
			const Vector2D* const right)
{
	return fabs(left->x - right->x) < EPSILON 
		&& fabs(left->y - right->y) < EPSILON;
}
