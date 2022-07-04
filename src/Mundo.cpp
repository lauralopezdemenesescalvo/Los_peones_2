#include "Mundo.h"
#include "freeglut.h"
#include <math.h>



void Mundo::dibuja()
{

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4, 4, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	tablero.dibuja(NULL,false);
	
}

Vector2D Mundo::click(int button, int state, int x, int y)
{
	float v_fila=0, v_columna=0;
	int i = 186;
	int j = 84;
	float colum = 0;
	float fila = 7;
	float fila_aux, columna_aux;
	Vector2D res={0,0};

	for (fila = 7; fila >= 0; fila--)
	{
		if (y >= j && y <= j + 55) {
			v_fila = fila;
			printf("fila %0.2f \n ", v_fila);
			fila_aux = v_fila;
		}
		j += 55;
	}

	for (colum = 0; colum < 8; colum++)
	{
		if (x >= i && x <= i + 55) {
			v_columna = colum;
			printf("columna %0.2f\n", v_columna);
			columna_aux = v_columna;
		}
		i += 55;
	}
		res.SetFila(int(v_columna));
		res.SetColumna(int(v_fila));


		return res;
	}


void Mundo::mueve()
{
	
}

void Mundo::inicializa()
{

ETSIDI::play("sonidos/musica.wav");

	x_ojo=4;
	y_ojo=4;
	z_ojo=15;
}

void Mundo::tecla(unsigned char key)
{

}
