#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readByCharacter(const string& filename, string& binario);
string convertirABinario(char ch);
void codificarMetodo2(string binario, int N, const string& outFile);

int main() {
    string inFile, outFile;
    string binario = "";
    int N;

    try {
        cout << "Ingrese el nombre del archivo fuente: ";
        cin >> inFile;

        cout << "Ingrese el nombre del archivo de salida: ";
        cin >> outFile;

        // Leer el archivo y convertirlo a binario
        readByCharacter(inFile, binario);
        cout << "El archivo en binario seria: " << binario << endl;

        // Pedir el tamaño de los bloques
        cout << "Ingrese el tamaño de los bloques: ";
        cin >> N;

        // Codificar el binario con el segundo método
        codificarMetodo2(binario, N, outFile);
        cout << "El archivo ha sido codificado y guardado como " << outFile << endl;

    } catch (const ifstream::failure& e) {
        cerr << "\nI/O Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "\nError: " << e.what() << endl;
    } catch (...) {
        cerr << "\nUnknown error occurred while handling the file." << endl;
    }

    return 0;
}

// Función para leer el archivo y convertirlo a binario
void readByCharacter(const string& filename, string& binario) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for character-by-character reading");
    }

    char ch;
    while (file.get(ch)) {
        binario += convertirABinario(ch);
    }
    file.close();
}

// Función para convertir un carácter a binario
string convertirABinario(char ch) {
    string resultado = "";
    for (int i = 7; i >= 0; i--) {
        resultado += ((ch >> i) & 1) ? '1' : '0';
    }
    return resultado;
}

// Método para codificar el binario desplazando los bits dentro de los bloques
void codificarMetodo2(string binario, int N, const string& outFile) {
    // Crear archivo binario de salida
    ofstream file(outFile, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Failed to open the output file");
    }

    // Procesar en bloques de tamaño N
    for (size_t i = 0; i < binario.length(); i += N) {
        string bloque = binario.substr(i, N);

        // Desplazar los bits de cada bloque
        string bloqueCodificado = "";
        for (int j = N - 1; j >= 0; j--) {
            bloqueCodificado += bloque[j];
        }

        // Guardar el bloque codificado en el archivo binario de salida
        for (char c : bloqueCodificado) {
            file.put(c == '1' ? 1 : 0);  // Escribir 1 o 0 en el archivo
        }
    }

    file.close();
}
