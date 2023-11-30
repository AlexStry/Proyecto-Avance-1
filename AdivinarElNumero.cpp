#include "AdivinarElNumero.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

AdivinarElNumero::AdivinarElNumero(int rangoMin, int rangoMax) : rangoMinimo(rangoMin), rangoMaximo(rangoMax) {
    generarNumeroSecreto(); 
}

int AdivinarElNumero::jugar(Usuario& usuario) {
    int intentos = 0;
    int adivinanza;
    cout << "Adivina el número entre " << rangoMinimo << " y " << rangoMaximo << ": ";
    do {
        cin >> adivinanza; // Usuario adivina
        intentos++;
        if (adivinanza < numeroSecreto) cout << "Más alto. Intenta de nuevo: "; 
        else if (adivinanza > numeroSecreto) cout << "Más bajo. Intenta de nuevo: ";
    } while (adivinanza != numeroSecreto && intentos < 10); // Una loop continua hasta que se acabe
    if (adivinanza == numeroSecreto) {
        cout << "Correcto! El número es " << numeroSecreto << endl; 
    } else {
        cout << "Agotaste tus intentos. El número era " << numeroSecreto << endl; 
    }
    int puntos = calcularPuntos(intentos);
    usuario.agregarXP(puntos); // Agregar XP
    return puntos; 
}

int AdivinarElNumero::calcularPuntos(int intentos) {
    // Calcular puntos basandose en intentos
    return 100 - (intentos * 10); 
}

void AdivinarElNumero::generarNumeroSecreto() {
    srand(static_cast<unsigned int>(time(nullptr))); 
    numeroSecreto = rangoMinimo + rand() % (rangoMaximo - rangoMinimo + 1); 
}

int AdivinarElNumero::obtenerNivel() const {
    return nivel; 
}

void AdivinarElNumero::establecerNivel(int nuevoNivel) {
    nivel = nuevoNivel; 
}
