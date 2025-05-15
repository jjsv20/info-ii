#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Enrutador {
private:
    string nombre;
    map<string, pair<string, int>> tabla; // destino -> {siguiente salto, costo}

public:
    Enrutador();
    Enrutador(string nuevoNombre);

    string getNombre() const;
    void setNombre(string nuevoNombre);

    map<string, pair<string, int>>& getTabla();
    void setTabla(map<string, pair<string, int>> nuevaTabla);

    void agregarRuta(string destino, string siguiente, int costo);
    void removerRuta(string destino);
    void mostrarTabla() const;
};
#endif // ENRUTADOR_H
