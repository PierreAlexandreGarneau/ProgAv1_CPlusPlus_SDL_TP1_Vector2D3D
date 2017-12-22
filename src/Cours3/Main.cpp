#include <iostream>
#include "Bishop.h"
#include "Rook.h"

#pragma region TEST HERITAGE
// A.h
class A
{
public:
	A();
	A(int i);
private:
	int i;
};

// A.cpp
A::A()
	: i(0)
{
	std::cout << "A::A()" << std::endl;
}
A::A(int i)
	: i(i)
{
	std::cout << "A::A(int i)" << std::endl;
}

// B.h
class B
	: public A
{
public:
	B();
};

// B.cpp
B::B()
	: A(5)
{
	std::cout << "B::B()" << std::endl;
}
#pragma endregion

void main()
{
	const int TAILLE = 4;
	Piece* pieces[TAILLE];

	pieces[0] = new Rook(Piece::WHITE);
	pieces[1] = new Rook(Piece::BLACK);
	pieces[2] = new Bishop(Piece::WHITE);
	pieces[3] = new Bishop(Piece::BLACK);

	pieces[0]->Test();

	for (int i = 0; i < TAILLE; i++)
		delete pieces[i];
}