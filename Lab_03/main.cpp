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
    string anterior = "";
    for(size_t i = 0; i < binario.length(); i += N){
        string bloque = binario.substr(i,N);
        string bloqueCodificado = bloque;
        if(anterior.empty()) {
            for(int j = 0; j < bloqueCodificado.length(); ++j){
                if(bloqueCodificado[j] == '1'){
                    bloqueCodificado[j] = '0';
                }else{
                    bloqueCodificado[j] = '1';
                }
            }
        }else{
            //Para los grupos siguientes se
            //debe contar el número de 1s y 0s en el grupo anterior
            int contadorUnos = 0, contadorCeros = 0;
            for(char caracter : anterior){
                if(caracter == '1'){
                    contadorUnos++;
                }else{
                    contadorCeros++;
                }
            }
            //Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
            if(contadorUnos == contadorCeros){
                for(int j = 0; j < bloqueCodificado.length(); ++j){
                    if(bloqueCodificado[j] == '1'){
                        bloqueCodificado[j] = '0';
                    }else{
                        bloqueCodificado[j] = '1';
                    }
                }
            }else if(contadorCeros > contadorUnos){
                for(int j = 0; j < bloqueCodificado.length(); j+=2){
                    if(bloqueCodificado[j] == '1'){
                        bloqueCodificado[j] = '0';
                    }else{
                        bloqueCodificado[j] = '1';
                    }
                }
            }else{
                for(int j = 0; j < bloqueCodificado.length(); j+=3){
                    if(bloqueCodificado[j] == '1'){
                        bloqueCodificado[j] = '0';
                    }else{
                        bloqueCodificado[j] = '1';
                    }
                }
            }
        }
        codificado += bloqueCodificado;
        anterior = bloque;
    }
    return codificado;
}
