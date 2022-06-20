#pragma once
#include "Pieza.h"
#include "Vector2D.h"

class Torre : public Pieza {

	Sprite torre_b{ "imagenes/torreb.png" };
	Sprite torre_n{ "imagenes/torren.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D);
	Torre(bool c) :Pieza(c) { TORRE; }
	void dibuja(Vector2D);
};
