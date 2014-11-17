/*	Generador de numeros aleatorios para rangos preferidos (se pueden agregar funciones generadoras de numeros aleatorios)
*/
#ifndef GENERADOR_H
#define	GENERADOR_H

class Generador {
public:
    Generador();
    Generador(const Generador& orig);
    virtual ~Generador();
    double random();
	double random1d();
private:

};

#endif	/* GENERADOR_H */

