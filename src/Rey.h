#pragma once
#include "Pieza.h"
#include "Vector2D.h"

class Rey : public Pieza {

	Sprite rey_b{ "imagenes/reyb.png" };
	Sprite rey_n{ "imagenes/reyn.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D,bool);
	Rey(bool c) :Pieza(c) { REY; }
	
	void dibuja(Vector2D);
};
