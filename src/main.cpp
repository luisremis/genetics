#include <iostream>
#include "CttesRobot.h"
#include "Constantes.h"
#include "Generador.h"
#include "Poblacion.h"
#include "FactoryRobot.h"
#include "EvalRobot.h"
#include "Individuo.h"
#include "GArbolRobot.h"

#include "Arquitectura.h"
#include "Genetico.h"
#include "SUS.h"
#include "Cruzamiento.h"
#include "Mutacion.h"
#include "SelElite.h"
#include "Estadisticas.h"

#include <vector>
using namespace std;

void inicializar(){
    // Generador para todo el algoritmo
    Generador *g = new Generador();
        
	// Generacion del mapa
    int filas=95, cols=95;
    double carga=20;
	Mapa *mapa= new Mapa(filas, cols, carga);
	CttesRobot::mapa=mapa;
    CttesRobot::pasos=4000;

	// Seteo del Factory
	Constantes::factory=new FactoryRobot();
    Constantes::gArbol=new GArbolRobot(g);
	
	// Carga de tablas
	// Funciones: S=Serie, P=Pasto adelante, O=Obstaculo adelante
	CttesRobot::tablaFunciones->agregarItem('S', 0.34);
	CttesRobot::tablaFunciones->agregarItem('P', 0.33);
	CttesRobot::tablaFunciones->agregarItem('O', 0.33);

	// Terminales: M=Mover, I=Girar Izquierda, D=Girar Derecha
	CttesRobot::tablaTerminales->agregarItem('M', 0.34);
	CttesRobot::tablaTerminales->agregarItem('I', 0.33);
	CttesRobot::tablaTerminales->agregarItem('D', 0.33);
        
    // Parametros del ArbolBinario
    ArbolBinario::ALTURA_MIN=3;
    ArbolBinario::ALTURA_MAX=4;

    // Parametros del Genetico
    Arquitectura *a = new Arquitectura(100, 100, 70, 30, 1);
    Genetico *genetico = Genetico::getGenetico();
    genetico->setGeneraciones(500);
    genetico->setArquitectura(a);
    genetico->setOEval(new EvalRobot());
    genetico->setOSel(new SUS(a->getPorcentajeSeleccion(), g));
    genetico->setOCross(new Cruzamiento(a->getPorcentajeCruzamiento(), 100, g));
    genetico->setOMut(new Mutacion(a->getPorcentajeMutacion(), g));
    genetico->setOElites(new SelElite(double(a->getPorcentajeElite())));
}

int main(){
	inicializar();
        
	Poblacion *p = new Poblacion();
    p->generar(10, "rampedHalfAndHalf", ArbolBinario::ALTURA_MIN, ArbolBinario::ALTURA_MAX);

    Genetico *genetico = Genetico::getGenetico();
    genetico->iniciar(p);

    Poblacion *final = genetico->getInitPop();
	genetico->getOEval()->operar(final);
	SelElite *mejor = new SelElite(1);
	Poblacion *mejorIndividuo = mejor->operar(final);
	mejorIndividuo->getIndividuos()->at(0)->mostrar();
	cout<<"Fitness: "<<mejorIndividuo->getIndividuos()->at(0)->getFitness()<<endl;
	
    CttesRobot::mapa->mostrar();

    vector<Parametro*> *parAux = new vector<Parametro*>();
    parAux->push_back(new Robot());
    Mapa *mapaFinal = new Mapa(*CttesRobot::mapa);
    //Mapa *mapaFinal = new Mapa(20,20,10);
    parAux->push_back(mapaFinal);
    for (unsigned int j=0; j<400; j++)
        mejorIndividuo->getIndividuos()->at(0)->getArbolBinario()->interpret(parAux);

    EvalRobot *eval = (EvalRobot*) genetico->getOEval();
    cout<<endl<<"Final: "<<eval->completado(mapaFinal)<<endl;
    mapaFinal->mostrar();

    //getchar();

    Estadisticas::getInstancia()->exportar();

	return 0;
}
