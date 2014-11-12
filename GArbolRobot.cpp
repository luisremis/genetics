#include "GArbolRobot.h"

GArbolRobot::GArbolRobot(Generador *g) : GArbol(g) {
}

GArbolRobot::~GArbolRobot() {
}

ArbolBinario* GArbolRobot::getFuncion(double random) {
    ArbolRobot *abNuevo = NULL;
    char aux = CttesRobot::tablaFunciones->getRandom(random);
    switch (aux) {
        case 'S':
            abNuevo = new Serie(NULL, NULL, NULL);
            abNuevo->setUnario(false);
            break;
        case 'P':
            abNuevo = new PastoAdelante(NULL, NULL, NULL);
            abNuevo->setUnario(false);
            break;
        case 'O':
            abNuevo = new ObstaculoAdelante(NULL, NULL, NULL);
            abNuevo->setUnario(false);
            break;
    }
    return abNuevo;
}

ArbolBinario* GArbolRobot::getTerminal(double random) {
    ArbolRobot *abNuevo = NULL;
    char aux = CttesRobot::tablaTerminales->getRandom(random);
    switch (aux) {
        case 'M':
            abNuevo = new Mover(NULL, NULL, NULL);
            break;
        case 'I':
            abNuevo = new GirarIzq(NULL, NULL, NULL);
            break;
        case 'D':
            abNuevo = new GirarDer(NULL, NULL, NULL);
            break;
    }
    return abNuevo;
}


