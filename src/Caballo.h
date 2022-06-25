#pragma once
#include "Pieza.h"
#include "Vector2D.h"

class Caballo : public Pieza {

	Sprite caballo_b{ "imagenes/caballob.png" };
	Sprite caballo_n{ "imagenes/caballon.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D,bool);
	Caballo(bool c) :Pieza(c) { CABALLO; }
	void dibuja(Vector2D);
};