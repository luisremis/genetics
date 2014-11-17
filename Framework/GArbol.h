#ifndef GARBOL_H
#define	GARBOL_H

#include "ArbolBinario.h"
#include "Generador.h"

class GArbol {
public:
    GArbol(Generador *gen);
    virtual ~GArbol();
    ArbolBinario* generarGrow(ArbolBinario *padre, int min, int max, int actual);
    ArbolBinario* generarFull(ArbolBinario *padre, int min, int max, int actual);
protected:
    Generador *g;
    virtual ArbolBinario* getFuncion(double random);
    virtual ArbolBinario* getTerminal(double random);
};

#endif	/* GARBOL_H */

