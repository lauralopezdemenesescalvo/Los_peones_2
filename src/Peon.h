#pragma once
#include "Pieza.h"
#include "Vector2D.h"

class Peon : public Pieza {

	Sprite peon_b{ "imagenes/peonb.png" };
	Sprite peon_n{ "imagenes/peonn.png" };
public:
	virtual bool mov_posible(Vector2D, Vector2D);
	Peon(bool c) :Pieza(c) { PEON; }
	void dibuja(Vector2D);
};