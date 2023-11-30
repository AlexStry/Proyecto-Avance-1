#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario {
private:
    string nombre;
    int nivel;
    int xp;
    void cargarDatos(); 
    void guardarDatos() const; 
public:
    Usuario(const string& nombre);
    ~Usuario();
    const string& obtenerNombre() const;
    int obtenerNivel() const;
    void agregarXP(int puntos);
};

#endif 
