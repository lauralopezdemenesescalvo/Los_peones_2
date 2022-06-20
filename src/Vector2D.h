#pragma once
#include <iostream>

class Vector2D {

	int fila, columna;  // X FILA Y COLUMNA
public:
	Vector2D();
	Vector2D(int f, int c);
	int getFila();
	int getColumna();
	void SetFila(int x);
	void SetColumna(int y);
	
	friend bool operator == (const Vector2D& v1, const Vector2D& v2);
	friend bool operator != (const Vector2D& v1, const Vector2D& v2);

};

