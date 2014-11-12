#include "IndRobot.h"

IndRobot::IndRobot(){
	FactoryRobot *fr = new FactoryRobot();
	ab = fr->crearArbol();
	valorFitness = 0;
        probabilidad = 0;
	acumulada = 0;
	delete fr;
}

IndRobot::IndRobot(IndRobot &original){
	if (original.ab!=NULL) this->ab = (ArbolBinario*)original.ab->copiar();
	else this->ab=NULL;
	valorFitness = original.valorFitness;
	probabilidad = original.probabilidad;
	acumulada = original.acumulada;
}

IndRobot::~IndRobot(){
	delete ab;
}

Prototype *IndRobot::copiar(){
	return new IndRobot(*this);
}
