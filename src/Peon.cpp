#include "Peon.h"


bool Peon::mov_posible(Vector2D pos1, Vector2D pos2, bool ocupado)
{
	if (ocupado==false) {//NO HAY PIEZA
		if (pos1.getColumna() == 1 || pos1.getColumna() == 6) {//está en pos inicial
			if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == 2))
				return true;
			else if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == -2))
				return true;
			else if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == 1))
				return true;
			else if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == -1))
				return true;
			else
				return false;
		}
		if (pos1.getColumna() != 1 && pos1.getColumna() != 6) {//NO está en pos inicial

			if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == 1))
				return true;
			else if (((pos2.getFila() - pos1.getFila()) == 0 && (pos2.getColumna() - pos1.getColumna()) == -1))
				return true;
			else
				return false;
		}
	}

	if (ocupado==true) { //HAY PIEZA
		if (((pos2.getFila() - pos1.getFila()) == -1 && (pos2.getColumna() - pos1.getColumna()) == 1))
			return true;
		else if (((pos2.getFila() - pos1.getFila()) == 1 && (pos2.getColumna() - pos1.getColumna()) == 1))
			return true;
		else
			return false;
	}
}

void Peon::dibuja(Vector2D p1)
{
	sprite_b = peon_b;
	sprite_n = peon_n;
	Pieza::dibuja(p1);
}

int Peon::getPieza()
{
	return 3;
}
