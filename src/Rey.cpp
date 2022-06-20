#include "Rey.h"

bool Rey::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Rey::dibuja(Vector2D p1)
{
	sprite_b = rey_b;
	sprite_n = rey_n;
	Pieza::dibuja(p1);
}
