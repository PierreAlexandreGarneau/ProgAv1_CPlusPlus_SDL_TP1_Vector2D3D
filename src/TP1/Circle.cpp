#include "Circle.h"

//Construie un cercle
Circle::Circle(float x, float y, float radius)
{
	_x = x;
	_y = y;
	_r = radius;
}

//Construie un cercle
Circle::Circle(Vector2D* center, float radius) :
	Circle::Circle(center->x, center->y, radius)
{
}

//Determine si le point est dans le cercle
bool Circle::Contains(float x, float y)
{
	float d = sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
	return d <= _r;
}

//Determine si le point est dans le cercle
bool Circle::Contains(Vector2D* point)
{
	return Contains(point->x, point->y);
}

//Retourne la position x du centre du cercle
float Circle::GetX()
{
	return _x;
}

//Retourne la position y du centre du cercle
float Circle::GetY()
{
	return _y;
}

//Retourne le rayon du cercle
float Circle::GetRadius()
{
	return _r;
}

//Definit le centre du cercle
void Circle::SetPosition(float x, float y)
{
	_x = x;
	_y = y;
}

void Circle::SetPosition(Vector2D* vect)
{
	SetPosition(vect->x, vect->y);
}

//Deplace le centre du cercle
void Circle::MoveBy(Vector2D* vect)
{
	MoveBy(vect->x, vect->y);
}

//Deplace le centre du cercle
void Circle::MoveBy(float x, float y)
{
	_x += x;
	_y += y;
}

//Pour la collision la distance entre les deux centres des cercles doit etre plus petite que la somme des radius
bool Circle::CollidesWith(Circle* circ)
{
	float d = sqrt((_x - circ->_x) * (_x - circ->_x) + (_y - circ->_y) * (_y - circ->_y));
	return d <= _r + circ->_r;
}