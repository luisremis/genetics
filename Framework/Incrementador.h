/*
	Usado para incrementar un entero y asegurar unicidad, sino habria replicacion de ids de nodos
*/
#pragma once

class Incrementador
{
private:
	int numero;
public:
	Incrementador(void);
	~Incrementador(void);
	int getNumero();
};
