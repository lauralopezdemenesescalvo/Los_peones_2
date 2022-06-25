#include "Tablero.h"

Tablero::Tablero()
{

	turno = 1; // empiezan las blancas

	pos_actual.SetFila(30);
	pos_actual.SetColumna(30);
	pos_siguiente.SetFila(20);
	pos_siguiente.SetColumna(20);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){
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
	//ILUMINAR CASILLA SELECCIONADA
	if (pos_actual.getFila() != 30) {
		glTranslatef(pos_actual.getFila(), pos_actual.getColumna(), -0.001);
		glBegin(GL_POLYGON);
		glColor3ub(255, 0, 0);

		glVertex3d(0.0f, 0.0f, 0.0001f);
		glVertex3d(1.0f, 0.0f, 0.0001f);
		glVertex3d(1.0f, 1.0f, 0.0001f);
		glVertex3d(0.0f, 1.0f, 0.0001f);

		glEnd();
		glTranslatef(-pos_actual.getFila(), -pos_actual.getColumna(), 0.001);
	}

}



void Tablero::gestion_click(Vector2D c)
{
	int estado;
	bool terminado=0;

	if (tablero[c.getFila()][c.getColumna()] == nullptr && pos_actual.getFila()==30 && pos_actual.getColumna()==30)  estado = 0;
	
	if (tablero[c.getFila()][c.getColumna()] != nullptr && tablero[c.getFila()][c.getColumna()]->getColor() != turno && pos_actual.getFila() == 30 && pos_actual.getColumna() == 30) estado = 1;

	if (tablero[c.getFila()][c.getColumna()] != nullptr && tablero[c.getFila()][c.getColumna()]->getColor() == turno && pos_actual.getFila() == 30 && pos_actual.getColumna() == 30) estado = 2;
	
	if (tablero[c.getFila()][c.getColumna()] != nullptr && tablero[c.getFila()][c.getColumna()]->getColor() == turno && pos_actual.getFila() != 30 && pos_actual.getColumna() != 30) estado = 3;
	
	if (tablero[c.getFila()][c.getColumna()] != nullptr && tablero[c.getFila()][c.getColumna()]->getColor() != turno && pos_actual.getFila() != 30 && pos_actual.getColumna() != 30) estado = 4;
	
	if (tablero[c.getFila()][c.getColumna()] == nullptr  && pos_actual.getFila() != 30 && pos_actual.getColumna() != 30) estado = 5;
	
	switch (estado) {

		// PRIMER CLICK
	case 0: // se ha seleccionado una casilla vacia-> no guarda
		break;
	case 1:  // se ha seleccionado una pieza que no toca ( toca blanca y haces click en negro)-> no guarda
		break; 
	case 2: // Se ha seleccionado una pieza -> guarda
		pos_actual = c;
		break;
		// SEGUNDO CLICK
	case 3: // Existe una poscion actual guardada y se ha seleccionado una pieza de su mismo color-> no guarda
		pos_actual.SetFila(30);
		pos_actual.SetColumna(30);
		break;
	case 4: // // Existe una poscion actual guardada y se ha seleccionado una pieza del otro color->COMER
		pos_siguiente = c;
		terminado = 1;
		break;

	case 5: // casilla vacia
		pos_siguiente = c;
		terminado = 1;
		break;
	}

	// Cuando se termina de almacenar los dos clicks y se han utilizado, ponemos posicion actual y siguiente a 30
	if (terminado == 1)
	{
		
		movimiento();
		

	}
}


bool Tablero::fin_mate()
{
	int numreyes=0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tablero[i][j] != nullptr) {
				if (tablero[i][j]->getPieza() == 5) {
					numreyes++;
				}
			}
		}
	}
	if (numreyes != 2) {
		return true;
	}
}

void Tablero::actualiza_tablero()
{
	bool fin=0;

	tablero[pos_siguiente.getFila()][pos_siguiente.getColumna()] = tablero[pos_actual.getFila()][pos_actual.getColumna()];
	tablero[pos_actual.getFila()][pos_actual.getColumna()] = NULL;
	fin = fin_mate();
	fin = pieza_trayectoria();
}

void Tablero::movimiento()
{
	bool res=false;
	bool ocupado=0;
	if (tablero[pos_siguiente.getFila()][pos_siguiente.getColumna()] == nullptr)
		ocupado = false;
	else ocupado = true;

	if (pos_actual.getFila() != 30 && pos_actual.getColumna() != 30 && pos_siguiente.getFila() != 20 && pos_siguiente.getColumna() != 20)
		res= tablero[pos_actual.getFila()][pos_actual.getColumna()]->mov_posible(pos_actual, pos_siguiente,ocupado);

	if (res == 1) {
		actualiza_tablero();		
		if (turno == 1) turno = 0;
		else turno = 1;
		pos_actual.SetFila(30);
		pos_actual.SetColumna(30);
		pos_siguiente.SetFila(20);
		pos_siguiente.SetColumna(20);

	}
	printf("res:%d", res);
}

