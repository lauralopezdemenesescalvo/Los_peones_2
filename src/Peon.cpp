#include "Peon.h"

bool Peon::mov_posible(Vector2D pos1, Vector2D pos2) //Las x son fila, falta tener en cuenta si es primer movimiento o no.
{
	if (/*pos1.getColumna() == 0 &&*/ ((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == 2))
		return true;
	else if (/*c == 1 &&*/ ((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == -2))
		return true;
	else
		return false;
}

void Peon::dibuja(Vector2D p1)
{
	sprite_b = peon_b;
	sprite_n = peon_n;
	Pieza::dibuja(p1);
}
