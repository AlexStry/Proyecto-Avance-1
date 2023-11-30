#include "PiedraPapelTijeras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

PiedraPapelTijeras::PiedraPapelTijeras() {
    srand(static_cast<unsigned int>(time(nullptr))); 
}

int PiedraPapelTijeras::jugar(Usuario& usuario) {
    cout << "Piedra, Papel, o Tijera: ";
    cin >> eleccionJugador; // Aqui se hace la desicion del jugador
    eleccionComputadora = generarEleccionComputadora(); // Se elige un numero al azar
    cout << "Computadora eligió " << eleccionComputadora << endl;
    int resultado = determinarGanador(); // Determina el ganador
    int puntos = calcularPuntos(resultado); // Calcula los puntos ganados
    usuario.agregarXP(puntos); 
    return puntos; 
}

int PiedraPapelTijeras::calcularPuntos(int resultado) {
    // Calcula los puntos basandose en el resultado
    if (resultado == 1) return 10; 
    else if (resultado == -1) return 0; 
    else return 5; 
}

string PiedraPapelTijeras::generarEleccionComputadora() {
    // Genera la desicion de la computadora
    int eleccionAleatoria = rand() % 3;
    return eleccionAleatoria == 0 ? "Piedra" : eleccionAleatoria == 1 ? "Papel" : "Tijera";
}

int PiedraPapelTijeras::determinarGanador() {
    // Determinaa el ganador
    if (eleccionJugador == eleccionComputadora) {
        cout << "Empate!" << endl;
        return 0; 
    }

    // Condiciones de ganar para el jugador
    if ((eleccionJugador == "Piedra" && eleccionComputadora == "Tijera") ||
        (eleccionJugador == "Papel" && eleccionComputadora == "Piedra") ||
        (eleccionJugador == "Tijera" && eleccionComputadora == "Papel")) {
        cout << "Ganaste!" << endl;
        return 1; 
    } else {
        cout << "Perdiste!" << endl;
        return -1; 
    }
}

int PiedraPapelTijeras::obtenerNivel() const {
    return nivel; 
}

void PiedraPapelTijeras::establecerNivel(int nuevoNivel) {
    nivel = nuevoNivel; 
}
