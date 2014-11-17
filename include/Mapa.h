#ifndef MAPA_H
#define MAPA_H
#include "Parametro.h"
#include "Generador.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Mapa : public Parametro
{
private:
	vector<vector<int>*> *mapa;
public:
	Mapa(void);
	Mapa(int filas, int cols, int carga);
	Mapa(Mapa& original);
	virtual ~Mapa(void);
	void generar(int filas, int cols, double carga);
	vector<vector<int>*> *getMapa();
	vector<int>* operator[] (const int i);
        void mostrar();
};
#endif
