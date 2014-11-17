/*
	Operador de seleccion
*/
#if !defined SUS_H
#define SUS_H

#include "Operador.h"
#include "Poblacion.h"
#include "Individuo.h"
#include "Generador.h"
#include <vector>
#include <exception>
#include <limits>

class SUS : public Operador
{
private:
	double porcentaje;
        Generador *g;
public:
	SUS(double porcentaje, Generador *generador);
	virtual ~SUS();
	virtual Poblacion* operar(Poblacion* p);

};
#endif // SUS_H
