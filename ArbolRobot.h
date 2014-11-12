#if !defined ARBOL_ROBOT_H
#define ARBOL_ROBOT_H
#include "ArbolBinario.h"
#include "Nodo.h"
#include "Incrementador.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

class ArbolRobot : public ArbolBinario
{
protected:
	string className;

public:
	ArbolRobot(Nodo* valor, ArbolBinario* i, ArbolBinario* d);
	ArbolRobot(ArbolRobot &original);
	virtual ~ArbolRobot();
	virtual double interpret(vector<Parametro*>*);
	Prototype* copiar();
	virtual void mostrar();
	virtual string mostrar(ofstream *out, Incrementador* inc);
	string getClassName();
};
#endif
