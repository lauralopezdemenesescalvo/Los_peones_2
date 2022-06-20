#include "Alfil.h"


bool Alfil::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Alfil::dibuja(Vector2D p1) {
	
	sprite_b = alfil_b;
	sprite_n = alfil_n;

	Pieza::dibuja(p1);
}