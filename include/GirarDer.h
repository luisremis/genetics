#if !defined GIRAR_DER_H
#define GIRAR_DER_H

#include "ArbolRobot.h"
#include "Robot.h"

class GirarDer : public ArbolRobot
{

public:
	GirarDer(Nodo* v, ArbolBinario* i, ArbolBinario* d);
	GirarDer(GirarDer& original);
	virtual ~GirarDer();
	virtual double interpret(vector<Parametro*>*);
	Prototype *copiar();
};
#endif
