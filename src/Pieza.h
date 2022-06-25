#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Pieza {
protected:
	enum tipo {ALFIL=1, CABALLO, PEON, REINA, REY, TORRE};
	bool color=1;  // 1 blanco 0 negro
	
public:
	Pieza(bool);
	Sprite sprite_b{ "imagenes/alfilb.png" };
	Sprite sprite_n{ "imagenes/alfiln.png" };

	bool getColor();
	virtual bool mov_posible(Vector2D, Vector2D,bool);
	virtual void dibuja(Vector2D);
	virtual int getPieza();
	
};

