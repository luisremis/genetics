#if !defined INDIVIDUO_H
#define INDIVIDUO_H

#include "Generador.h"
#include "ArbolBinario.h"
#include "Incrementador.h"
#include <vector>
using namespace std;

class Individuo : public Prototype {
public:
    Individuo();
    Individuo(Individuo &original);
    virtual ~Individuo();

    void setArbolBinario(ArbolBinario*);
    ArbolBinario* getArbolBinario();
    double getFitness();
    void setFitness(double);
    double getProbabilidad();
    void setProbabilidad(double);
    double getAcumulada();
    void setAcumulada(double);
    virtual void mostrar(); // optativa
    virtual void mostrar(ofstream *out, Incrementador *inc); // optativa
    virtual Prototype* copiar();

protected:
    ArbolBinario *ab;
    double valorFitness;
    double probabilidad;
    double acumulada;

};
#endif
