#if !defined PASO_ADELANTE_H
#define PASO_ADELANTE_H

#include "ArbolRobot.h"

class PastoAdelante : public ArbolRobot
{

public:
	PastoAdelante(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	PastoAdelante(PastoAdelante& original);
	virtual ~PastoAdelante();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
