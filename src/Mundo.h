#pragma once
#include "Tablero.h"
#include "ETSIDI.h"

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

	Vector2D v_click={0,0};
	Vector2D click(int,int,int,int);
	Tablero tablero;
	
};
