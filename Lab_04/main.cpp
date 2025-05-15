#include "Red.h"

int main() {
    Red red;
    int opcion;
    string nombre, destino, siguiente;
    int costo;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar Enrutador\n";
        cout << "2. Eliminar Enrutador\n";
        cout << "3. Agregar Ruta\n";
        cout << "4. Mostrar Red\n";
        cout << "5. Mostrar Tablas\n";
        cout << "6. Cargar desde archivo\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            cout << "Ingrese nombre del enrutador: ";
            cin >> nombre;
            if (!red.validacionEnrutador(nombre)) {
                red.agregarEnrutador(Enrutador(nombre));
                cout << "Enrutador agregado.\n";
            } else {
                cout << "Ya existe un enrutador con ese nombre.\n";
            }
            break;
        case 2:
            cout << "Ingrese nombre del enrutador a eliminar: ";
            cin >> nombre;
            if (red.validacionEnrutador(nombre)) {
                red.removerEnrutador(nombre);
                cout << "Enrutador eliminado.\n";
            } else {
                cout << "No existe ese enrutador.\n";
            }
            break;

        case 3:
            cout << "Nombre del enrutador origen: ";
            cin >> nombre;
            if (!red.validacionEnrutador(nombre)) {
                cout << "Enrutador no encontrado.\n";
                break;
            }
            cout << "Destino: ";
            cin >> destino;
            cout << "Siguiente salto: ";
            cin >> siguiente;
            cout << "Costo: ";
            cin >> costo;
            red.obtenerEnrutador(nombre).agregarRuta(destino, siguiente, costo);
            cout << "Ruta agregada.\n";
            break;
        case 4:
            red.mostrarRed();
            break;
        case 5:
            red.mostrarTablas();
            break;
        case 6:
            cout << "Nombre del archivo: ";
            cin >> nombre;
            red.cargarDesdeArchivo(nombre);
            break;
        case 7:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (opcion != 7);
    return 0;
}
