#pragma once

#include <math.h>

struct Vector3D {
	float x, y, z;
};

const float PI_3D = 3.1415926535897f;
const double EPSILON_3D = 0.0001;

// Vector 3D
Vector3D Add(const Vector3D* const left, const Vector3D* const right);
Vector3D Substract(const Vector3D* const left, const Vector3D* const right);
Vector3D Scale(const Vector3D* const vect,const float const scale);
float Dot(const Vector3D* const left, const Vector3D* const right);
Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right);
Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right);
void MoveBy(const Vector3D* const by, /*ES*/ Vector3D* const toMove);
float Length(const Vector3D* const vect);
float LengthSq(const Vector3D* const vect);
bool Normalize(Vector3D* const vect);
void ScaleBy(Vector3D* const vect, const float const scale);
bool Equals(const Vector3D* const  left,
			const Vector3D* const right);