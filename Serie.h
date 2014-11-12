#if !defined SERIE_H
#define SERIE_H

#include "ArbolRobot.h"

class Serie : public ArbolRobot
{

public:
	Serie(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	Serie(Serie& original);
	virtual ~Serie();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
