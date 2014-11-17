#ifndef MUTACIONSHRINK_H
#define MUTACIONSHRINK_H

#include "Operador.h"
#include "ArbolBinario.h"

class MutacionShrink : public Operador
{
private:
	double porcentaje;
        Generador *g;
public:
	MutacionShrink(double porcentaje, Generador* generador);
	~MutacionShrink(void);
	Poblacion* operar(Poblacion *p);
        Generador* getG();
        void setG(Generador *generador);
};

#endif 