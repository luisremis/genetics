#if !defined ROBOT_H
#define ROBOT_H

#include <string>
#include "Parametro.h"
#include "Mapa.h"
using namespace std;

class Robot : public Parametro
{

public:
	Robot();
	virtual ~Robot();

	void mover(Mapa *mapa);
	void girarI();
	void girarD();
	int getPosI();
	void setPosI(int i);
	int getPosJ();
	void setPosJ(int j);
	char getOrientacion();
	void setOrientacion(char oNueva);

private:
	char orientacion;
	int posI;
	int posJ;
};
#endif 
