#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readByCharacter(const string& filename, string& binario);
void readByLineAndEncode(const string& filename, string& binario);
string convertirABinario(char ch);
char convertirATexto(string binario);
string codificarMetodo1(string binario);
string decodificarMetodo1(string binario);
string codificarMetodo2(string binario);
string decodificarMetodo2(string binario);
void ejercicio1();
void ejercicio2();
void aplicacion();

int main()
{
    char opcion;
    do {
        cout << "\n======= MENÚ PRINCIPAL =======" << endl;
        cout << "1. Banco" << endl;
        cout << "2. Codificar archivo" << endl;
        cout << "3. Decodificar archivo" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case '1': aplicacion(); break;
            case '2': ejercicio1(); break;
            case '3': ejercicio2(); break;
            case '4': cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opción inválida.\n"; break;
        }
    } while (opcion != '4');
    return 0;
}

//Function to read a file character by character
void readByCharacter(const string& filename, string& binario)
{
    ifstream file(filename, ios::binary);
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

void readByLine(const string& filename, string& binario)
{
    ifstream file(filename);  // Abrir el archivo
    if (!file.is_open()) {  // Verificar si se abrió correctamente
        throw runtime_error("No se pudo abrir el archivo para lectura línea por línea.");
    }

    string linea;
    //int lineCount = 1;  // Contador de líneas
    while (getline(file, linea)) {  // Leer línea por línea
        //cout << "Leyendo línea " << lineCount++ << ": " << linea << endl;

        // Codificar cada carácter de la línea a binario
        for (char ch : linea) {
            binario += convertirABinario(ch);  // Convertir cada carácter a binario
        }

        // Agregar un salto de línea codificado al final de cada línea
        binario += convertirABinario('\n');
    }

    file.close();  // Cerrar el archivo después de procesarlo
}



string convertirABinario(char ch)
{
    short binario[8];
    int valorASCII = static_cast<unsigned char>(ch);
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

char convertirATexto(string binario)
{
    int valorASCII = 0;
    for(int i = 0; i < 8; i++){
        if(binario[i] == '1'){
            valorASCII += (1 << (7 - i));
        }
    }
    return static_cast<char>(valorASCII);
}

string codificarMetodo1(string binario)
{
    size_t N;
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
string decodificarMetodo1(string codificado)
{
    size_t N;
    cout << "Ingrese el tamaño de los bloques (semilla): ";
    cin >> N;
    string binario = "";
    for(size_t i = 0; i < codificado.length(); i += N){
        string bloque = codificado.substr(i, N);
        string bloqueDecodificado = "";
        if(i == 0){
            //En el primer bloque se cambian todos los 1 por 0 y viceversa.
            for(char bit : bloque){
                if(bit == '0'){
                    bloqueDecodificado += '1';
                } else{
                    bloqueDecodificado += '0';
                }
            }
        }
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
                for(char bit : bloque){
                    if(bit == '0'){
                        bloqueDecodificado += '1';
                    }else{
                        bloqueDecodificado += '0';
                    }
                }
            }
            //Si hay mayor cantidad de 0s se invierte cada 2 bits.
            else if(contadorCeros > contadorUnos){
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 2 == 0){
                        if(bloque[j] == '0'){
                            bloqueDecodificado += '1';
                        } else{
                            bloqueDecodificado += '0';
                        }
                    } else{
                        bloqueDecodificado += bloque[j];
                    }
                }
            }
            //Si hay mayor cantidad de 1s se invierte cada 3 bits.
            else{
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 3 == 0){
                        if(bloque[j] == '0'){
                            bloqueDecodificado += '1';
                        } else{
                            bloqueDecodificado += '0';
                        }
                    } else{
                        bloqueDecodificado += bloque[j];
                    }
                }
            }
        }
        binario += bloqueDecodificado;
    }
    return binario;
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
string decodificarMetodo2(string binario)
{
    size_t N;
    cout << "Ingrese el tamaño de los bloques (semilla): ";
    cin >> N;
    string decodificado = "";

    for (size_t i = 0; i < binario.length(); i += N) {
        string bloque = binario.substr(i, N);
        string original = "";

        if (bloque.length() < N) {
            original = bloque;
        } else {
            // el primer carácter codificado era el último del original
            // por tanto, el original empieza desde el segundo hasta el final, luego el primero del codificado
            for (size_t j = 1; j < bloque.length(); j++) {
                original += bloque[j];
            }
            original += bloque[0];  // el último original era el primero codificado
        }
        decodificado += original;
    }

    return decodificado;
}


