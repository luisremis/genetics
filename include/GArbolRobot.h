#ifndef GARBOLROBOT_H
#define	GARBOLROBOT_H

#include "GArbol.h"
#include "ArbolRobot.h"
#include "Serie.h"
#include "PastoAdelante.h"
#include "ObstaculoAdelante.h"
#include "Mover.h"
#include "GirarIzq.h"
#include "GirarDer.h"
#include "CttesRobot.h"

class GArbolRobot : public GArbol{
public:
    GArbolRobot(Generador *g);
    virtual ~GArbolRobot();
protected:
    virtual ArbolBinario* getFuncion(double random);
    virtual ArbolBinario* getTerminal(double random);

};

#endif

