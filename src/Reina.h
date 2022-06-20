#pragma once
#include "Pieza.h"
#include "Vector2D.h"

class Reina : public Pieza {

	Sprite reina_b{ "imagenes/reinab.png" };
	Sprite reina_n{ "imagenes/reinan.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D);
	Reina(bool c) :Pieza(c) { REINA; }
	
	void dibuja(Vector2D);
};