#if !defined GIRAR_IZQ_H
#define GIRAR_IZQ_H

#include "ArbolRobot.h"
#include "Robot.h"

class GirarIzq : public ArbolRobot
{

public:
	GirarIzq(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	GirarIzq(GirarIzq& original);
	virtual ~GirarIzq();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