string codificarMetodo1admin(string binario, size_t N)
{
    //size_t N = 4; // Valor fijo para el tamaño de los bloques
    string codificado = "";
    for(size_t i = 0; i < binario.length(); i += N){
        string bloque = binario.substr(i, N);
        string bloqueCodificado = "";

        if(i == 0){
            // En el primer bloque se cambian todos los 1 por 0 y viceversa.
            for(char bit : bloque){
                if(bit == '0'){
                    bloqueCodificado += '1';
                } else{
                    bloqueCodificado += '0';
                }
            }
        }
        // Grupos siguientes... bloque anterior del binario SIN CODIFICAR
        else{
            string bloqueAnterior = binario.substr(i - N, N);
            int contadorUnos = 0, contadorCeros = 0;
            for(char bit : bloqueAnterior){
                if(bit == '1'){
                    contadorUnos++;
                } else{
                    contadorCeros++;
                }
            }

            // Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
            if(contadorUnos == contadorCeros){
                for(size_t j = 0; j < bloque.length(); j++){
                    if(bloque[j] == '0'){
                        bloqueCodificado += '1';
                    } else{
                        bloqueCodificado += '0';
                    }
                }
            }
            // Si hay mayor cantidad de 0s se invierte cada 2 bits.
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
            // Si hay mayor cantidad de 1s se invierte cada 3 bits.
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
string decodificarMetodo1admin(string codificado, size_t N)
{
    //size_t N = 4; // Tamaño fijo del bloque (semilla)
    string binario = "";
    for(size_t i = 0; i < codificado.length(); i += N){
        string bloque = codificado.substr(i, N);
        string bloqueDecodificado = "";

        if(i == 0){
            // En el primer bloque se cambian todos los 1 por 0 y viceversa.
            for(char bit : bloque){
                if(bit == '0'){
                    bloqueDecodificado += '1';
                } else{
                    bloqueDecodificado += '0';
                }
            }
        }
        else{
            string bloqueAnterior = binario.substr(i - N, N);
            int contadorUnos = 0, contadorCeros = 0;
            for(char bit : bloqueAnterior){
                if(bit == '1'){
                    contadorUnos++;
                } else{
                    contadorCeros++;
                }
            }

            // Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
            if(contadorUnos == contadorCeros){
                for(char bit : bloque){
                    if(bit == '0'){
                        bloqueDecodificado += '1';
                    } else{
                        bloqueDecodificado += '0';
                    }
                }
            }
            // Si hay mayor cantidad de 0s se invierte cada 2 bits.
            else if(contadorCeros > contadorUnos){
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 2 == 0){
                        if(bloque[j] == '0'){
                            bloqueDecodificado += '1';
                        } else{
                            bloqueDecodificado += '0';
                        }
                    } else{
                        bloqueDecodificado += bloque[j];
                    }
                }
            }
            // Si hay mayor cantidad de 1s se invierte cada 3 bits.
            else{
                for(size_t j = 0; j < bloque.length(); j++){
                    if((j + 1) % 3 == 0){
                        if(bloque[j] == '0'){
                            bloqueDecodificado += '1';
                        } else{
                            bloqueDecodificado += '0';
                        }
                    } else{
                        bloqueDecodificado += bloque[j];
                    }
                }
            }
        }
        binario += bloqueDecodificado;
    }
    return binario;
}


string codificarMetodo2usuarios(string binario, size_t N) {
    string codificado2 = "";
    for (size_t i = 0; i < binario.length(); i += N) {
        string bloque = binario.substr(i, N);
        string nuevo = "";

        if (bloque.length() < N) {
            nuevo = bloque;
        } else {
            nuevo += bloque[bloque.length() - 1];  // Primer bit codificado
            for (size_t j = 0; j < bloque.length() - 1; j++) {
                nuevo += bloque[j];
            }
        }
        codificado2 += nuevo;
    }
    return codificado2;
}
string decodificarMetodo2usuarios(string binario, size_t N)
{
    string decodificado = "";
    for (size_t i = 0; i < binario.length(); i += N) {
        string bloque = binario.substr(i, N);
        string original = "";

        if (bloque.length() < N) {
            original = bloque;
        } else {
            for (size_t j = 1; j < bloque.length(); j++) {
                original += bloque[j];
            }
            original += bloque[0];
        }
        decodificado += original;
    }
    return decodificado;
}

void añadirusuarios(){
    const string archivosUsuarios = "usuarios.txt";
    try {
        // Try to create/overwrite the file first
        ofstream archivoSalida(archivosUsuarios, ios::app);
        if (!archivoSalida)
        {
            throw runtime_error("Failed to create/open file for writing");
        }
        //string inFile;
        string cedula, clave;
        int saldo;
        cout << "Ingrese cedula: ";
        cin >> cedula;
        cout << "Ingrese clave: ";
        cin >> clave;
        cout << "Ingrese saldo: ";
        cin >> saldo;
        archivoSalida << cedula << "," << clave << "," << saldo << endl;
        archivoSalida.close();

    } catch (const ifstream::failure& e) {
        cerr << "\nI/O Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "\nError: " << e.what() << endl;
    } catch (...) {
        cerr << "\nUnknown error occurred while handling the file." << endl;
    }
}

void codificarAdmin(){
    ifstream archivo("admin.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de texto." << endl;
        return;
    }
    string contenido, binario;
    while(getline(archivo, contenido)){
        for(char& c : contenido){
            binario += convertirABinario(c);
        }
        binario += convertirABinario('\n');
    }
    archivo.close();
    size_t N = 4;
    string binarioCodificado = codificarMetodo1admin(binario, N);
    ofstream archivoSalida("sudo.txt", ios::binary);
    if(!archivoSalida.is_open()){
        cerr << "No se pudo abrir el archivo sudo.txt." << endl;
        return;
    }
    for (size_t i = 0; i + 8 <= binarioCodificado.length(); i += 8) {
        char byte = convertirATexto(binarioCodificado.substr(i, 8));
        archivoSalida.write(&byte, 1);
    }
    archivoSalida.close();

    cout << "Archivo 'sudo.txt' generado exitosamente.\n";
}
bool validarAdmnistradores(){
    string codificadoBinario;
    readByCharacter("sudo.txt", codificadoBinario);////////////////////////////////////////////////////////////////////////////////
    size_t N = 4;
    string decodificadoBinario = decodificarMetodo1admin(codificadoBinario, N);
    string textoOriginal;
    for (size_t i = 0; i + 8 <= decodificadoBinario.length(); i += 8) {
        textoOriginal += convertirATexto(decodificadoBinario.substr(i, 8));
    }
    string usuario, clave;
    cout << "Ingrese usuario: ";
    cin >> usuario;
    cout << "Ingrese clave: ";
    cin >> clave;
    //cout << "***** Usuario " << usuario << " *****" << endl;
    string linea = "";
    for (char c : textoOriginal) {
        if (c == '\n') {
            if (linea == (usuario + "," + clave)) {
                return true;
            }
            linea = "";
        } else {
            linea += c;
        }
    }
    if (!linea.empty() && linea == (usuario + "," + clave)) {
        return true;
    }
    return false;
}

void codificarUsuarios(){
    ifstream archivo("usuarios.txt");
    if(!archivo.is_open()){
        cerr << "No se pudo abrir el archivo de texto." << endl;
        return;
    }
    string contenido, binario;
    while(getline(archivo, contenido)){
        for(char& c : contenido){
            binario += convertirABinario(c);
        }
        binario += convertirABinario('\n');
    }
    archivo.close();
    size_t N = 4;
    string binariocodificado = codificarMetodo2usuarios(binario, N);
    ofstream archivosalida("usuarioscode.txt", ios::binary);
    if(!archivosalida.is_open()){
        cerr << "No se pudo abrir el archivo sudo.txt." << endl;
        return;
    }
    for(size_t i = 0; i + 8 <= binariocodificado.length(); i += 8){
        char byte = convertirATexto(binariocodificado.substr(i, 8));
        archivosalida.write(&byte, 1);
    }
    archivosalida.close();
    cout << "Archivo 'usuarioscode.txt' generado exitosamente.\n";
}
bool validarUsuarios(){
    string codificadobinario;
    readByCharacter("usuarioscode.txt", codificadobinario);
    size_t N = 4;
    string decodificadoBinario = decodificarMetodo2usuarios(codificadobinario, N);
    string textoOriginal;
    for(size_t i = 0; i + 8 <= decodificadoBinario.length(); i += 8){
        textoOriginal += convertirATexto(decodificadoBinario.substr(i, 8));
    }
    string cedula, claveU;
    //int saldo;
    cout << "Ingrese cedula: ";
    cin >> cedula;
    cout << "Ingrese clave: ";
    cin >> claveU;
    string linea = "";
    for (char c : textoOriginal) {
        if (c == '\n') {
            size_t ce = linea.find(',');
            size_t cl = linea.find(',', ce + 1);
            if(ce != string::npos && cl != string::npos){
                string cedularchivo = linea.substr(0, ce);
                string clavearchivo = linea.substr(ce + 1, cl - ce - 1);
                string saldoarchivo = linea.substr(cl + 1);
                if (cedula == cedularchivo && claveU == clavearchivo) {
                    saldocuenta = saldoarchivo;
                    return true;
                }
            }
            linea = "";
        } else {
            linea += c;
        }
    }
    if (!linea.empty()) {
        size_t p1 = linea.find(',');
        size_t p2 = linea.find(',', p1 + 1);
        if (p1 != string::npos && p2 != string::npos) {
            string cedulaArchivo = linea.substr(0, p1);
            string claveArchivo = linea.substr(p1 + 1, p2 - p1 - 1);

            if (cedula == cedulaArchivo && claveU == claveArchivo) {
                return true;
            }
        }
    }
    return false;
}

void consultarSaldo(){

}

void retirarDinero(){

}

void aplicacion()
{
    char opcion;
    do {
        cout << "\n======= BANCO =======" << endl;
        cout << "1. Ingresar como Administrador" << endl;
        cout << "2. Ingresar como Usuario" << endl;
        cout << "3. Back" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
        case '1':
            codificarAdmin();
            if(validarAdmnistradores()){
                cout << "\n*****************************" << endl;
                cout << "\n*    MENU ADMINISTRADOR     *" << endl;
                cout << "\n*****************************" << endl;
                char opcionadmin;
                do {
                    cout << "\n1. Añadir usuario" << endl;
                    cout << "2. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcionadmin;
                    switch (opcionadmin) {
                    case '1':
                        añadirusuarios();
                        break;
                    case '2':
                        break;
                    default:
                        cout << "Opcion no valida";
                        break;
                    }
                }while(opcionadmin != '2');
            }else{
                cout << "Usuario o clave incorrectos";
            }
            break;
        case '2':
            string saldo;
            codificarUsuarios();
            if(validarUsuarios()){
                cout << "\n*****************************" << endl;
                cout << "\n*       MENU USUARIOS       *" << endl;
                cout << "\n*****************************" << endl;
                char opcionusuario;
                do {
                    cout << "1. Consultar saldo" << endl;
                    cout << "2. Retirar dinero" << endl;
                    cout << "3. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcionusuario;
                    switch (opcionusuario) {
                    case '1':

                        break;
                    case '2':
                        retirarDinero();
                        break;
                    default:
                        cout << "Opcion no valida";
                        break;
                    }
                }while(opcionusuario != '3');
            }else{
                cout << "cedula o clave incorrectos";
            }
        }
    } while(opcion != '3');
}





















































