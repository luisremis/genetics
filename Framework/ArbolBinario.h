#ifndef _CLASE_ARBOL_BINARIO_PUNT
#define _CLASE_ARBOL_BINARIO_PUNT

#include<iostream>
#include "Nodo.h"
#include "Generador.h"
#include <vector>
#include "Incrementador.h"
#include <string>
#include "Tabla.h"
#include "ItemTabla.h"
#include "Parametro.h"
#include "Prototype.h"
using namespace std;

/*!Clase Arbol Binario, estructura basica del Framework*/
class ArbolBinario : public Prototype{
protected:
	/*!Estructura generica para guardar un valor en el arbol*/
	Nodo* valor;
	/*!Subarbol Izquierdo*/
	ArbolBinario *izq;
	/*!Subarbol Derecho*/
	ArbolBinario *der;
	/*!Puntero al padre*/
	ArbolBinario *padre;
        /*!Cuando este arbol se usa para representar una funcion, este miembro representa si es una funcion unaria o no.*/
        bool unario;
	/*!Nivel de este arbol (altura+1)*/
	int nivel;
	/*!Nivel por abajo de este arbol, hasta llegar al nivel mas bajo de hojas*/
	int nivelesPorAbajo;
public:
	// Constructores y destructor *****************************************************************************************************
	/*!Constructor con parametros. Construye un arbol con nodo v, y con hijos izquierdo y derecho.
		\param v Valor a usar en este arbol. Por defecto es NULL.
		\param i Subarbol izquiero. Por defecto es NULL.
		\param d Subarbol derecho. Por defecto es NULL.
	*/
	ArbolBinario(Nodo* v=NULL, ArbolBinario *i=NULL, ArbolBinario *d=NULL);
	/*!Constructor de copia.
		\param abCopia Arbol que se desea copiar.
	*/
	ArbolBinario(ArbolBinario &abCopia);
	/*!Destructor virtual.*/
	virtual ~ArbolBinario();
	// Getters y Setters****************************************************************************************************************
	/*!Establece el valor del nodo
		\param v El nuevo Nodo, por defecto NULL.
	*/
	void setValor(Nodo* v=NULL);
	/*!Retorna el nodo que representa el valor almacenado en este ArbolBinario.
		\return El Nodo valor.
	*/
	Nodo* getValor();
	/*!Retorna el hijo izquiero.
		\return El ArbolBinario izquierdo.
	*/
	ArbolBinario *getIzq();
	/*!Retorna el hijo derecho.
		\return El ArbolBinario derecho.
	*/
	ArbolBinario *getDer();
	/*!Retorna el padre.
		\return El ArbolBinario padre.
	*/
	ArbolBinario *getPadre();
	/*!Establece el subarbol izquierdo de este arbol.
		\param i El nuevo ArbolBinario izquierdo.
	*/
	void setIzq(ArbolBinario *i);
	/*!Establece el subarbol derecho de este arbol.
		\param d El nuevo ArbolBinario derecho.
	*/
	void setDer(ArbolBinario *d);
	/*!Establece el arbol padre de este arbol.
		\param p El nuevo ArbolBinario padre.
	*/
	void setPadre(ArbolBinario *p);
        /*!Testea si es un arbol unario.
		\return True si este arbol representa una funcion unaria, false en caso contrario.
	*/
	bool esUnario();
	/*!Establece el valor del campo unario de este arbol.
		\param u El nuevo valor para unario.
	*/
	void setUnario(bool u);
	/*!Retorna el nivel de este arbol.
		\return El nivel de este arbol.
	*/
	int getNivel();
	/*!Retorna el numero de niveles por abajo de este arbol.
		\return El numero de niveles por abajo.
	*/
	int getNivelesPorAbajo();
	/*!Establece el nivel de este arbol.
		\param nivel El nuevo nivel.
	*/
	void setNivel(int nivel);
	/*!Establece los niveles por abajo de este arbol.
		\param niveles El nuevo numero de niveles por abajo.
	*/
	void setNivelesPorAbajo(int niveles);
	// Tests ***************************************************************************************************************************
	/*!Funcion para determinar si el arbol almacena un valor o no.
		\return True si el valor almacenado es NULL, false en caso contrario.
	*/
	bool esVacio ();
	/*!Funcion para determinar si el arbol es una hoja (si tiene hijos NULL).
		\return True si sus subarboles izquierdo y derecho son NULL (es una hoja), false en caso contrario.
	*/
	bool esHoja();
	// Otras Funciones *****************************************************************************************************************
	/*!Funcion recursiva para calcular y establecer tanto el nivel como los niveles por abajo de este arbol y sus hijos.
		\param nivelPadre El nivel del ArbolBinario padre.
		\return El nivel de este arbol.
	*/
	int calcularNiveles(int nivelPadre);
	/*!Esta funcion recursiva vuelca el arbol en un vector de punteros.
		\param salida El vector a ser llenado con los punteros.
		\param ab El ArbolBinario que se desea vectorizar.
	*/
	void vectorizar(vector<ArbolBinario*>* salida, ArbolBinario* ab);
	/*!Esta funcion retorna el numero de hojas del arbol.
		\return Numero de hojas.
	*/
	int numHojas();
	/*!Esta funcion retorna la altura del arbol.
		\return Altura del ArbolBinario.
	*/
	int altura();
	/*!Funcion para recorrer el arbol en orden y volcar el recorrido en un vector de Nodos.
		\param salida Vector de Nodo que se llena con el recorrido.
	*/
	void recorridoEnOrden(vector<Nodo*>* salida);
	/*!Funcion para recorrer el arbol en orden previo y volcar el recorrido en un vector de Nodos.
		\param salida Vector de Nodo que se llena con el recorrido.
	*/
	void recorridoPreOrden(vector<Nodo*>* salida);
	/*!Funcion para recorrer el arbol en orden posterior y volcar el recorrido en un vector de Nodos.
		\param salida Vector de Nodo que se llena con el recorrido.
	*/
	void recorridoPostOrden(vector<Nodo*>* salida);
	/*!Funcion para mostrar el ArbolBinario. Debe ser implementada obligatoriamente por las subclases.*/
	virtual void mostrar();
	/*!Funcion para mostrar el ArbolBinario. Debe ser implementada obligatoriamente por las subclases.
		\param out ofstream para volcar la salida.
		\param inc Incrementador para poder llevar un id unico de nodo (util para mostrar usando GraphViz).
         *      \return La cadena de texto que representa al nodo (es una funcion recursiva).
	*/
	virtual string mostrar(ofstream *out, Incrementador* inc);
	/*!Esta funcion interpreta a este ArbolBinario. Es parte del patron de dise�o de software: Interpreter.
		\param parametros Vector de Parametro para realizar la interpretacion.
		\return El numero double resultante de interpretar este ArbolBinario.
	*/
	virtual double interpret(vector <Parametro*> *parametros);
	/*!Funcion para copiar un arbol. Es parte del patron de dise�o de software: Prototype.
		\return Una copia de este ArbolBinario, el cual es del tipo Prototype.
	*/
	virtual Prototype *copiar();
	/*!Funcion recursiva para retornar en una cadena el recorrido en orden de este arbol.
		\param recorrido La cadena en la cual se va armando el recorrido.
		\return La cadena con el recorrido.
	*/
	string mostrarEnOrden(string recorrido);

	// Miembros publicos ***************************************************************************************************************
	/*!Altura minima permitida*/
        static int ALTURA_MIN;
	/*!Altura maxima permitida*/
	static int ALTURA_MAX;

};
#endif /* _CLASE_ARBOL_BINARIO_PUNT */
