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

int Pieza::getPieza()
{
	return 0;
}







