#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Enrutador {
private:
    string nombre;
    map<string, pair<string, int>> tabla; // destino -> {siguiente salto, costo}

public:
    Enrutador() : nombre("") {}
    Enrutador(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nuevoNombre){
        nombre = nuevoNombre;
    }

    map<string, pair<string, int>>& getTabla(){
        return tabla;
    }

    void setTabla(map<string, pair<string, int>> nuevaTabla) {
        tabla = nuevaTabla;
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


    void actualizarTabla(map<string, pair<string, int>> nuevaTabla){
        tabla = nuevaTabla;
    }
};

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(Enrutador enrutador){
        enrutadores[enrutador.getNombre()] = enrutador;
    }

    map<string, Enrutador> getEnrutadores() const {
        return enrutadores;
    }

    void removerEnrutador(string nombre){
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
        string nombre, destino, siguienteSalto;
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
    Red red;
    int opcion;
    do {
        cout << "Menu" << endl;
        cout << "1. Agregar Enrutador" << endl;
        cout << "2. Remover Enrutador" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        string nombre;
        switch(opcion) {
        case 1:
            cout << "Nombre Enrutador: ";
            cin >> nombre;
            red.agregarEnrutador(Enrutador(nombre));
            cout << "Enrutador agregado" << endl;
            break;
        case 2:
            cout << "Nombre del enrutador a eliminar: ";
            cin >> nombre;
            red.removerEnrutador(nombre);
            cout << "Enrutador eliminado" << endl;
            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida";
            break;
        }
    } while(opcion != 3);
    return 0;
}
