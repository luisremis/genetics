#include "CttesRobot.h"

Mapa *CttesRobot::mapa=new Mapa();
Tabla<char> *CttesRobot::tablaFunciones = new Tabla<char>();
Tabla<char> *CttesRobot::tablaTerminales = new Tabla<char>();
int CttesRobot::pasos;

CttesRobot::CttesRobot(){
}

CttesRobot::~CttesRobot(){

}
