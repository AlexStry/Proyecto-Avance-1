#ifndef PIEDRAPAPELTIJERAS_H
#define PIEDRAPAPELTIJERAS_H
#include "Juego.h"
#include <string>

using namespace std; 

class PiedraPapelTijeras : public Juego {
private:
    string eleccionJugador; 
    string eleccionComputadora; 
    int nivel; 
    string generarEleccionComputadora(); 
    int determinarGanador(); 
public:
    PiedraPapelTijeras(); 
    int jugar(Usuario& usuario) override; 
    int calcularPuntos(int resultado) override; 
    int obtenerNivel() const override; 
    void establecerNivel(int nuevoNivel) override; 
};

#endif
