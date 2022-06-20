#include "Peon.h"

bool Peon::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Peon::dibuja(Vector2D p1)
{
	sprite_b = peon_b;
	sprite_n = peon_n;
	Pieza::dibuja(p1);
}