void ejercicio1()
{
    char opcion;
    string inFile, outFile;
    string binario = "";
    string codificado = "";
    string codificado2 = "";
    do {
        cout << "\n==== Codificar archivos de Texto ====" << endl;
        cout << "1. Primer Metodo." << endl;
        cout << "2. Segundo Metodo." << endl;
        cout << "3. Salir." << endl;
        cout << "Seleccione el metodo para codificar: ";
        cin >> opcion;
        switch (opcion) {
        case '1':
            binario.clear();
            codificado.clear();
            try {
                cout << "\nIngrese el nombre del archivo a leer: ";
                cin >> inFile;
                cout << "Ingrese el nombre del archivo de salida (binario): ";
                cin >> outFile;
                // Read the file using different methods
                readByCharacter(inFile, binario);
                cout << "El archivo en binario seria: " << binario << endl;
                codificado = codificarMetodo1(binario);//Llamado Funcion Metodo 1
                cout << "El archivo codificado por el metodo 1 seria: " << codificado << endl;

                ofstream archivoSalida(outFile, ios::binary);
                if (archivoSalida.is_open()) {
                    for (size_t i = 0; i + 8 <= codificado.length(); i += 8) {
                        string byteStr = codificado.substr(i, 8);
                        char byte = convertirATexto(byteStr);
                        archivoSalida.write(&byte, sizeof(char));
                    }
                    archivoSalida.close();
                    cout << "El resultado se guardo en " << outFile << endl;
                } else {
                    cerr << "No se pudo abrir el archivo para la codificacion." << endl;
                }
            } catch (const ifstream::failure& e) {
                cerr << "\nI/O Error: " << e.what() << endl;
            } catch (const runtime_error& e) {
                cerr << "\nError: " << e.what() << endl;
            } catch (...) {
                cerr << "\nUnknown error occurred while handling the file." << endl;
            }
            break;
        case '2':
            binario.clear();
            codificado2.clear();
            try {
                cout << "\nIngrese el nombre del archivo a leer: ";
                cin >> inFile;
                cout << "Ingrese el nombre del archivo de salida (binario): ";
                cin >> outFile;
                // Read the file using different methods
                readByLine(inFile, binario);
                cout << "El archivo en binario seria: " << binario << endl;
                codificado2 = codificarMetodo2(binario);//Llamado Funcion Metodo 2
                cout << "El archivo codificado por el metodo 2 seria: " << codificado2 << endl;
                ofstream archivoSalida(outFile, ios::binary);
                if (archivoSalida.is_open()) {
                    for (size_t i = 0; i < codificado2.length(); i += 8) {
                        string byteStr = codificado2.substr(i, 8);
                        if (byteStr.length() < 8) {
                            byteStr.append(8 - byteStr.length(), '0'); // Rellenar con ceros si falta
                        }
                        char byte = convertirATexto(byteStr);
                        archivoSalida.write(&byte, 1); // Escribir 1 byte
                    }
                    archivoSalida.close();
                    cout << "El resultado se guardó en " << outFile << " como binario codificado." << endl;
                } else {
                    cerr << "No se pudo abrir el archivo para la codificación." << endl;
                }
            } catch (const ifstream::failure& e) {
                cerr << "\nI/O Error: " << e.what() << endl;
            } catch (const runtime_error& e) {
                cerr << "\nError: " << e.what() << endl;
            } catch (...) {
                cerr << "\nUnknown error occurred while handling the file." << endl;
            }
            break;
        case '3':
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != '3');
}

void ejercicio2()
{
    char opcion;
    string inFile, outFile;
    string binario = "";
    string decodificado = "";
    string decodificado2 = "";
    string texto = "";

    do {
        cout << "\n==== Decodificar archivos de Texto ====" << endl;
        cout << "1. Primer Metodo." << endl;
        cout << "2. Segundo Metodo." << endl;
        cout << "3. Salir." << endl;
        cout << "Seleccione el metodo para decodificar: ";
        cin >> opcion;
        switch (opcion) {
        case '1':
            binario.clear();
            decodificado.clear();
            texto.clear();
            try {
                cout << "\nIngrese el nombre del archivo codificado (binario): ";
                cin >> inFile;
                cout << "Ingrese el nombre del archivo de salida (texto decodificado): ";
                cin >> outFile;
                // Leer el archivo codificado en binario (caracteres)
                {
                    ifstream archivoEntrada(inFile, ios::binary);
                    if (!archivoEntrada.is_open()) {
                        throw runtime_error("No se pudo abrir el archivo de entrada.");
                    }
                    char ch;
                    while (archivoEntrada.get(ch)) {
                        binario += convertirABinario(ch);
                    }
                    archivoEntrada.close();
                }
                // Decodificar con el método 1
                decodificado = decodificarMetodo1(binario);
                // Convertir el binario a texto real
                for (size_t i = 0; i + 8 <= decodificado.length(); i += 8) {
                    string byteStr = decodificado.substr(i, 8);
                    texto += convertirATexto(byteStr);
                }
                // Guardar el texto en el archivo de salida
                ofstream archivoSalida(outFile);
                if (!archivoSalida.is_open()) {
                    throw runtime_error("No se pudo abrir el archivo de salida.");
                }
                archivoSalida << texto;
                archivoSalida.close();
                cout << "Texto decodificado guardado exitosamente en " << outFile << endl;
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case '2':
            binario.clear();
            decodificado2.clear();
            texto.clear();
            try {
                cout << "\nIngrese el nombre del archivo codificado (binario): ";
                cin >> inFile;
                cout << "Ingrese el nombre del archivo de salida (texto decodificado): ";
                cin >> outFile;
                // Leer el archivo codificado en binario (caracteres)
                {
                    ifstream archivoEntrada(inFile, ios::binary);
                    if (!archivoEntrada.is_open()) {
                        throw runtime_error("No se pudo abrir el archivo de entrada.");
                    }
                    char ch;
                    while (archivoEntrada.get(ch)) {
                        binario += convertirABinario(ch);
                    }
                    archivoEntrada.close();
                }
                // Decodificar con el método 1
                decodificado2 = decodificarMetodo2(binario);
                // Convertir el binario a texto real
                for (size_t i = 0; i + 8 <= decodificado2.length(); i += 8) {
                    string byteStr = decodificado2.substr(i, 8);
                    texto += convertirATexto(byteStr);
                }
                // Guardar el texto en el archivo de salida
                ofstream archivoSalida(outFile);
                if (!archivoSalida.is_open()) {
                    throw runtime_error("No se pudo abrir el archivo de salida.");
                }
                archivoSalida << texto;
                archivoSalida.close();
                cout << "Texto decodificado guardado exitosamente en " << outFile << endl;
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case '3':
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (opcion != '3');
}
