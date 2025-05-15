#include "Red.h"

Red::Red() {}

void Red::agregarEnrutador(Enrutador nuevo) {
    enrutadores[nuevo.getNombre()] = nuevo;
}

void Red::removerEnrutador(string nombre) {
    enrutadores.erase(nombre);
    for (auto& [clave, enrutador] : enrutadores) {
        enrutador.removerRuta(nombre);
    }
}

void Red::mostrarRed() const {
    cout << "\nEnrutadores en la red:\n";
    for (const auto& [nombre, _] : enrutadores) {
        cout << " - " << nombre << endl;
    }
}

void Red::mostrarTablas() const {
    for (const auto& [_, enrutador] : enrutadores) {
        enrutador.mostrarTabla();
    }
}

void Red::cargarDesdeArchivo(string archivo) {
    ifstream file(archivo);
    if (!file) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    string nombre, destino, siguiente;
    int costo;
    while (file >> nombre >> destino >> siguiente >> costo) {
        if (!validacionEnrutador(nombre)) {
            agregarEnrutador(Enrutador(nombre));
        }
        enrutadores[nombre].agregarRuta(destino, siguiente, costo);
    }

    file.close();
    cout << "Archivo cargado exitosamente.\n";
}

bool Red::validacionEnrutador(string nombre) const {
    return enrutadores.find(nombre) != enrutadores.end();
}

Enrutador& Red::obtenerEnrutador(string nombre) {
    return enrutadores[nombre];
}
