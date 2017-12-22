#include "Rectangle.h"



Rectangle::Rectangle(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_w = width;
	_h = height;
}

Rectangle::Rectangle(Vector2D* topLeft, Vector2D* btmRight) :
	Rectangle::Rectangle(topLeft->x, topLeft->y, btmRight->x - topLeft->x, topLeft->y - btmRight->y)
{
}

float Rectangle::GetX() const
{
	return _x;
}

//Retourne la position y du coin top left du rectangle
float Rectangle::GetY() const
{
	return _y;
}

//Retourne la largeur du rectangle
float Rectangle::GetWidth() const
{
	return _w;
}

//Retourne la hauteur du rectangle
float Rectangle::GetHeight() const
{
	return _h;
}

//Determine si le point est dans le rectangle
bool Rectangle::Contains(float x, float y) const
{
	return x >= _x && x <= _x + _w &&
		   y >= _y - _h && y <= _y;
}

//Determine si le point est dans le rectangle
bool Rectangle::Contains(Vector2D* point)
{
	return this->Contains(point->x, point->y);
}

//Definit le coin top left du rectangle
void Rectangle::SetPosition(float x, float y)
{
	_x = x;
	_y = y;
}

//Definit le coin top left du rectangle
void Rectangle::SetPosition(Vector2D* vect)
{
	this->SetPosition(vect->x, vect->y);
}

//Deplace le regtangle
void Rectangle::MoveBy(float x, float y)
{
	_x += x;
	_y += y;
}

//Deplace le regtangle
void Rectangle::MoveBy(Vector2D* vect)
{
	this->MoveBy(vect->x, vect->y);
}

//Pour la collision un des 4 coins d un des retangles doit etre contenu dans l autre
bool Rectangle::CollidesWith(Rectangle* rect) const
{
	return Contains(rect->_x, rect->_y) ||
			Contains(rect->_x + rect->_w, rect->_y) ||
			Contains(rect->_x, rect->_y - rect->_h) ||
			Contains(rect->_x + rect->_w, rect->_y - rect->_h);
}