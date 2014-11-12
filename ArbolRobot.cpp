#include "ArbolRobot.h"

ArbolRobot::ArbolRobot(Nodo* v, ArbolBinario* i, ArbolBinario* d) : ArbolBinario(v, i, d) {
    className = "ArbolRobot";
}

ArbolRobot::ArbolRobot(ArbolRobot &original) {
    if (original.valor != NULL) this->valor = (Nodo*) original.valor->copiar();
    else this->valor = NULL;
    if (original.izq != NULL) {
        this->izq = (ArbolRobot*) original.izq->copiar();
        this->izq->setPadre(this);
    } else {
        this->izq = NULL;
    }
    if (original.der != NULL) {
        this->der = (ArbolRobot*) original.der->copiar();
        this->der->setPadre(this);
    } else {
        this->der = NULL;
    }
    if (original.padre == NULL) this->padre = NULL;
    this->nivel = original.nivel;
    this->nivelesPorAbajo = original.nivelesPorAbajo;
    this->className = original.className;
}

ArbolRobot::~ArbolRobot() {
    delete izq;
    delete der;
    delete valor;
}

double ArbolRobot::interpret(vector<Parametro*>*) {
    return 0;
}

Prototype *ArbolRobot::copiar() {
    return new ArbolRobot(*this);
}

void ArbolRobot::mostrar() {
    // Muestra solo este arbol
    ofstream *out = new ofstream("temp.dot");
    *out << "graph Temp {" << endl;
    mostrar(out, new Incrementador());
    *out << "}" << endl;
    out -> close();

    //system("dot -Tpng -o temp.png temp.dot");//FOR LLINUX
    //system("shotwell temp.png"); // FOR LINUX

    system("/Applications/Graphviz.app/Contents/MacOS/Graphviz temp.dot &"); //FOR MAC
    //system("/usr/local/graphviz-2.12/bin/dot -Tpng temp.png temp.dot &"); //FOR MAC
    //system("open -a Preview temp.png"); //For Mac
}

string ArbolRobot::mostrar(ofstream *out, Incrementador *inc) {
    string hijoIzq = "";
    string hijoDer = "";
    if (!esHoja()) {
        if (izq != NULL) hijoIzq = izq->mostrar(out, inc);
        if (der != NULL) hijoDer = der->mostrar(out, inc);
    }

    string label = "";
    string color = "";
    if (getClassName().compare("Serie") == 0 || getClassName().compare("PastoAdelante") == 0 || getClassName().compare("ObstaculoAdelante") == 0) {
        label = getClassName();
        color = "tomato";
    } else if (getClassName().compare("Mover") == 0 || getClassName().compare("GirarIzq") == 0 || getClassName().compare("GirarDer") == 0) {
        label = getClassName();
        color = "darkslateblue";
    }

    stringstream sAux;
    sAux << "Nodo_" << inc->getNumero();
    string esteNodo = sAux.str();
    string nodo = esteNodo;
    nodo.append("[label=").append(label).append(", color=").append(color).append("]");
    *out << nodo << ";" << endl;
    if (!esHoja()) {
        if (izq != NULL) *out << esteNodo << " -- " << hijoIzq << ";" << endl;
        if (der != NULL) *out << esteNodo << " -- " << hijoDer << ";" << endl;
    }
    return esteNodo;
}

string ArbolRobot::getClassName() {
    return className;
}
