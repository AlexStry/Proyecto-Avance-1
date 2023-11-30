#ifndef ADIVINARELNUMERO_H
#define ADIVINARELNUMERO_H
#include "Juego.h"
#include <string>

using namespace std;

class AdivinarElNumero : public Juego {
private:
    int numeroSecreto;
    int rangoMinimo, rangoMaximo;
    int nivel;
    void generarNumeroSecreto();
public:
    AdivinarElNumero(int rangoMin, int rangoMax); 
    int jugar(Usuario& usuario) override;
    int calcularPuntos(int intentos) override;
    int obtenerNivel() const override;
    void establecerNivel(int nuevoNivel) override;
};

#endif