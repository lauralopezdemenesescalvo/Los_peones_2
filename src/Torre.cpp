#include "Torre.h"

bool Torre::mov_posible(Vector2D pos1, Vector2D pos2)
{
	if ((abs(pos2.getColumna() - pos1.getColumna()) == 0 && abs(pos2.getFila() - pos1.getFila()) != 0) || (abs(pos2.getColumna() - pos1.getColumna()) != 0 && abs(pos2.getFila() - pos1.getFila()) == 0))
		return true;
	else
		return false;
}
void Torre::dibuja(Vector2D p1)
{
	sprite_b = torre_b;
	sprite_n = torre_n;
	Pieza::dibuja(p1);
}
