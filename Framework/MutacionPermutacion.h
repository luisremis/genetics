#ifndef MUTACIONPERMUTACION_H
#define MUTACIONPERMUTACION_H

#include "Operador.h"
#include "ArbolBinario.h"

class MutacionPermutacion : public Operador
{
private:
	double porcentaje;
        Generador *g;
public:
	MutacionPermutacion(double porcentaje, Generador* generador);
	~MutacionPermutacion(void);
	Poblacion* operar(Poblacion *p);
        Generador* getG();
        void setG(Generador *generador);
};

#endif 