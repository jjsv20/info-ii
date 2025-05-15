#ifndef RED_H
#define RED_H

#include "Enrutador.h"
#include <map>
#include <fstream>

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    Red();

    void agregarEnrutador(Enrutador nuevo);
    void removerEnrutador(string nombre);
    void mostrarRed() const;
    void mostrarTablas() const;
    void cargarDesdeArchivo(string archivo);
    bool validacionEnrutador(string nombre) const;
    Enrutador& obtenerEnrutador(string nombre);
};

#endif // RED_H
