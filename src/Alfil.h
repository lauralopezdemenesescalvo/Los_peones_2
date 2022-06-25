#pragma once
#include "Pieza.h"
#include "Vector2D.h"


class Alfil : public Pieza {

	Sprite alfil_n{ "imagenes/alfiln.png" };
	Sprite alfil_b{ "imagenes/alfilb.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D,bool);
	Alfil(bool c) :Pieza(c) { ALFIL; }
	void dibuja(Vector2D);
	int getPieza();
		
};