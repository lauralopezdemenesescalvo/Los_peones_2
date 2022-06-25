#include "Reina.h"


bool Reina::mov_posible(Vector2D pos1, Vector2D pos2, bool ocupado)
{
	if (abs(pos2.getFila() - pos1.getFila()) == abs(pos2.getColumna() - pos1.getColumna())) // movimiento en diagonal
		return true;

	else if ((abs(pos2.getColumna() - pos1.getColumna()) == 0 && abs(pos2.getFila() - pos1.getFila()) != 0) || (abs(pos2.getColumna() - pos1.getColumna()) != 0 && abs(pos2.getFila() - pos1.getFila()) == 0))
		return true;
	else
		return false;
}

void Reina::dibuja(Vector2D p1)
{
	sprite_b = reina_b;
	sprite_n = reina_n;
	Pieza::dibuja(p1);
}
