#ifndef MUTACIONHOIST_H
#define MUTACIONHOIST_H

#include "Operador.h"
#include "ArbolBinario.h"

class MutacionHoist : public Operador
{
private:
	double porcentaje;
        Generador *g;
public:
	MutacionHoist(double porcentaje, Generador* generador);
	~MutacionHoist(void);
	Poblacion* operar(Poblacion *p);
        Generador* getG();
        void setG(Generador *generador);
};

#endif 