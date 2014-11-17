#ifndef CRUZAMIENTO_H
#define CRUZAMIENTO_H

#include "Operador.h"
#include "ArbolBinario.h"

class Cruzamiento : public Operador
{
private:
	double porcentaje;
        int iteracionesMaximas;
        Generador *g;
public:
	Cruzamiento(double porcentaje, int itMaximas, Generador *generador);
	~Cruzamiento(void);
	Poblacion* operar(Poblacion *p);
};

#endif