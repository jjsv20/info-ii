#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
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
        cout << "Tabla de enrutamiento para " << nombre << ":" << endl;
        cout << left << setw(10) << "Destino" << setw(10) << "Costo" << setw(15) << "Siguiente Salto" << endl;
        for (const auto& entrada : tabla) {
            cout << setw(10) << entrada.first
                 << setw(10) << entrada.second.second
                 << setw(15) << entrada.second.first << endl;
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

    map<string, Enrutador> getEnrutadores(){
        return enrutadores;
    }

    void removerEnrutador(string nombre){
        enrutadores.erase(nombre);
        for(auto& par : enrutadores) {
            par.second.eliminarRuta(nombre);
        }
    }

    void mostrarTablaEnrutador(string nombre) {
        if(enrutadores.find(nombre) == enrutadores.end()){
            cout << "Enrutador no encontrado";
            return;
        }
        enrutadores[nombre].mostrarTabla();
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
            if (enrutadores.find(destino) == enrutadores.end()) {
                enrutadores[destino] = Enrutador(destino);
            }
            enrutadores[nombre].agregarRuta(destino, destino, costo);
            enrutadores[destino].agregarRuta(nombre, nombre, costo);
        }

        file.close();
        cout << "Archivo cargado exitosamente.\n";
    }
};

int main() {
    Red red;
    int opcion;
    do {
        cout << "----- Menu ----"<< endl;
        cout << "1. Agregar Enrutador" << endl;
        cout << "2. Remover Enrutador" << endl;
        cout << "3. Mostrar tabla de Enrutadores" << endl;
        cout << "4. Cargar desde archivo" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        string nombre;
        switch(opcion) {
        case 1:
            cout << "Ingrese nombre del Enrutador: ";
            cin >> nombre;
            red.agregarEnrutador(Enrutador(nombre));
            cout << "Enrutador agregado" << endl;
            break;
        case 2:
            cout << "Ingrese el nombre del enrutador a eliminar: ";
            cin >> nombre;
            red.removerEnrutador(nombre);
            cout << "Enrutador eliminado" << endl;
            break;
        case 3:
            cout << "Ingrese el nombre del enrutador: ";
            cin >> nombre;
            red.mostrarTablaEnrutador(nombre);
            break;
        default:
            cout << "Opcion invalida";
            break;
        }
    } while(opcion != 3);
    return 0;
}
