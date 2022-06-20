#include "Tablero.h"

Tablero::Tablero()
{

	turno = 1; // empiezan las blancas


	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = nullptr;
			
		}



	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			tablero[i][1] = new Peon(1);
			tablero[i][6] = new Peon(0);
		}
	//TORRES
	tablero[0][0] = new Torre(1);
	tablero[0][7] = new Torre(0);
	tablero[7][0] = new Torre(1);
	tablero[7][7] = new Torre(0);
	//ALFILES
	tablero[2][0] = new Alfil(1);
	tablero[5][0] = new Alfil(1);
	tablero[2][7] = new Alfil(0);
	tablero[5][7] = new Alfil(0);
	//CABALLO
	tablero[1][0] = new Caballo(1);
	tablero[6][0] = new Caballo(1);
	tablero[1][7] = new Caballo(0);
	tablero[6][7] = new Caballo(0);
	//REY
	tablero[4][0] = new Rey(1);
	tablero[4][7] = new Rey(0);
	//REINA
	tablero[3][0] = new Reina(1);
	tablero[3][7] = new Reina(0);
}
Tablero::~Tablero()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			delete[] tablero[i][j];
		}
	
}

void Tablero::dibuja(Pieza* pieza, bool iluminacion)
{

	int paridad;
	int i, j;
		for (i = 0; i < 8; i++) {	//cada i es una fila del tablero
			for (j = 0; j < 8; j++) { //cada j es una columna del tablero
				paridad = (i + j) % 2;
				if (paridad == 1)//BLANCO
				{
					glTranslatef(i,j, -0.001);
					glBegin(GL_POLYGON);
					glColor3ub(255, 255, 255);

					glVertex3d(0.0f, 0.0f, 0.0f);
					glVertex3d(1.0f, 0.0f, 0.0f);
					glVertex3d(1.0f, 1.0f, 0.0f);
					glVertex3d(0.0f, 1.0f, 0.0f);

					glEnd();
					glTranslatef(-i,-j, 0.001);

				}

				if (paridad == 0)//NEGRO
				{
					glTranslatef(i,j, -0.001);
					glBegin(GL_POLYGON);
					glColor3ub(141, 73, 37);

					glVertex3d(0.0f, 0.0f, 0.0f);
					glVertex3d(1.0f, 0.0f, 0.0f);
					glVertex3d(1.0f, 1.0f, 0.0f);
					glVertex3d(0.0f, 1.0f, 0.0f);

					glEnd();
					glTranslatef(-i,-j, 0.001);
				}
			}
		}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if(tablero[i][j]!=nullptr)
				tablero[i][j]->dibuja({i,j});
		}
	}
}


void Tablero::inicializa()
{

}


void Tablero::setTurno()
{
}

bool Tablero::fin_mate()
{
	return false;
}

