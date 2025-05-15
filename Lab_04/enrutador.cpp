#include "Enrutador.h"

Enrutador::Enrutador() {
    nombre = "";
}

Enrutador::Enrutador(string nuevoNombre) {
    nombre = nuevoNombre;
}

string Enrutador::getNombre() const {
    return nombre;
}

void Enrutador::setNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

map<string, pair<string, int>>& Enrutador::getTabla() {
    return tabla;
}

void Enrutador::setTabla(map<string, pair<string, int>> nuevaTabla) {
    tabla = nuevaTabla;
}

void Enrutador::agregarRuta(string destino, string siguiente, int costo) {
    tabla[destino] = make_pair(siguiente, costo);
}

void Enrutador::removerRuta(string destino) {
    tabla.erase(destino);
}

void Enrutador::mostrarTabla() const {
    cout << "\nTabla de enrutamiento de " << nombre << ":\n";
    for (const auto& entrada : tabla) {
        cout << "Destino: " << entrada.first
             << ", Siguiente: " << entrada.second.first
             << ", Costo: " << entrada.second.second << endl;
    }
}
