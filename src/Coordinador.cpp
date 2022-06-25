#include "Coordinador.h"
#include <stdio.h>
#include "Vector2D.h"
#include "ETSIDI.h"


Coordinador::Coordinador()
{
	estado = INICIO;
}

Coordinador::~Coordinador()
{
}

void Coordinador::teclaEspecial(unsigned char key)
{

	if (estado == JUEGO)
		mundo1.tecla(key);
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			mundo1.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

void Coordinador::mueve()
{

	if (estado == JUEGO)
	{

		

		if (mundo1.tablero.fin_mate() == 1)
		{

			estado = GAMEOVER;
		}

	}
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/nuestrafuente.ttf", 30);
		ETSIDI::printxy("Ajedrez LosPeones_2", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/nuestrafuente.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Andres Perez Mora", 2, 1);
		ETSIDI::printxy("Guillermo Martin Lechuga", 2, 2);
		ETSIDI::printxy("Noelia Lopez Rua", 2, 4);
		ETSIDI::printxy("Laura Lopez De Meneses Calvo", 2, 3);
	}
	else if (estado == JUEGO)
	{
		mundo1.dibuja();
	}
	else if (estado == GAMEOVER)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		mundo1.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/nuestrafuente.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		mundo1.dibuja();
		ETSIDI::setFont("fuentes/nuestrafuente.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}
}

void Coordinador::inicializa()
{
	mundo1.inicializa();
}
