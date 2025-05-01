#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readByCharacter(const string& filename, string& binario);
string convertirABinario(char ch);
string codificarMetodo1(string binario);
string codificarMetodo2(string binario);

int main()
{
    //const string outFile = "ejemplo.txt";
    string inFile;
    string binario = "";
    string codificado = "";
     string codificado2 = "";

    try {
        cout << "Ingrese el nombre del archivo a leer: ";
        cin >> inFile;

        // Read the file using different methods
        readByCharacter(inFile, binario);
        cout << "El archivo en binario seria: " << binario << endl;

        codificado = codificarMetodo1(binario);
        cout << "El archivo codificado por el metodo 1 seria: " << codificado << endl;

        codificado2 = codificarMetodo2(binario);
        cout << "El archivo codificado por el metodo 2 seria: " << codificado2 << endl;

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
    for(size_t i = 0; i < binario.length(); i += N){
        string bloque = binario.substr(i,N);
        string bloqueCodificado = "";

        if(i == 0){
            //En el primer bloque se cambian todos los 1 por 0 y viceversa.
            for(char bit : bloque){
                if(bit == '0'){
                    bloqueCodificado += '1';
                } else{
                    bloqueCodificado += '0';
                }
            }
        }
        //Grupos siguientes... bloque anterior del binario SIN CODIFICAR
        else{
            string bloqueAnterior = binario.substr(i - N, N);
            //contar el número de 1s y 0s en el grupo anterior
            int contadorUnos = 0, contadorCeros = 0;
            for(char bit : bloqueAnterior){
                if(bit == '1'){
                    contadorUnos++;
                }else{
                    contadorCeros++;
                }
            }
            //Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
            if(contadorUnos == contadorCeros){
                for(size_t j = 0; j < bloque.length(); j++){
                    if(bloque[j] == '0'){
                        bloqueCodificado += '1';
                    }else{
                        bloqueCodificado += '0';
                    }
                }
            }
            //Si hay mayor cantidad de 0s se invierte cada 2 bits.
            else if(contadorCeros > contadorUnos){
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 2 == 0){
                        if(bloque[j] == '0'){
                            bloqueCodificado += '1';
                        } else{
                            bloqueCodificado += '0';
                        }
                    } else{
                        bloqueCodificado += bloque[j];
                    }
                }
            }
            //Si hay mayor cantidad de 1s se invierte cada 3 bits.
            else{
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 3 == 0){
                        if(bloque[j] == '0'){
                            bloqueCodificado += '1';
                        } else{
                            bloqueCodificado += '0';
                        }
                    } else{
                        bloqueCodificado += bloque[j];
                    }
                }
            }
        }
        codificado += bloqueCodificado;
    }
    return codificado;
}

string codificarMetodo2(string binario)
{
    size_t N;
    cout << "Ingrese el tamaño de los bloques: ";
    cin >> N;
    string codificado2 = "";
    for(size_t i = 0; i < binario.length(); i += N){
        string bloque = binario.substr(i, N);
        string nuevo = "";

        if (bloque.length() < N) {
            nuevo = bloque;
        } else {
            //primer bit del grupo codificado corresponde al último bit del grupo sin codificar,
            nuevo += bloque[bloque.length() - 1];
            //el segundo bit codificado corresponde al primero sin
            //codificar y así sucesivamente hasta que el último corresponde al penúltimo sin codificar.
            for (size_t j = 0; j < bloque.length() - 1; j++) {
                nuevo += bloque[j];
            }
        }
        codificado2 += nuevo;
    }
    return codificado2;
}
