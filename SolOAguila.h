#ifndef SOLOAGUILA_H
#define SOLOAGUILA_H

#include "Juego.h"
#include <string>

using namespace std;

class SolOAguila : public Juego {
private:
    string lanzarMoneda();
    int nivel;
public:
    SolOAguila();
    int jugar(Usuario& usuario) override;
    int calcularPuntos(int resultado) override;
    int obtenerNivel() const override;
    void establecerNivel(int nuevoNivel) override;
};

#endif 
