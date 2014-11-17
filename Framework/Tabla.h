#ifndef TABLA_H
#define TABLA_H

#include "ItemTabla.h"
#include <vector>
#include <iostream>
using namespace std;

template <class T> class Tabla
{
private:
	vector<ItemTabla<T>*> *tabla;
public:
	Tabla(void);
	~Tabla(void);
	T getRandom(double random);
	void agregarItem(T item, double probabilidad);
};

template <class T>
Tabla<T>::Tabla(void)
{
	this->tabla = new vector<ItemTabla<T>*>();
}

template <class T> 
Tabla<T>::~Tabla(void)
{
}

template <class T>
void Tabla<T>::agregarItem(T item, double probabilidad){
	double aux;
	if (tabla->size()==0){
		tabla->push_back(new ItemTabla<T>(new T(item), probabilidad, probabilidad));
	} else {
		aux = tabla->at(tabla->size()-1)->getAcumulada();
		tabla->push_back(new ItemTabla<T>(new T(item), probabilidad, aux+probabilidad));
	}
}

template <class T>
T Tabla<T>::getRandom(double random){
	for (unsigned int i=0; i<tabla->size(); i++){
		if (random<=tabla->at(i)->getAcumulada()){
			return *(new T(*(tabla->at(i)->getItem())));
		}
	}
}


#endif