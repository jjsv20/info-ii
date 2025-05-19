#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <climits>
#include <ctime>
using namespace std;

class Ruta{
public:
    string destino;
    int costo;
    Ruta(string destino, int costo) : destino(destino), costo(costo){}
};

class Enrutador {
private:
    string nombre;
    map<string, pair<int, string>> tablaDeEnrutamiento; // destino -> {costo, siguiente salto}

public:
    vector<Ruta> rutas;
    Enrutador() : nombre("") {}
    Enrutador(string nombre) : nombre(nombre) {
        tablaDeEnrutamiento[nombre] = {0, nombre}; //inicializado en costo 0
    }

    string getNombre() const {
        return nombre;
    }

    void agregarRuta(string destino, int costo){
        for(auto &existe : rutas){
            if(existe.destino == destino){
                existe.costo = costo;
                tablaDeEnrutamiento[destino] = {costo, destino};
                return;
            }
        }
        rutas.push_back(Ruta(destino, costo));
        tablaDeEnrutamiento[destino] = {costo, destino};
    }

    void eliminarRuta(string destino) {
        for(auto i = rutas.begin(); i != rutas.end(); ++i){
            if(i->destino == destino){
                rutas.erase(i);
                break;
            }
        }
        tablaDeEnrutamiento.erase(destino);
    }

    map<string, pair<int, string>> getTablaDeEnrutamiento() const {
        return tablaDeEnrutamiento;
    }
};

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    bool existeEnrutador(const string& nombre) const {
        return enrutadores.find(nombre) != enrutadores.end();
    }

    bool agregarEnrutador(const Enrutador& enrutador){
        string nombre = enrutador.getNombre();
        if(existeEnrutador(nombre)){
            cout << "Ya existe un enrutador con ese nombre." << endl;
            return false;
        }
        enrutadores[nombre] = enrutador;
        return true;
    }

    void agregarEnlace(const string &origen, const string &destino, int costo) {
        if(!existeEnrutador(origen)) enrutadores[origen] = Enrutador(origen);
        if(!existeEnrutador(destino)) enrutadores[destino] = Enrutador(destino);
        enrutadores[origen].agregarRuta(destino, costo);
        enrutadores[destino].agregarRuta(origen, costo);
    }

    void mostrarRed(){
        cout << "\nEnrutadores en la red: ";
        for(auto& enrutador : enrutadores){
            cout << "\n - " << enrutador.first << endl;
        }
    }

    bool removerEnrutador(string nombre){
        if(!existeEnrutador(nombre)){
            cout << "\nEl enrutador no existe." << endl;
            return false;
        }
        enrutadores.erase(nombre);
        for(auto& par : enrutadores) {
            par.second.eliminarRuta(nombre);
        }
        return true;
    }

    void mostrarTablas() {
        vector<string> nombres;
        // Obtener todos los nombres de enrutadores
        for (const auto& par : enrutadores) {
            nombres.push_back(par.first);
        }
        // Imprimir encabezado
        cout << "\n   ";
        for (const auto& destino : nombres) {
            cout << setw(4) << destino;
        }
        cout << endl;
        // Imprimir las filas
        for (const auto& origen : nombres) {
            cout << setw(2) << origen << " ";
            for (const auto& destino : nombres) {
                if (origen == destino) {
                    cout << setw(4) << 0;
                } else {
                    const auto& tabla = enrutadores.at(origen).getTablaDeEnrutamiento();
                    if (tabla.count(destino)) {
                        cout << setw(4) << tabla.at(destino).first;
                    } else {
                        cout << setw(4) << "-";
                    }
                }
            }
            cout << endl;
        }
    }

    void archivo(const string& namearchivo) {
        ifstream archivo(namearchivo);
        string linea;
        if (archivo.is_open()) {
            int numEnrutadores;
            archivo >> numEnrutadores;
            getline(archivo, linea);
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string origen, destino;
                int costo;
                ss >> origen >> destino >> costo;
                agregarEnlace(origen, destino, costo);
            }
            cout << "\nSe ha cargado " << namearchivo << " exitosamente." << endl;
        } else {
            cout << "Error: No se pudo abrir el archivo ";
        }
        archivo.close();
    }

    void encontrarCamino(const string& actual, const string& destino, vector<string>& caminoActual, int costoAcumulado,
                         vector<string>& mejorCamino, int& menorCosto, size_t& saltos, map<string, bool>& enrutadorvisitado){
        enrutadorvisitado[actual] = true;
        caminoActual.push_back(actual);
        if(actual == destino){
            if((costoAcumulado < menorCosto) || (costoAcumulado == menorCosto && caminoActual.size() < saltos)){
                menorCosto = costoAcumulado;
                mejorCamino = caminoActual;
                saltos = caminoActual.size();
            }
        }else{
            for(const Ruta& ruta : enrutadores[actual].rutas){
                if(!enrutadorvisitado[ruta.destino]){
                    encontrarCamino(ruta.destino, destino, caminoActual, costoAcumulado + ruta.costo, mejorCamino, menorCosto, saltos, enrutadorvisitado);
                }
            }
        }
        caminoActual.pop_back();
        enrutadorvisitado[actual] = false;
    }

    int costoPaquete(const string& origen, const string& destino){
        vector<string> mejorCamino, caminoActual;
        map<string, bool> enrutadorVisitado;
        int menorCosto = INT_MAX;
        size_t saltos = SIZE_MAX;
        for(auto& par : enrutadores){
            enrutadorVisitado[par.first] = false;
        }
        if(!enrutadores.count(origen) || !enrutadores.count(destino)){
            return -1;
        }
        encontrarCamino(origen, destino, caminoActual, 0, mejorCamino, menorCosto, saltos, enrutadorVisitado);
        if(menorCosto == INT_MAX){
            return -1;
        }
        return menorCosto;
    }

    void caminoPaquete(const string& origen, const string& destino){
        vector<string> mejorCamino, caminoActual;
        map<string,bool> enrutadorvisitado;
        int menorCosto = INT_MAX;
        size_t saltos = SIZE_MAX;
        for(auto& par : enrutadores){
            enrutadorvisitado[par.first] = false;
        }
        if(!enrutadores.count(origen) || !enrutadores.count(destino)){
            cout << "\nOrigen o destino no existen en la Red" << endl;
            return;
        }
        encontrarCamino(origen, destino, caminoActual, 0, mejorCamino, menorCosto, saltos, enrutadorvisitado);
        if(menorCosto == INT_MAX){
            cout << "\nNo existe camino entre " << origen << " y " << destino << endl;
        }else{
            cout << "Camino mas eficiente: ";
            for(size_t i = 0; i < mejorCamino.size(); ++i){
                cout << mejorCamino[i];
                if(i + 1 < mejorCamino.size()){
                    cout << " -> ";
                }
                //cout << "\nCosto total: " << menorCosto << ""
            }
        }
    }

    void generarRedAleatoria(int numEnrutadores, size_t totalConexiones, string archivo) {
        ofstream file(archivo);
        srand(time(0));
        vector<string> nombres;
        for (int i = 0; i < numEnrutadores; i++) {
            string nombre = string(1, 'A' + i);
            nombres.push_back(nombre);
        }
        file << numEnrutadores << endl;
        set<pair<string, string>> conexiones;
        while (conexiones.size() < totalConexiones) {
            string origen = nombres[rand() % nombres.size()];
            string destino = nombres[rand() % nombres.size()];
            if (origen != destino) {
                pair<string, string> conexion = make_pair(min(origen, destino), max(origen, destino));
                if (conexiones.count(conexion) == 0) {
                    int costo = 1 + rand() % 10;
                    file << origen << " " << destino << " " << costo << endl;
                    conexiones.insert(conexion);
                }
            }
        }
        file.close();
        cout << "\nRed aleatoria generada en: " << archivo << endl;
        this->archivo(archivo);
    }

};

