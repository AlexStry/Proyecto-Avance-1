#include "Usuario.h"
#include <fstream>
#include <iostream>

using namespace std;

Usuario::Usuario(const string& nombre) : nombre(nombre), nivel(1), xp(0) {
    cargarDatos(); // Cargar data
}

Usuario::~Usuario() {
    guardarDatos(); // guardar
}

const string& Usuario::obtenerNombre() const {
    return nombre; 
}

int Usuario::obtenerNivel() const {
    return nivel; 
}

void Usuario::agregarXP(int puntos) {
    xp += puntos; // Agregar puntos de xp
    while (xp >= 20) { // Ecuacion que calcula cuando subes de nivel
        nivel++;
        xp -= 20;
    }
}

void Usuario::cargarDatos() {
    ifstream file(nombre + ".txt"); // Abre el archivo de tu txt
    if (file.is_open()) {
        file >> nivel >> xp;
        file.close(); // Cierra el archivo
    }
}

void Usuario::guardarDatos() const {
    ofstream file(nombre + ".txt"); // Abre el archivo para guardatar dat
    if (file.is_open()) {
        file << nivel << ' ' << xp; // Escribe el nivel y el xp en el archivo
        file.close(); 
    } else {
        cerr << "Error al guardar datos para " << nombre << endl; 
    }
}
