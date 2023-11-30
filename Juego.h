#ifndef JUEGO_H
#define JUEGO_H

#include "Usuario.h"

class Juego {
public:
    virtual ~Juego() = default;
    virtual int jugar(Usuario& usuario) = 0;
    virtual int calcularPuntos(int resultado) = 0;
    virtual int obtenerNivel() const = 0;
    virtual void establecerNivel(int nuevoNivel) = 0;
};

#endif