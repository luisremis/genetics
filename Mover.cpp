#include "Mover.h"

Mover::Mover(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="Mover";
}

Mover::Mover(Mover &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

Mover::~Mover(){

}

double Mover::interpret(vector<Parametro*>* parametros){
	Robot* robot = (Robot*) parametros->at(0);
	Mapa* mapa = (Mapa*) parametros->at(1);
	robot->mover(mapa);
	return 0;
}

Prototype* Mover::copiar(){
	return new Mover(*this);
}