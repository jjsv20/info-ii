#include <iostream>
#include <map>
#include <string>
using namespace std;

class Enrutador {
private:
    string nombre;
    map<string, pair<string, int>> tabla; // destino -> {siguiente salto, costo}

public:
    Enrutador(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void actualizarRuta(const string& destino, const string& siguiente, int costo) {
        tabla[destino] = {siguiente, costo};
    }

    void eliminarRuta(const string& destino) {
        tabla.erase(destino);
    }

    void mostrarTabla() const {
        cout << "Tabla de enrutamiento de " << nombre << ":\n";
        for (const auto& entrada : tabla) {
            cout << "  Destino: " << entrada.first
                 << ", Siguiente: " << entrada.second.first
                 << ", Costo: " << entrada.second.second << endl;
        }
    }

    map<string, pair<string, int>>& obtenerTabla() {
        return tabla;
    }
};

int main() {
    // Crear enrutadores
    Enrutador A("A");
    Enrutador B("B");

    // Agregar rutas
    A.actualizarRuta("B", "B", 3);
    A.actualizarRuta("C", "B", 5);

    B.actualizarRuta("A", "A", 3);
    B.actualizarRuta("C", "C", 2);

    // Mostrar tablas iniciales
    A.mostrarTabla();
    B.mostrarTabla();

    // Eliminar una ruta
    A.eliminarRuta("C");

    cout << "\nDespués de eliminar la ruta A -> C:\n";
    A.mostrarTabla();

    return 0;
}
