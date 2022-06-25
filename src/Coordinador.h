#pragma once
#include"Mundo.h"

class Coordinador
{
public:

	Mundo mundo1;
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void inicializa();

protected:
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER };
	Estado estado;
};