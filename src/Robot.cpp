#include "Robot.h"
#include "CttesRobot.h"

Robot::Robot() {
    posI = 0;
    posJ = 0;
    orientacion = 'E';
}

Robot::~Robot() {

}

void Robot::mover(Mapa* mapa) {
    int posAux;
    switch (orientacion) {
        case 'E':
            posAux = this->posJ + 1;
            if (posAux > mapa->getMapa()->at(0)->size() - 1) posAux = 0;
            if (mapa->getMapa()->at(this->posI)->at(posAux) != 1) {
                (*mapa->getMapa()->at(this->posI))[posAux]=2;
                //mapa->getMapa()->at(this->posI)->at(posAux) = 2;
                this->posJ = posAux;
            }
            break;
        case 'N':
            posAux = this->posI - 1;
            if (posAux < 0) posAux = mapa->getMapa()->size() - 1;
            if (mapa->getMapa()->at(posAux)->at(this->posJ) != 1) {
                (*mapa->getMapa()->at(posAux))[this->posJ] = 2;
                //mapa->getMapa()->at(posAux)->at(this->posJ) = 2;
                this->posI = posAux;
            }
            break;
        case 'O':
            posAux = this->posJ - 1;
            if (posAux < 0) posAux = mapa->getMapa()->at(0)->size() - 1;
            if (mapa->getMapa()->at(this->posI)->at(posAux) != 1) {
                (*mapa->getMapa()->at(this->posI))[posAux]=2;
                //mapa->getMapa()->at(this->posI)->at(posAux) = 2;
                this->posJ = posAux;
            }
            break;
        case 'S':
            posAux = this->posI + 1;
            if (posAux > mapa->getMapa()->size() - 1) posAux = 0;
            if (mapa->getMapa()->at(posAux)->at(this->posJ) != 1) {
                (*mapa->getMapa()->at(posAux))[this->posJ] = 2;
                //mapa->getMapa()->at(posAux)->at(this->posJ) = 2;
                this->posI = posAux;
            }
            break;
    }
}

void Robot::girarI() {
    switch (orientacion) {
        case 'E':
            orientacion = 'N';
            break;
        case 'N':
            orientacion = 'O';
            break;
        case 'O':
            orientacion = 'S';
            break;
        case 'S':
            orientacion = 'E';
            break;
    }
}

void Robot::girarD() {
    switch (orientacion) {
        case 'E':
            orientacion = 'S';
            break;
        case 'S':
            orientacion = 'O';
            break;
        case 'O':
            orientacion = 'N';
            break;
        case 'N':
            orientacion = 'E';
            break;
    }
}

int Robot::getPosI() {
    return posI;
}

void Robot::setPosI(int i) {
    posI = i;
}

int Robot::getPosJ() {
    return posJ;
}

void Robot::setPosJ(int j) {
    posJ = j;
}

char Robot::getOrientacion() {
    return orientacion;
}

void Robot::setOrientacion(char oNueva) {
    orientacion = oNueva;
}