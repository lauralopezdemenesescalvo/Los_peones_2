#pragma once
#include "Tablero.h"


class Mundo
{
public: 
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	Tablero tablero;
	
};
