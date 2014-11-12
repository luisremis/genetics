#if !defined OBSTACULO_ADELANTE_H
#define OBSTACULO_ADELANTE_H

#include "ArbolRobot.h"

class ObstaculoAdelante : public ArbolRobot
{

public:
	ObstaculoAdelante(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	ObstaculoAdelante(ObstaculoAdelante& original);
	virtual ~ObstaculoAdelante();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
