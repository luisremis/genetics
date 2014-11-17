#include "Mapa.h"

Mapa::Mapa(void)
{
	this->mapa=new vector<vector<int>*>();
}

Mapa::Mapa(int filas, int cols, int carga)
{
	this->mapa=NULL;
	this->generar(filas, cols, carga);
}

Mapa::Mapa(Mapa& original){
	this->mapa=new vector<vector<int>*>();
	for (unsigned int i=0; i<original.mapa->size(); i++){
		this->mapa->push_back(new vector<int>());
		for (unsigned int j=0; j<original.mapa->at(i)->size(); j++){
			this->mapa->at(i)->push_back(original.mapa->at(i)->at(j));
		}
	}
}

Mapa::~Mapa(void){
    for (unsigned int i=0; i<mapa->size(); i++){
        delete mapa->at(i);
    }
    delete mapa;
}

void Mapa::generar(int filas, int columnas, double carga){
	vector<vector<int>*> *resultado = new vector<vector<int>*>();
	Generador *g = new Generador();
	int obstaculos = floor((carga/100)*filas*columnas);
	int puestos=0;
	for(unsigned int i=0; i<filas; i++){
		resultado->push_back(new vector<int>());
		for(unsigned int j=0; j<columnas; j++){
			double prob = g->random();
			if (prob<carga/100 && puestos<obstaculos){
				resultado->at(i)->push_back(1);
				puestos++;
			} else {
				resultado->at(i)->push_back(0);
			}
		}
	}
	delete g;
	if (this->mapa!=NULL){
		for (unsigned int y=0; y<this->mapa->size(); y++){
			this->mapa->at(y)->erase(mapa->at(y)->begin(), mapa->at(y)->end());
			delete this->mapa->at(y);
		}
		delete this->mapa;
	}
	this->mapa=resultado;
}


vector<vector<int>*> *Mapa::getMapa(){
	return this->mapa;
}

vector<int>* Mapa::operator [](int i){
	return this->mapa->at(i);
}

void Mapa::mostrar(){
    int filas = mapa->size();
    int columnas = mapa->at(0)->size();
    for (unsigned int i=0; i<filas; i++){
        for (unsigned int j=0; j<columnas; j++){
            cout<<mapa->at(i)->at(j)<<" ";
        }
        cout<<endl;
    }
}