int main() {
    Red red;
    int opcion;
    do {
        cout << "\n----- Menu ----"<< endl;
        cout << "1.  Agregar Enrutador" << endl;
        cout << "2.  Remover Enrutador" << endl;
        cout << "3.  Agregar Enlace" << endl;
        cout << "4.  Mostrar Tablas de Enrutamiento" << endl;
        cout << "5.  Mostrar la Red" << endl;
        cout << "6.  Cargar desde archivo" << endl;
        cout << "7.  Calcular costo" << endl;
        cout << "8.  Camino eficiente" << endl;
        cout << "9.  Generar Red Aleatoria" << endl;
        cout << "10. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        string nombre, origen, destino, nombreRedAleatoria;
        int costo, numeroEnrutadores, conexiones;
        switch (opcion) {
        case 1:
            cout << "Ingrese nombre del Enrutador: ";
            cin >> nombre;
            if (red.agregarEnrutador(Enrutador(nombre))) {
                cout << "Enrutador " << nombre << " agregado exitosamente." << endl;
            }
            break;
        case 2:
            cout << "Ingrese el nombre del enrutador a eliminar: ";
            cin >> nombre;
            if (red.removerEnrutador(nombre)) {
                cout << "Enrutador " << nombre << " eliminado exitosamente." << endl;
            }
            break;
        case 3:
            cout << "Ingrese el Enrutador origen: ";
            cin >> origen;
            cout << "Ingrese el Enrutador destino: ";
            cin >> destino;
            cout << "Ingrese el costo del enlace: ";
            cin >> costo;
            red.agregarEnlace(origen, destino, costo);
            cout << "Enlace agregado exitosamente.\n";
            break;
        case 4:
            red.mostrarTablas();
            break;
        case 5:
            red.mostrarRed();
            break;
        case 6:
            cout << "Ingrese el nombre del archivo: ";
            cin >> nombre;
            red.archivo(nombre);
            break;
        case 7:
            cout << "Ingrese el Enrutador origen: ";
            cin >> origen;
            cout << "Ingrese el Enrutador destino: ";
            cin >> destino;
            costo = red.costoPaquete(origen, destino);
            if(costo == -1){
                cout << "No exite camino entre " << origen << " y " << destino << endl;
            }else{
                 cout << "El costo mínimo de " << origen << " a " << destino << " es: " << costo << endl;
            }
            break;
        case 8:
            cout << "Ingrese el Enrutador origen: ";
            cin >> origen;
            cout << "Ingrese el Enrutador destino: ";
            cin >> destino;
            red.caminoPaquete(origen, destino);
            break;
        case 9:
            cout << "Ingrese numero de Enrutadores para la red: ";
            cin >> numeroEnrutadores;
            cout << "Ingrese numero de conexiones por Enrutador: ";
            cin >> conexiones;
            cout << "Nombre del archivo para la red aleatoria: ";
            cin >> nombreRedAleatoria;
            red.generarRedAleatoria(numeroEnrutadores, conexiones, nombreRedAleatoria);
            break;
        case 10:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 10);
    return 0;
}
