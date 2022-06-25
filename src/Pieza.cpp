#include "Pieza.h"

Pieza::Pieza(bool c)
{
	
	color = c;
}

bool Pieza::getColor()
{

	return color;
}

bool Pieza::mov_posible(Vector2D, Vector2D, bool)
{
	return false;
}




void Pieza::dibuja(Vector2D p1) {

	if (color == true) {
		sprite_b.setCenter(-p1.getFila(), -p1.getColumna());
		sprite_b.setSize(1, 1);
		sprite_b.draw();
	}
	else {
		sprite_n.setCenter(-p1.getFila(), -p1.getColumna());
		sprite_n.setSize(1, 1);
		sprite_n.draw();
		}
}

int Pieza::getTipo()
{ 
	if (ALFIL)
		return 1;
	if (CABALLO)
		return 2;
	if (PEON)
		return 3;
	if (REINA)
		return 4;
	if (REY)
		return 5;
	if (TORRE)
		return 6;
	else
		return 0;
}



