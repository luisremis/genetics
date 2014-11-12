#include "PastoAdelante.h"
#include "Robot.h"
#include "CttesRobot.h"

PastoAdelante::PastoAdelante(Nodo* v, ArbolBinario* i, ArbolBinario* d):ArbolRobot(v,i,d){
	className="PastoAdelante";
}

PastoAdelante::PastoAdelante(PastoAdelante &abCopia):ArbolRobot(abCopia){
	this->className=abCopia.className;
}

PastoAdelante::~PastoAdelante(){

}

double PastoAdelante::interpret(vector<Parametro*>* parametros){
	Robot* robot = (Robot*) parametros->at(0);
	Mapa* mapa = (Mapa*) parametros->at(1);
	char orientacion=robot->getOrientacion();
	int iAux, jAux;
        iAux=robot->getPosI();
        jAux=robot->getPosJ();
	
        switch (orientacion){
		case 'E':
			if (jAux+1>mapa->getMapa()->at(0)->size()-1) jAux=0;
                        else jAux++;
			break;
		case 'N':
			if (iAux-1<0) iAux=mapa->getMapa()->size()-1;
                        else iAux--;
                        break;
		case 'O':
			if (jAux-1<0) jAux=mapa->getMapa()->at(0)->size()-1;
                        else jAux--;
			break;
		case 'S':
			if (iAux+1>mapa->getMapa()->size()-1) iAux=0;
                        else iAux++;
			break;
	}
	// Si hay un obstaculo adelante interpreta su hijo izquierdo, sino su hijo derecho
	if (mapa->getMapa()->at(iAux)->at(jAux)==0) this->izq->interpret(parametros);
	else this->der->interpret(parametros);
	return 0;
}

Prototype* PastoAdelante::copiar(){
	return new PastoAdelante(*this);
}