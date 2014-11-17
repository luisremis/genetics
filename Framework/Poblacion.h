/*
        Clase que agrupa un conjunto de individuos
 */

#if !defined POBLACION_H
#define POBLACION_H

#include "Individuo.h"
#include "Constantes.h"
#include "GArbol.h"
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

class Poblacion {
public:
    Poblacion();
    virtual ~Poblacion();

    vector<Individuo*> *getIndividuos();
    void setIndividuos(vector<Individuo*> *i);
    int getTam();
    void setTam(int tam);
    Poblacion* dividir(double porcentaje); // Retorna porcentaje de poblacion, quitandoselo a lo que queda (afecta la poblacion original)
    void unir(Poblacion*); // Operacion inversa a dividir
    void generar(int tam, string modo, int min, int max);
    void mostrar();
    void mostrarDOT(string nombrePob);
    void shuffle();

protected:
    vector<Individuo*> *individuos;
    int tam;

};
#endif 
