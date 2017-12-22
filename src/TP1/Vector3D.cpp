#include <math.h>
#include "Vector3D.h"

Vector3D Add(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D v;
	v.x = left->x + right->x;
	v.y = left->y + right->y;
	v.z = left->z + right->z;
	return v;
}

Vector3D Substract(const Vector3D* const left, const Vector3D* const right)
{
	return Add(left, &Scale(right, -1));
}

Vector3D Scale(const Vector3D* const vect, const float const scale)
{
	Vector3D v;
	v.x = vect->x * scale;
	v.y = vect->y * scale;
	v.z = vect->z * scale;
	return v;
}

float Dot(const Vector3D* const left, const Vector3D* const right)
{
	return left->x * right->x + left->y * right->y + left->z * right->z;
}

Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D v;
	v.x = right->y * left->z - right->z * left->y;
	v.y = right->z * left->x - right->x * left->z;
	v.z = right->x * left->y - right->y * left->x;
	return v;
}

Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D v = CrossLH(left, right);
	return Scale(&v, -1);
}

void MoveBy(const Vector3D* const by, Vector3D* const toMove)
{
	*toMove = Add(by, toMove);
}

float Length(const Vector3D* const vect)
{
	return sqrt(LengthSq(vect));
}

float LengthSq(const Vector3D* const vect)
{
	return vect->x * vect->x + vect->y * vect->y + vect->z * vect->z;
}

bool Normalize(Vector3D* const vect)
{
	float len = Length(vect);
	if (len == 0)
		return false;
	vect->x = vect->x / len;
	vect->y = vect->y / len;
	vect->z = vect->z / len;
	return true;
}

void ScaleBy(Vector3D* const vect, const float const scale)
{
	*vect = Scale(vect, scale);
}

bool Equals(const Vector3D* const  left,
			const Vector3D* const right)
{
	return fabs(left->x - right->x) < EPSILON_3D
		&& fabs(left->y - right->y) < EPSILON_3D
		&& fabs(left->z - right->z) < EPSILON_3D;
}