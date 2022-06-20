#include "Caballo.h"

bool Caballo::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Caballo::dibuja(Vector2D p1)
{
	sprite_b = caballo_b;
	sprite_n = caballo_n;

	Pieza::dibuja(p1);
}
