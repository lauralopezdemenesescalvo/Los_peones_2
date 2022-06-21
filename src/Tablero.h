#pragma once
#include "Vector2D.h"
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"
#include "Caballo.h"
#include "Reina.h"


class Tablero {
public:
	Tablero();
	virtual~Tablero();
	bool turno;
	void dibuja(Pieza* pieza, bool iluminacion);
	void inicializa();

	Pieza* tablero[8][8];
	void gestion_click(Vector2D);
	void setTurno();
	bool fin_mate();

	Vector2D pos_actual, pos_siguiente;

};