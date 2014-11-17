#include "ObstaculoAdelante.h"
#include "Robot.h"
#include "CttesRobot.h"

ObstaculoAdelante::ObstaculoAdelante(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="ObstaculoAdelante";
}

ObstaculoAdelante::ObstaculoAdelante(ObstaculoAdelante &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

ObstaculoAdelante::~ObstaculoAdelante(){

}

double ObstaculoAdelante::interpret(vector<Parametro*>* parametros){
	Robot* robot = (Robot*) parametros->at(0);
	Mapa* mapa = (Mapa*) parametros->at(1);
	char orientacion=robot->getOrientacion();
	int iAux, jAux;
	switch (orientacion){
		case 'E':
			iAux=robot->getPosI();
			jAux=robot->getPosJ();
			if (jAux+1>mapa->getMapa()->at(0)->size()-1) jAux=0;
			break;
		case 'N':
			iAux=robot->getPosI();
			jAux=robot->getPosJ();
			if (iAux-1<0) iAux=mapa->getMapa()->size()-1;
		case 'O':
			iAux=robot->getPosI();
			jAux=robot->getPosJ();
			if (jAux-1<0) jAux=mapa->getMapa()->at(0)->size()-1;
			break;
		case 'S':
			iAux=robot->getPosI();
			jAux=robot->getPosJ();
			if (iAux>mapa->getMapa()->size()-1) iAux=0;
			break;
	}
	// Si hay un obstaculo adelante interpreta su hijo izquierdo, sino su hijo derecho
	if (mapa->getMapa()->at(iAux)->at(jAux)==1) this->izq->interpret(parametros);
	else this->der->interpret(parametros);
	return 0;
}

Prototype* ObstaculoAdelante::copiar(){
	return new ObstaculoAdelante(*this);
}