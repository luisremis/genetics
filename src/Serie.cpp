#include "Serie.h"

Serie::Serie(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="Serie";
}

Serie::Serie(Serie &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

Serie::~Serie(){

}

double Serie::interpret(vector<Parametro*>* parametros){
	// Primero interpreta su hijo izquierdo y luego su hijo derecho
	this->izq->interpret(parametros);
	this->der->interpret(parametros);
	return 0;
}

Prototype* Serie::copiar(){
	return new Serie(*this);
}