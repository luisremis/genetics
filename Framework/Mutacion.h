#ifndef MUTACION_H
#define MUTACION_H

#include "Operador.h"
#include "ArbolBinario.h"

class Mutacion : public Operador
{
private:
	double porcentaje;
        Generador *g;
public:
	Mutacion(double porcentaje, Generador* generador);
	~Mutacion(void);
	Poblacion* operar(Poblacion *p);
        Generador* getG();
        void setG(Generador *generador);
};

#endif 