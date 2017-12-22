#pragma once
#include "Vector2D.h"

class Rectangle
{
private:
	//Coordonnee du coin top left du rectangle
	float _x;
	float _y;
	//Largeur
	float _w;
	//Hauteur
	float _h;

public:
	Rectangle(float x, float y, float width, float height);
	Rectangle(Vector2D* topLeft, Vector2D* btmRight);
	bool Contains(float x, float y) const;
	bool Contains(Vector2D* point);
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	void SetPosition(Vector2D* vect);
	void SetPosition(float x, float y);
	void MoveBy(Vector2D* vect);
	void MoveBy(float x, float y);
	bool CollidesWith(Rectangle* rect) const;
};

