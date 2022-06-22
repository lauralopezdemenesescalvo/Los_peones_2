#include "Caballo.h"

bool Caballo::mov_posible(Vector2D pos1, Vector2D pos2)
{
	if ((abs(pos2.getColumna() - pos1.getColumna()) == 2 && abs(pos2.getFila() - pos1.getFila()) == 1) || (abs(pos2.getColumna() - pos1.getColumna()) == 1 && abs(pos2.getFila() - pos1.getFila()) == 2))
		return true;
	else
		return false;
}

void Caballo::dibuja(Vector2D p1)
{
	sprite_b = caballo_b;
	sprite_n = caballo_n;

	Pieza::dibuja(p1);
}
