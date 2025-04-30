#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readByCharacter(const string& filename, string& binario);
string convertirABinario(char ch);

int main()
{
    //const string outFile = "ejemplo.txt";
    string inFile;
    string binario = "";

    try {
        cout << "Ingrese el nombre del archivo a leer: ";
        cin >> inFile;

        // Read the file using different methods
        readByCharacter(inFile, binario);
        cout << binario << endl;

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
        binario += convertirABinario(ch) + "";
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
