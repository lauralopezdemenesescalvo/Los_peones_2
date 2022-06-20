#include "Reina.h"

bool Reina::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Reina::dibuja(Vector2D p1)
{
	sprite_b = reina_b;
	sprite_n = reina_n;
	Pieza::dibuja(p1);
}
