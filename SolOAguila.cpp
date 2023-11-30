#include "SolOAguila.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

SolOAguila::SolOAguila() {
    srand(static_cast<unsigned int>(time(nullptr)));
}

int SolOAguila::jugar(Usuario& usuario) {
    string eleccionJugador;
    cout << "Elige Sol o Águila: ";
    cin >> eleccionJugador; // El jugador hace una desicion
    string resultadoMoneda = lanzarMoneda(); 
    cout << "La moneda cayó en: " << resultadoMoneda << endl;
    int acierto = (eleccionJugador == resultadoMoneda) ? 1 : 0; // Se determina si es correcto
    int puntos = calcularPuntos(acierto); 
    usuario.agregarXP(puntos); 
    return puntos; 
}

int SolOAguila::calcularPuntos(int resultado) {
    return resultado ? 10 : 0; 
}

string SolOAguila::lanzarMoneda() {
    // Se "lanza" la moneda
    return rand() % 2 == 0 ? "Sol" : "Águila";
}

int SolOAguila::obtenerNivel() const {
    return nivel; 
}

void SolOAguila::establecerNivel(int nuevoNivel) {
    nivel = nuevoNivel; 
}
