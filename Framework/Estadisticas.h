#ifndef ESTADISTICAS_H
#define	ESTADISTICAS_H

#include <vector>
#include <climits>
#include <fstream>
using namespace std;

class Estadisticas {
private:
    Estadisticas();
    vector<double> *best;
    vector<double> *avg;
    double bestAux;
    double avgAux;
    int cantAux;
    static Estadisticas* instancia;
public:
    void compararMejor(double);
    void agregarAvg(double);
    void nuevaGeneracion();
    void exportarMejor();
    void exportarPromedio();
    void exportar();
    void reset();
    static Estadisticas* getInstancia();
private:

};

#endif