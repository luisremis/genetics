#if !defined FACTORY_ROBOT_H
#define FACTORY_ROBOT_H

#include "AbstractFactory.h"
#include "IndRobot.h"
#include "ArbolRobot.h"

class FactoryRobot : public AbstractFactory
{

public:
	FactoryRobot();
	virtual ~FactoryRobot();

	Individuo* crearIndividuo();
	ArbolBinario* crearArbol();

};
#endif
