#include <iostream>
#include <map>
#include <vector>
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

    void agregarRuta(string destino, string siguiente, int costo){
        tabla[destino] = make_pair(siguiente, costo);
    }

    void eliminarRuta(string destino) {
        tabla.erase(destino);
    }

    void mostrarTabla() const {
        cout << "Tabla de enrutamiento de " << nombre << ":\n";
        for (const auto& entrada : tabla) {
            cout << "Destino: " << entrada.first
                 << ", Siguiente: " << entrada.second.first
                 << ", Costo: " << entrada.second.second << endl;
        }
    }

    map<string, pair<string, int>>& getTabla(){
        return tabla;
    }

    void actualizarTabla(map<string, pair<string, int>> nuevaTabla){
        tabla = nuevaTabla;
    }
};

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(){
        enrutadores[enrutador.getNombre() = enrutador];
    }

    void removerEnrutador(){
        enrutadores.erase(nombre);
        for(auto& par : enrutadores) {
            par.second.eliminarRuta(nombre);
        }
    }

    void actualizarTablasE(){
        for(auto& enrutador : enrutadores) {
            enrutador.second.mostrarTabla();
        }
    }

    void archivo(string archivo) {
        ifstream file(archivo);
        if(!file) {
            cout << "No se pudo abrir el archivo." << endl;
            return;
        }
        string nombre, destino. siguienteSalto;
        int costo;
        while (file >> nombre >> destino >> siguienteSalto >> costo) {
            if (enrutadores.find(nombre) == enrutadores.end()) {
                enrutadores[nombre] = Enrutador(nombre);
            }
            enrutadores[nombre].agregarRuta(destino, siguienteSalto, costo);
        }
        file.close();
        cout << "Archivo cargado exitosamente" << endl;
    }
};

int main() {
    /*/ Crear enrutadores
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
    A.mostrarTabla();/*/
    Red red;
    int opcion;
    do {
        cout << "Menu" << enld;
        cout << "1. Agregar Enrutador" << enld;
        cout << "2. Remover Enrutador" << enld;
        cin >> opcion;
        string nombre, destino, siguienteSalto;
        int costo;
        switch(opcion) {
        case 1:
            cout << "Nombre Enrutador: ";
            cin >> nombre;
            red.agregarEnrutador((nombre));
            cout << "Enrutador agregado" << endl;
        }
        break;
        case 2:
            cout << "Nombre del enrutador a eliminar: ";
            cin >> nombre;
            red.eliminarEnrutador(nombre);
            cout << "Enrutador eliminado.\n";

    return 0;
}
