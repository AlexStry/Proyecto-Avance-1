#include <iostream>
#include "Usuario.h"
#include "PiedraPapelTijeras.h"
#include "AdivinarElNumero.h"
#include "SolOAguila.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    string nombreUsuario;
    cout << "Ingresa tu nombre: ";
    cin >> nombreUsuario; // Esto lee el nombre del usuario
    Usuario usuario(nombreUsuario); // Creamos un objeto de Usuario
    PiedraPapelTijeras juegoPiedraPapelTijera; // Creamos un objeto de piedra papel o tijeras
    AdivinarElNumero juegoAdivinarNumero(1, 100); // Creamos un objeto de Adivinar el Numero
    SolOAguila juegoSolOAguila; // Creamos un objeto de Sol o Aguila

    int opcion;
    do {
        cout << "\nBienvenido al Hub de Juegos, " << usuario.obtenerNombre() << "!\n";
        cout << "Nivel: " << usuario.obtenerNivel() << "\n"; // Mostramos el nivel de Usuario
        cout << "1. Piedra, Papel o Tijera\n"; 
        cout << "2. Adivina el Número(Una vez por sesion)\n"; 
        cout << "3. Sol o Águila\n"; 
        cout << "4. Salir\n"; 
        cout << "Elige un juego: ";
        cin >> opcion; // Esto lee la opcion elegida de las 4 de arriba

        switch (opcion) {
            case 1: {
                    int xpGanado = juegoPiedraPapelTijera.jugar(usuario); // Activa la funcion de jugar de Piedra Papel o Tiejeras
                    cout << "XP ganado: " << xpGanado << endl; 
                }
                break;
            case 2: {
                    int xpGanado = juegoAdivinarNumero.jugar(usuario); // Activa la funcion de jugar de Adivinar el Numero
                    cout << "XP ganado: " << xpGanado << endl; 
                }
                break;
            case 3: {
                    int xpGanado = juegoSolOAguila.jugar(usuario); // Activa la funcion de jugar de Sol o Aguila
                    cout << "XP ganado: " << xpGanado << endl; 
                }
                break;
        }

    } while (opcion != 4); // El menu se repite hasta que el jugadir decide salir
    cout << "Gracias por jugar. ¡Hasta luego!\n"; 
    return 0;
}
