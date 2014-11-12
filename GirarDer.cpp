#include "GirarDer.h"

GirarDer::GirarDer(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="GirarDer";
}

GirarDer::GirarDer(GirarDer &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

GirarDer::~GirarDer(){

}

double GirarDer::interpret(vector<Parametro*>* parametros){
	Robot* robot = (Robot*) parametros->at(0);
	robot->girarD();
	return 0;
}

Prototype* GirarDer::copiar(){
	return new GirarDer(*this);
}