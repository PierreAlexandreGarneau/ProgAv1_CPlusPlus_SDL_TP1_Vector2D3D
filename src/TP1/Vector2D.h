#pragma once

#include <math.h>

struct Vector2D {
	float x, y;
};

const float PI = 3.1415926535897f;
const double EPSILON = 0.0001;

// Vector 2D
Vector2D Add(const Vector2D* const left, const Vector2D* const right);
Vector2D Substract(const Vector2D* const left, const Vector2D* const right);
Vector2D Scale(const Vector2D* const vect, const float const scale);
void MoveBy(const Vector2D* const by, /*ES*/ Vector2D* const toMove);
float GetPolarAngleDeg(Vector2D* const vect);
float AngleBetweenDeg(Vector2D* const left, Vector2D* const right);
float Length(const Vector2D* const vect);
float LengthSq(const Vector2D* const vect);
bool Normalize(Vector2D* const vect);
void ScaleBy(Vector2D* const vect, const float const scale);
Vector2D GetVectorByAngleDeg(const float const angle);
bool Equals(const Vector2D* const  left, 
			const Vector2D* const right);