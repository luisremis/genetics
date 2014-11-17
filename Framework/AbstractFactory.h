#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H
#include "Individuo.h"
#include "ArbolBinario.h"

/*!Esta interface se utiliza para implementar el patron de diseño Abstract Factory. De esta forma, al implementar esta interface 
se provee un mecanismo para crear individuos y arboles desde el framework, y usarlos sin conocer realmente como estan implementados, 
siempre y cuando sean clases derivadas de Individuo o ArbolBinario respectivamente.*/
class AbstractFactory
{
public:
	/*!Constructor por defecto.*/
	AbstractFactory(void);
	/*!Destructor virtual.*/
	~AbstractFactory(void);
	/*!Esta funcion crea un individuo, se utiliza poliformicamente para crear individuos desconocidos por el Framework.
		/return Individuo nuevo.
	*/
	virtual Individuo* crearIndividuo()=0;
	/*!Esta funcion crea un arbol, se utiliza poliformicamente para crear arboles desconocidos por el Framework.
		/return ArbolBinario nuevo.
	*/
	virtual ArbolBinario* crearArbol()=0;
	
};

#endif