#if !defined GENETICO_H
#define GENETICO_H

#include "Operador.h"
#include "Poblacion.h"
#include "Arquitectura.h"
#include "Generador.h"
#include "SelElite.h"
#include <vector>
#include <sstream>
#include <ctime>

class Genetico
{

public:
    static Generador *randomGen;
	static double mejorFitness;

    static Genetico* getGenetico();
	virtual ~Genetico();
	
	int getGeneraciones();
	void setGeneraciones(int g);
	Poblacion* getInitPop();
	void setInitPop(Poblacion* p);
	Poblacion* getEvalPop();
	void setEvalPop(Poblacion* p);
	Poblacion* getSelPop();
	void setSelPop(Poblacion* p);
	Poblacion* getCrossPop();
	void setCrossPop(Poblacion* p);
	Poblacion* getMutPop();
	void setMutPop(Poblacion* p);
    Poblacion* getElitePop();
	void setElitePop(Poblacion* p);
	Operador* getOEval();
	void setOEval(Operador* o);
	Operador* getOSel();
	void setOSel(Operador* o);
	Operador* getOCross();
	void setOCross(Operador* o);
	Operador* getOMut();
	void setOMut(Operador* o);
    Operador* getOElites();
	void setOElites(Operador* o);
    Arquitectura* getArquitectura();
    void setArquitectura(Arquitectura*);
	string iniciar(Poblacion*);
	int getPopSize();
	void setPopSize(int p);
	void unaGeneracion();
	void reset();
	void configurar();
	Individuo* getMejorInd();

private:
	int generaciones;
	int popSize;
	Poblacion* initPop;
	Poblacion* evalPop;
	Poblacion* selPop;
	Poblacion* crossPop;
	Poblacion* mutPop;
    Poblacion* elitePop;
	Operador* oEval;
	Operador* oSel;
	Operador* oCross;
	Operador* oMut;
    Operador* oElites;
	Arquitectura* a;
	static Genetico* instancia;
	Genetico();
	Individuo *mejorInd;

};
#endif // !defined GENETICO_H
