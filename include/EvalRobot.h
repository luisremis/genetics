#if !defined EVAL_ROBOT_H
#define EVAL_ROBOT_H

#include "Operador.h"
#include "Poblacion.h"
#include "CttesRobot.h"
#include "Individuo.h"
#include "Robot.h"
#include <vector>

class EvalRobot : public Operador
{
public:
	EvalRobot();
	virtual ~EvalRobot();
	Poblacion* operar(Poblacion* p);
        double completado(Mapa* mapa);
};
#endif
