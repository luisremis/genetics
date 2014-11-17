#ifndef ITEMTABLA_H
#define ITEMTABLA_H

template <class T> class ItemTabla
{
private:
	T *item;
	//double probabilidad;
	double acumulada;
public:
        double probabilidad;
	//ItemTabla(void);
	ItemTabla(T *dato, double probabilidad, double acumulada);
	~ItemTabla(void);
	T* getItem();
	double getProbabilidad();
	double getAcumulada();
};

template <class T>
ItemTabla<T>::ItemTabla(T *d, double p, double a)
{
	this->item=d;
	this->probabilidad=p;
	this->acumulada=a;
}

template <class T>
ItemTabla<T>::~ItemTabla(void)
{
}

template <class T>
T* ItemTabla<T>::getItem(){
	return item;
}

template <class T>
double ItemTabla<T>::getProbabilidad(){
	return probabilidad;
}

template <class T>
double ItemTabla<T>::getAcumulada(){
	return acumulada;
}


#endif