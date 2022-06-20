#include "Vector2D.h"
#include <iostream>


bool operator == (const Vector2D& v1, const Vector2D& v2) {
	if (v1.fila== v2.fila && v1.columna == v2.columna)
		return true;
	else
		return false;
}

bool operator != (const Vector2D& v1, const Vector2D& v2) {
	if (v1.fila == v2.fila && v1.columna == v2.columna)
		return false;
	else
		return true;
}

Vector2D::Vector2D(int f, int c)
{
	fila = f;
	columna = c;
}

int Vector2D::getFila()
{
	return fila;
}

int Vector2D::getColumna()
{
	return columna;
}

void Vector2D::SetFila(int x)
{
	fila = x;
}

void Vector2D::SetColumna(int y)
{
	columna = y;
}


