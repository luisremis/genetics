/*	Clase base de nodos (abstracta)
*/

#pragma once
#include <string>
#include "Prototype.h"
using namespace std;

class Nodo : public Prototype
{
public:
	Nodo(void);
	virtual ~Nodo(void);
	virtual char getTipo() = 0;
	virtual string toString()=0;
	virtual Prototype* copiar()=0;
};
