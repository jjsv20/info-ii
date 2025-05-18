#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
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

    /*/void mostrarTabla() const {
        cout << "Tabla de enrutamiento para " << nombre << ":" << endl;
        cout << left << setw(10) << "Destino" << setw(10) << "Costo" << setw(15) << "Siguiente Salto" << endl;
        for (const auto& entrada : tabla) {
            cout << setw(10) << entrada.first
                 << setw(10) << entrada.second.second
                 << setw(15) << entrada.second.first << endl;
        }
    }/*/

    void mostrarTabla() {
        cout << "\nTabla de enrutamiento para " << nombre << ":\n";
        cout << "\nDestino\tCosto\tSiguiente Salto\n";
        for (const auto& entrada : tablaDeEnrutamiento) {
            cout << entrada.first << "\t" << entrada.second.first << "\t" << entrada.second.second << endl;
        }
    }

    map<string, pair<int, string>> getTablaDeEnrutamiento() const {
        return tablaDeEnrutamiento;
    }


    void actualizarTabla(const map<string, pair<int, string>>& nuevaTabla){
        tablaDeEnrutamiento = nuevaTabla;
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

    bool removerEnrutador(string nombre){
        if(!existeEnrutador(nombre)){
            cout << "El enrutador no existe." << endl;
            return false;
        }
        enrutadores.erase(nombre);
        for(auto& par : enrutadores) {
            par.second.eliminarRuta(nombre);
        }
        return true;
    }

    void mostrarTablas(){
        for(auto& par : enrutadores){
            par.second.mostrarTabla();
        }
    }

    /*/map<string, Enrutador> getEnrutadores(){
        return enrutadores;
    }/*/

    void archivo(const string& archivo) {
        ifstream file(archivo);
        if(!file) {
            cout << "No se pudo abrir el archivo." << endl;
            return;
        }
        string nombre, destino, salto;
        int costo;
        while (file >> nombre >> destino >> salto >> costo) {
            if (enrutadores.find(nombre) == enrutadores.end()) {
                enrutadores[nombre] = Enrutador(nombre);
            }
            if (enrutadores.find(destino) == enrutadores.end()) {
                enrutadores[destino] = Enrutador(destino);
            }
            enrutadores[nombre].agregarRuta(destino, costo);
            enrutadores[destino].agregarRuta(nombre, costo);
        }

        file.close();
        cout << "Archivo cargado exitosamente.\n";
    }

    vector<string> caminoCompleto(const string &origen, const string &destino, int &costoTotal){
        vector<string> camino;
        costoTotal = 0;
        if(enrutadores.count(origen)){
            string actual = origen;
            while(actual != destino){
                camino.push_back(actual);
                auto tablaOrigen = enrutadores.at(actual).getTablaDeEnrutamiento();
                if(tablaOrigen.count(destino)){
                    string siguienteSalto = tablaOrigen.at(destino).second;
                    int costoSalto = tablaOrigen.at(siguienteSalto).first;
                    cout << "Desde " << actual << " a " << siguienteSalto << " con costo: " << costoSalto;
                    costoTotal += costoSalto;
                    actual = siguienteSalto;
                }else {
                    camino.clear();
                    break;
                }
            }
            if(!camino.empty()){
                camino.push_back(destino);
            }
        }
        return camino;
    }

    void caminoPaquete(const string& origen, const string& destino){
        int costoTotal = 0;
        vector<string> camino = caminoCompleto(origen, destino, costoTotal);
        if(!camino.empty()){
            cout << "Camino desde " << origen << " a " << destino << " Costo: " << costoTotal << ": ";
            for(const auto &nodo : camino) {
                cout << nodo << (nodo == destino ? "\n" : " -> ");
            }
        }else{
            cout << "No hay ruta";
        }
    }
};

int main() {
    Red red;
    int opcion;
    do {
        cout << "\n----- Menu ----"<< endl;
        cout << "1. Agregar Enrutador" << endl;
        cout << "2. Remover Enrutador" << endl;
        cout << "3. Mostrar Tablas de Enrutamiento" << endl;
        cout << "4. Agregar enlace" << endl;
        cout << "5. Cargar desde archivo" << endl;
        cout << "6. Calcular costo" << endl;
        cout << "7. Camino eficiente" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        string nombre;
        switch (opcion) {
        case 1: {
            cout << "Ingrese nombre del Enrutador: ";
            cin >> nombre;
            if (red.agregarEnrutador(Enrutador(nombre))) {
                cout << "Enrutador " << nombre << " agregado exitosamente." << endl;
            }
            break;
        }
        case 2: {
            cout << "Ingrese el nombre del enrutador a eliminar: ";
            cin >> nombre;
            if (red.removerEnrutador(nombre)) {
                cout << "Enrutador " << nombre << " eliminado exitosamente." << endl;
            }
            break;
        }
        case 3:
            red.mostrarTablas();
            break;
        case 4: {
            string origen, destino;
            int costo;
            cout << "Ingrese el Enrutador origen: ";
            cin >> origen;
            cout << "Ingrese el Enrutador destino: ";
            cin >> destino;
            cout << "Ingrese el costo del enlace: ";
            cin >> costo;
            red.agregarEnlace(origen, destino, costo);
            cout << "Enlace agregado exitosamente.\n";
            break;
        }
        case 5: {
            cout << "Ingrese el nombre del archivo: ";
            cin >> nombre;
            red.archivo(nombre);
            break;
        }
        case 6: {
            string origen, destino;
            cout << "Ingrese el Enrutador origen: ";
            cin >> origen;
            cout << "Ingrese el Enrutador destino: ";
            cin >> destino;
            red.caminoPaquete(origen, destino);
            break;
        }
        case 7:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 7);
    return 0;
}
