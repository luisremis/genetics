/*	
	Clase base para los operadores (clase abstracta). Obliga a la definicion de la funcion operar
*/
#if !defined OPERADOR_H
#define OPERADOR_H

#include <iostream>
#include "Poblacion.h"
using namespace std;

class Operador
{

public:
	Operador();
	virtual ~Operador();
	virtual Poblacion* operar(Poblacion* p)=0;
};
#endif 
