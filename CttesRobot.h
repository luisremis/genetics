#if !defined CTTES_ROBOT_H
#define CTTES_ROBOT_H

#include <vector>
#include "Tabla.h"
#include "Mapa.h"
using namespace std;

class CttesRobot
{

public:
	CttesRobot();
	virtual ~CttesRobot();
	static Mapa *mapa;
	static Tabla<char> *tablaFunciones;
	static Tabla<char> *tablaTerminales;
	static int pasos;
};
#endif
