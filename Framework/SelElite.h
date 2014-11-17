#ifndef SELELITE_H
#define	SELELITE_H

#include "Operador.h"
#include "Poblacion.h"

class SelElite : public Operador {
public:
    SelElite(double porcentaje);
	SelElite(int numero_fijo);
    SelElite(const SelElite& orig);
    virtual ~SelElite();
    double getPorcentajeElites();
    void setPorcentajeElites(double);
    Poblacion* operar(Poblacion*);
	Poblacion* reducir(Poblacion* p, double porcentaje, bool mejores);

private:
    double porcentajeElites;
	int fijo;

};

#endif	/* SELELITE_H */

