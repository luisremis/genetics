#ifndef CONSTANTES_H
#define CONSTANTES_H

#include "AbstractFactory.h"
#include "GArbol.h"
using namespace std;

/*!*/
class Constantes
{
public:
	Constantes(void);
	~Constantes(void);
	//static Tabla<char> *tablaFunciones;
	//static Tabla<string> *tablaVariables;
	//static Tabla<double> *tablaTerminales;
	static AbstractFactory *factory;
        static GArbol *gArbol;
};

#endif
