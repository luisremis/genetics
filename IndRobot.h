#if !defined IND_ROBOT_H
#define IND_ROBOT_H

#include "ArbolRobot.h"
#include "FactoryRobot.h"
#include "Generador.h"

class IndRobot : public Individuo
{

public:
	IndRobot();
	IndRobot(IndRobot &original);
	virtual ~IndRobot();
	Prototype* copiar();
};
#endif
