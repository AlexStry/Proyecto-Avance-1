#include <iostream>
#include "Usuario.h"
#include "PiedraPapelTijeras.h"
#include "AdivinarElNumero.h"
#include "SolOAguila.h"

using namespace std; // Using the standard namespace

int main() {
    string nombreUsuario;
    cout << "Ingresa tu nombre: ";
    cin >> nombreUsuario; // Read user name

    Usuario usuario(nombreUsuario); // Create a user object
    PiedraPapelTijeras juegoPiedraPapelTijera; // Create a Rock, Paper, Scissors game object
    AdivinarElNumero juegoAdivinarNumero(1, 100); // Create a Guess the Number game object with range 1-100
    SolOAguila juegoSolOAguila; // Create a Heads or Tails game object

    int opcion;
    do {
        cout << "\nBienvenido al Hub de Juegos, " << usuario.obtenerNombre() << "!\n";
        cout << "Nivel: " << usuario.obtenerNivel() << "\n"; // Display user level
        cout << "1. Piedra, Papel o Tijera\n"; // Game option 1
        cout << "2. Adivina el Número\n"; // Game option 2
        cout << "3. Sol o Águila\n"; // Game option 3
        cout << "4. Salir\n"; // Exit option
        cout << "Elige un juego: ";
        cin >> opcion; // Read the user's choice

        switch (opcion) {
            case 1: {
                    int xpGanado = juegoPiedraPapelTijera.jugar(usuario); // Play Rock, Paper, Scissors
                    cout << "XP ganado: " << xpGanado << endl; // Display XP gained
                }
                break;
            case 2: {
                    int xpGanado = juegoAdivinarNumero.jugar(usuario); // Play Guess the Number
                    cout << "XP ganado: " << xpGanado << endl; // Display XP gained
                }
                break;
            case 3: {
                    int xpGanado = juegoSolOAguila.jugar(usuario); // Play Heads or Tails
                    cout << "XP ganado: " << xpGanado << endl; // Display XP gained
                }
                break;
        }

    } while (opcion != 4); // Repeat until the user chooses to exit

    cout << "Gracias por jugar. ¡Hasta luego!\n"; // Exit message
    return 0;
}
