#include "EvalRobot.h"
//#include "Estadisticas.h"

EvalRobot::EvalRobot(){

}

EvalRobot::~EvalRobot(){

}

Poblacion* EvalRobot::operar(Poblacion* p){
	vector<Individuo*>* inds = p->getIndividuos();
        double fitness;
        //Estadisticas *estadisticas = Estadisticas::getInstancia();
	for (unsigned int i=0; i<inds->size(); i++){
		// Instancio un robot y un mapa para usarlos de parametros
                try{
		Robot* robot = new Robot();
		Mapa* mapa = new Mapa(*CttesRobot::mapa);
		vector<Parametro*> *parametros = new vector<Parametro*>();
		parametros->push_back(robot);
		parametros->push_back(mapa);
		// Llamo a interpret una cantidad de veces determinada por CttesRobot::pasos de cada individuo con estos parametros
		for (unsigned int j=0; j<CttesRobot::pasos; j++)
                    inds->at(i)->getArbolBinario()->interpret(parametros);
                fitness=this->completado(mapa);
		inds->at(i)->setFitness(fitness);
                //estadisticas->compararMejor(fitness);
                //estadisticas->agregarAvg(fitness);
                int tam=parametros->size();
                for (unsigned int k=0; k<tam; k++)
                    delete parametros->at(k);
                delete parametros;
                } catch (...){
                    cout<<"Error en el individuo "<< i << endl;
                }
	}
    //estadisticas->nuevaGeneracion();
	return p;
}

double EvalRobot::completado(Mapa *mapa){
	double cantidad=0;
        int obstaculos=0;
        int filas = mapa->getMapa()->size();
        int columnas = mapa->getMapa()->at(0)->size();
	for(unsigned int i=0; i<filas; i++){
		for(unsigned int j=0; j<columnas; j++){
			if (mapa->getMapa()->at(i)->at(j)==2) cantidad=cantidad+1;
                        if (mapa->getMapa()->at(i)->at(j)==1) obstaculos=obstaculos+1;
		}
	}
	return cantidad/(filas*columnas-obstaculos);
}