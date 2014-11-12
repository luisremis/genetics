#include "GirarIzq.h"

GirarIzq::GirarIzq(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="GirarIzq";
}

GirarIzq::GirarIzq(GirarIzq &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

GirarIzq::~GirarIzq(){

}

double GirarIzq::interpret(vector<Parametro*>* parametros){
	Robot* robot = (Robot*) parametros->at(0);
	robot->girarI();
	return 0;
}

Prototype* GirarIzq::copiar(){
	return new GirarIzq(*this);
}