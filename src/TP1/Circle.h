#pragma once
#include "Vector2D.h"

class Circle
{
private:
	//Coordonnees du centre du cercle
	float _x;
	float _y;
	//Rayon du cercle
	float _r;

public:
	Circle(float x, float y, float radius);
	Circle(Vector2D* center, float radius);
	bool Contains(float x, float y);
	bool Contains(Vector2D* point);
	float GetX();
	float GetY();
	float GetRadiusSq();
	float GetRadius();
	void SetPosition(Vector2D* vect);
	void SetPosition(float x, float y);
	void MoveBy(Vector2D* vect);
	void MoveBy(float x, float y);
	bool CollidesWith(Circle* circ);
};

