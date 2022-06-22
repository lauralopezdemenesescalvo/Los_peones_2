#include "Alfil.h"


bool Alfil::mov_posible(Vector2D pos1, Vector2D pos2)
{
	if (abs(pos2.getFila() - pos1.getFila()) == abs(pos2.getColumna() - pos1.getColumna()))
	return true;
	else
	return false;
}

void Alfil::dibuja(Vector2D p1) {
	
	sprite_b = alfil_b;
	sprite_n = alfil_n;

	Pieza::dibuja(p1);
}