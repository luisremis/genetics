#if !defined MOVER_H
#define MOVER_H

#include "ArbolRobot.h"
#include "Robot.h"

class Mover : public ArbolRobot
{

public:
	Mover(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	Mover(Mover& original);
	virtual ~Mover();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
