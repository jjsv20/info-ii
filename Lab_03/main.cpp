#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readByCharacter(const string& filename, string& binario);
string convertirABinario(char ch);
string codificarMetodo1(string binario);

int main()
{
    //const string outFile = "ejemplo.txt";
    string inFile;
    string binario = "";
    string codificado = "";

    try {
        cout << "Ingrese el nombre del archivo a leer: ";
        cin >> inFile;
        // Read the file using different methods
        readByCharacter(inFile, binario);
        cout << "El archivo en binario seria: " << binario << endl;
        codificado = codificarMetodo1(binario);
        cout << "El archivo codificado seria: " << codificado << endl;
    } catch (const ifstream::failure& e) {
        cerr << "\nI/O Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "\nError: " << e.what() << endl;
    } catch (...) {
        cerr << "\nUnknown error occurred while handling the file." << endl;
    }

    return 0;
}

// Function to read a file character by character
void readByCharacter(const string& filename, string& binario)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Failed to open file for character-by-character reading");
    }

    char ch;
    cout << "\nReading '" << filename << "' character by character:\n";
    while (file.get(ch))
    {
        binario += convertirABinario(ch);
    }
    file.close();
}

string convertirABinario(char ch)
{
    short binario[8];
    int valorASCII = static_cast<int>(ch);
    for(int i = 0; i < 8; i++){
        binario[i] = valorASCII % 2;
        valorASCII /= 2;
    }
    string resultado = "";
    for(int i = 7; i >= 0; i--){
        resultado += to_string(binario[i]);
    }
    return resultado;
}

string codificarMetodo1(string binario)
{
    int N;
    cout << "Ingrese el tamaño de los bloques: ";
    cin >> N;
    string codificado = "";

    // Imprimir la cadena binaria separada en bloques de N bits
    cout << "\nCadena binaria separada en bloques de " << N << " bits:\n";
    string binarioConEspacios = "";
    for(size_t i = 0; i < binario.length(); i++){
        binarioConEspacios += binario[i];
        // Añadir un espacio después de cada grupo de N bits (excepto al final)
        if((i + 1) % N == 0 && i < binario.length() - 1){
            binarioConEspacios += " ";
        }
    }
    cout << binarioConEspacios << endl;

    cout << "\nProceso de codificación detallado:\n";

    // Procesamiento de la codificación según las reglas correctas
    for(size_t i = 0; i < binario.length(); i += N){
        // Obtener el bloque actual (si es el último bloque puede ser menor que N)
        string bloque = binario.substr(i, N);
        string bloqueModificado = "";

        // Si es el primer bloque, invertimos todos los bits
        if(i == 0){
            for(char bit : bloque){
                bloqueModificado += (bit == '0') ? '1' : '0';
            }
            cout << "Bloque 1 (" << bloque << "): Invirtiendo todos los bits -> " << bloqueModificado << endl;
        }
        // Para los bloques siguientes
        else{
            // Obtenemos el bloque anterior del binario SIN CODIFICAR para analizar
            string bloqueAnterior = binario.substr(i - N, N);

            // Contar 1s y 0s en el bloque anterior
            int unos = 0;
            int ceros = 0;
            for(char bit : bloqueAnterior){
                if(bit == '1') unos++;
                else ceros++;
            }

            int numeroBloque = (i/N) + 1;

            // Determinar la regla a aplicar basada en la cantidad de 1s y 0s
            if(unos == ceros){
                cout << "Bloque " << numeroBloque << " (" << bloque << "): El bloque anterior tiene " << unos << " unos y " << ceros << " ceros (iguales). Invirtiendo cada bit." << endl;
                // Si hay igual cantidad de 1s y 0s: invertir cada bit
                for(size_t j = 0; j < bloque.length(); j++){
                    bloqueModificado += (bloque[j] == '0') ? '1' : '0';
                }
            }
            else if(ceros > unos){
                cout << "Bloque " << numeroBloque << " (" << bloque << "): El bloque anterior tiene " << unos << " unos y " << ceros << " ceros (más ceros). Invirtiendo cada 2 bits." << endl;
                // Si hay más 0s: invertir cada 2 bits (CORREGIDO: es cada segundo bit)
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j+1) % 2 == 0){ // Posiciones 1, 3, 5... (cada segundo bit)
                        bloqueModificado += (bloque[j] == '0') ? '1' : '0';
                    }
                    else{
                        bloqueModificado += bloque[j];
                    }
                }
            }
            else{ // unos > ceros
                cout << "Bloque " << numeroBloque << " (" << bloque << "): El bloque anterior tiene " << unos << " unos y " << ceros << " ceros (más unos). Invirtiendo cada 3 bits." << endl;
                // Si hay más 1s: invertir cada 3 bits (CORREGIDO: es cada tercer bit)
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j+1) % 3 == 0){ // Posiciones 2, 5, 8... (cada tercer bit)
                        bloqueModificado += (bloque[j] == '0') ? '1' : '0';
                    }
                    else{
                        bloqueModificado += bloque[j];
                    }
                }
            }

            cout << "   Resultado: " << bloqueModificado << endl;
        }

        // Añadir el bloque modificado al resultado
        codificado += bloqueModificado;
    }

    return codificado;
}
