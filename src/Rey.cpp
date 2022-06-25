#include "Rey.h"

bool Rey::mov_posible(Vector2D pos1, Vector2D pos2, bool ocupado)
{
	if (abs(pos2.getFila() - pos1.getFila()) ==0 && abs(pos2.getColumna() - pos1.getColumna()) == 1)
		return true;
	else if ((abs(pos2.getColumna() - pos1.getColumna()) == 0 && abs(pos2.getFila() - pos1.getFila()) == 1) || (abs(pos2.getColumna() - pos1.getColumna()) == 1 && abs(pos2.getFila() - pos1.getFila()) == 0))
		return true;
	else
		return false;
}

void Rey::dibuja(Vector2D p1)
{
	sprite_b = rey_b;
	sprite_n = rey_n;
	Pieza::dibuja(p1);
}

int Rey::getPieza()
{
	return 5;
}
