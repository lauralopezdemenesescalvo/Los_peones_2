#include "Torre.h"

bool Torre::mov_posible(Vector2D, Vector2D)
{
	return false;
}

void Torre::dibuja(Vector2D p1)
{
	sprite_b = torre_b;
	sprite_n = torre_n;
	Pieza::dibuja(p1);
}
