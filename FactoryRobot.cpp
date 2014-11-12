#include "FactoryRobot.h"


FactoryRobot::FactoryRobot(){

}

FactoryRobot::~FactoryRobot(){

}

Individuo* FactoryRobot::crearIndividuo(){
	return new IndRobot();
}

ArbolBinario* FactoryRobot::crearArbol(){
	return new ArbolRobot(NULL, NULL, NULL);
}