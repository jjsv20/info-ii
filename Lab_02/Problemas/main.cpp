#include <iostream>
using namespace std;
#include <cstring>
#include <iomanip> //espaciado matriz problema14
#include <cstdlib>
#include <ctime>

void problema1();//

void problema2();//

bool problema3();//

void problema4();//

void problema5();//

void problema6();//

void problema7();//

void problema8();//
void problema8puntero();//

void problema9();//

void problema10();//

void problema11();//

bool problema12();//

void problema13();//

void problema14();//

void problema15();//

void problema16();//

void problema17();//

void problema18();//



int main()
{
    problema10();
    return 0;
}



void problema1()
{
    int cantidad, billetesUsados, monedasUsadas;
    int billetes[6] = {50000,20000,10000,5000,2000,1000};
    int monedas[4] = {500,200,100,50};
    cout << "Ingrese una cantidad de dinero: ";
    cin >> cantidad;
    for(int i = 0; i < 6; i++){
        billetesUsados = cantidad / billetes[i];
        cout << billetes[i] << ": " << billetesUsados << endl;
        cantidad = cantidad % billetes[i];
    }
    for(int j = 0; j < 4; j++) {
        monedasUsadas = cantidad / monedas[j];
        cout << monedas[j] << ": " << monedasUsadas << endl;
        cantidad = cantidad % monedas[j];
    }
    if(cantidad > 0) {
        cout << "Faltante: " << cantidad << endl;
    }
}


/*/void setup() {//Problema 1 - Arduino
    Serial.begin(9600);
    while (!Serial);
    long cantidad, billetesUsados, monedasUsadas;
    long billetes[6] = {50000, 20000, 10000, 5000, 2000, 1000};
    long monedas[4] = {500, 200, 100, 50};
    Serial.println("Ingrese una cantidad de dinero (positivo): ");
    while (Serial.available() == 0) {
    }
    cantidad = Serial.parseInt();
    if (cantidad <= 0) {
        Serial.println("Por favor, ingrese una cantidad positiva.");
        return;
    }
    for (int i = 0; i < 6; i++) {
        billetesUsados = cantidad / billetes[i];
        Serial.print(billetes[i]);
        Serial.print(": ");
        Serial.println(billetesUsados);
        cantidad = cantidad % billetes[i];
        if (cantidad <= 0) {
            break;
        }
    }
    if (cantidad > 0) {
        for (int j = 0; j < 4; j++) {
            monedasUsadas = cantidad / monedas[j];
            Serial.print(monedas[j]);
            Serial.print(": ");
            Serial.println(monedasUsadas);
            cantidad = cantidad % monedas[j];
            if (cantidad <= 0) {
                break;
            }
        }
    }
    if (cantidad > 0) {
        Serial.print("Faltante: ");
        Serial.println(cantidad);
    }
}
void loop() {
    //solo se ejcuta una vez
}/*/


void problema2()
{
    char letras[200];
    int repeticion[26] = {0};
    srand(time(0)); //numero aleatorio
    for(int i = 0; i < 200; i++){
        letras[i] = 'A' + rand() % 26;
        repeticion[letras[i] - 'A']++;
    }
    cout << "Arreglo: ";
    for(int i = 0; i < 200; i++){
        cout << letras[i];
    }
    cout << endl;
    for(int i = 0; i < 26; i++){
        if(repeticion[i] > 0){
            cout << char('A' + i) << ": " << repeticion[i] << endl;
        }
    }
}

bool problema3()
{
    char cadena1[100], cadena2[100];
    cout << "Ingrese la primera cadena: ";
    cin.getline(cadena1, 100);
    cout << "Ingrese la segunda cadena: ";
    cin.getline(cadena2, 100);

    if(strlen(cadena1) == strlen(cadena2)) {
        //cout << "Igual longitud";
        bool son_iguales = true;
        for(int i = 0; i < strlen(cadena1); i++){
            if(cadena1[i] != cadena2[i]){
                son_iguales = false;
                break;
            }
        }
        if(son_iguales){
            cout << "Las cadenas son iguales." << endl;
            return true;
        }else{
            cout << "Las cadenas no son iguales." << endl;
            return false;
        }
    }
    cout << "Las cadenas no son iguales." << endl;
    return false;
}

void problema4()
{
    char cadenanum[100];
    char *p = cadenanum;
    int numero = 0;
    cout << "Ingrese una cadena de caracteres: ";
    cin >> cadenanum;
    while(*p){
        numero = numero * 10 + (*p - '0');
        p++;
    }
    cout << "Numero entero: " << numero;
}

void problema5()
{
    int numero;
    char cadena[100];
    int j = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;
    if(numero == 0){
        cadena[j++] = '0';
    }
    while(numero > 0){
        cadena[j++] = (numero % 10) + '0';
        numero /= 10;
    }
    cadena[j] = '\0';
    for(int k = 0; k < j/2; k++){
        swap(cadena[k], cadena[j - 1 - k]);
    }

    cout << "Cadena: " << cadena << endl;
}

void problema6()
{
    char cadena_caracteres[100];
    char cadenacopia[100];
    cout << "Ingrese una cadena: ";
    cin >> cadena_caracteres;
    strcpy(cadenacopia, cadena_caracteres);
    for (int i = 0; i < strlen(cadena_caracteres); i++) {
        if (cadena_caracteres[i] >= 'a' && cadena_caracteres[i] <= 'z') {
            cadena_caracteres[i] -= 32;
        }
    }
    cout << "Original: " << cadenacopia << ". En mayuscula: " << cadena_caracteres << endl;
}


/*/void setup(){Problema 6 - Arduino
    Serial.begin(9600);
    while(!Serial);
    char candena_caracteres[100];
    char cadenacopia[100];
    int indice = 0;
    Serial.println("Ingrese una cadena: ");
    while(Serial.available() == 0){
    }
    while(Serial.available() > 0 && indice < 99){
        char c = Serial.read();
        if(c = '\n') {
            break;
        }
        cadena_caracteres[indice++] = c;
        delay(10);
    }
    cadena_caracteres[indice] = '\0';
    strcpy(cadenacopia,cadena_caracteres);
    for(int i = 0; i < strlen(cadena_caracteres); i++){
        if(cadena_caracteres[i] >= 'a' && cadena_caracteres[i] <= 'z'){
            cadena_caracteres[i] -= 32;
        }
    }
    Serial.print("Original: ");
    Serial.println(cadenacopia);
    Serial.print(". En mayuscula: ");
    Serial.println(cadena_caracteres);
}
void loop(){
    //solo se ejecuta una vez
}/*/

void problema7()
{
    char cadena[100];
    char cadenacop[100];
    char *p, *q, *k;
    cout << "Ingrese una cadena: ";
    cin >> cadena;
    p = cadena;
    q = cadenacop;
    while(*p){
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';
    for(p = cadena; *p; p++){
        q = p + 1;
        k = p + 1;
        while(*q){
            if(*q != *p){
                *k = *q;
                k++;
            }
            q++;
        }
        *k = '\0';
    }
    cout << "Original: " << cadenacop << endl;
    cout << "Sin repetidos: " << cadena << endl;
}

void problema8()
{
    char cadenacaracteres[100];
    char letras[100];
    char numeros[100];
    int l = 0;
    int n = 0;
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadenacaracteres, 100);
    for(int i = 0; i < strlen(cadenacaracteres); i++){
        if (cadenacaracteres[i] >= '0' && cadenacaracteres[i] <= '9') {
            numeros[n++] = cadenacaracteres[i];
        }else {
            letras[l++] = cadenacaracteres[i];
        }
    }
    letras[l] = '\0';
    numeros[n] = '\0';
    cout << "Original: " << cadenacaracteres << "." << endl;
    cout << "Texto: " << letras << "." << endl;
    cout << "Numero: " << numeros << "." << endl;
}

void problema8puntero()
{
    char *cadenacaracteres = new char[100];
    char *letras = new char[100];
    char *numeros = new char[100];
    int l = 0;
    int n = 0;
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadenacaracteres, 100);
    for(int i = 0; i < strlen(cadenacaracteres); i++){
        if(*(cadenacaracteres + i) >= '0' && *(cadenacaracteres + i) <= '9'){
            *(numeros + n) = *(cadenacaracteres + i);
            n++;
        } else {
            *(letras + l) = *(cadenacaracteres + i);
            l++;
        }
    }
    *(numeros + n) = '\0';
    *(letras + l) = '\0';
    cout << "Original: " << cadenacaracteres << "." << endl;
    cout << "Texto: " << letras << "." << endl;
    cout << "Numero: " << numeros << "." << endl;
    delete[] cadenacaracteres;
    delete[] letras;
    delete[] numeros;
}

void problema9()
{
    int N, suma = 0;
    char caracteresnum[100];
    char original[100];
    char division[100];
    cout << "Ingrese un numero: ";
    cin >> N;
    if(N <= 0){
        cout << "Ingrese un numero valido";
        return;
    }
    cout << "Ingrese una cadena de caracteres: ";
    cin >> caracteresnum;
    strcpy(original, caracteresnum);
    int longitud = strlen(caracteresnum);
    int residuo = longitud % N;
    if(residuo != 0) {
        int ceros = N - residuo;
        for(int i = longitud - 1; i >= 0; i--){
            caracteresnum[i + ceros] = caracteresnum[i];
        }
        for(int i = 0; i < ceros; i++){
            caracteresnum[i] = '0';
        }
        caracteresnum[longitud + ceros] = '\0';
    }
    cout << "Original: " << original << ". " << endl;
    for(int i = 0; i < longitud; i += N){
        for(int k = 0; k < N; k++){
            division[k] = caracteresnum[i + k];
        }
        division[N] = '\0';
        cout << division;
        if (i + N < strlen(caracteresnum)) cout << " + ";
        //cout << endl;
        suma += atoi(division);
    }
    cout << endl;
    cout << "Suma: " << suma << "." << endl;
}

void problema10()
{
    int total=0;
    string romano;
    cout << "Ingrese un numero romano: ";
    cin >> romano;
    for (int i = 0; i < romano.length(); i++) {
        romano[i] = toupper(romano[i]);
    }
    for(int i = 0; i < romano.length(); i++){
        int caracter = 0;
        int caractersiguiente = 0;
        if(romano[i] == 'M'){
            caracter = 1000;
        } else if(romano[i] == 'D'){
            caracter = 500;
        } else if(romano[i] == 'C'){
            caracter = 100;
        } else if(romano[i] == 'L'){
            caracter = 50;
        } else if(romano[i] == 'X'){
            caracter = 10;
        } else if(romano[i] == 'V'){
            caracter = 5;
        } else if(romano[i] == 'I'){
            caracter = 1;
        }
        if(i + 1 < romano.length()){
            if(romano[i + 1] == 'M'){
                caractersiguiente = 1000;
            } else if(romano[i + 1] == 'D'){
                caractersiguiente = 500;
            } else if(romano[i + 1] == 'C'){
                caractersiguiente = 100;
            } else if(romano[i + 1] == 'L'){
                caractersiguiente = 50;
            } else if(romano[i + 1] == 'X'){
                caractersiguiente = 10;
            } else if(romano[i + 1] == 'V'){
                caractersiguiente = 5;
            } else if(romano[i + 1] == 'I'){
                caractersiguiente = 1;
            }
        }
        if(caracter < caractersiguiente){
            total -= caracter;
        } else {
            total += caracter;
        }
    }

    cout << "El numero ingresado fue: "<< romano << endl ;
    cout << "Que corresponde a: " << total << endl;
    //return 0;
}

/*/void setup(){//Problema 10 - Arduino
    Serial.begin(9600);
    while(!Serial);
    String romano;
    int total = 0;
    Serial.println("Ingrese un numero romano: ");
    while(Serial.available() == 0);
    romano = Serial.readString();
    for (int i = 0; i < romano.length(); i++) {
        romano[i] = toupper(romano[i]);
    }
    for(int i = 0; i < romano.length(); i++){
        int caracter = 0;
        int caractersiguiente = 0;
        if(romano[i] == 'M'){
            caracter = 1000;
        }else if(romano[i] == 'D'){
            caracter = 500;
        }else if(romano[i] == 'C'){
            caracter = 100;
        }else if(romano[i] == 'L'){
            caracter = 50;
        }else if(romano[i] == 'X'){
            caracter = 10;
        }else if(romano[i] == 'V'){
            caracter = 5;
        }else if(romano[i] == 'I'){
            caracter = 1;
        }
        if(i + 1 < romano.length()){
            if(romano[i + 1] == 'M'){
                caractersiguiente = 1000;
            }else if(romano[i + 1] == 'D'){
                caractersiguiente = 500;
            }else if(romano[i + 1] == 'C'){
                caractersiguiente = 100;
            }else if(romano[i + 1] == 'L'){
                caractersiguiente = 50;
            }else if(romano[i + 1] == 'X'){
                caractersiguiente = 10;
            }else if(romano[i + 1] == 'V'){
                caractersiguiente = 5;
            }else if(romano[i + 1] == 'I'){
                caractersiguiente = 1;
            }
        }
        if(caracter < caractersiguiente){
            total -= caracter;
        }else {
            total += caracter;
        }
    }
    Serial.print("El numero ingresado fue: ");
    Serial.println(romano);
    Serial.print("Que corresponde a : ");
    Serial.println(total);
}
void loop(){
    //solo se ejecuta una vez
}/*/


void problema11()
{
    char sala[15][20];
    char opcion;
    char fila;
    int asiento;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 20; j++){
            sala[i][j] = '-';

        }
    }
    do {
        cout << "1. Resaervar asiento" << endl;
        cout << "2. Cancelar reserva" << endl;
        cout << "3. Ver salar" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige la opcion que desees: ";
        cin >> opcion;
        switch(opcion){
            case '1':{
                cout << "Ingrese la fila. (Ej. 'A'): ";
                cin >> fila;
                fila = toupper(fila);
                cout << "Ingrese el numero de asiento (de 1 a 20): ";
                cin >> asiento;
                int i = fila - 'A';
                int j = asiento - 1;
                if(i >= 0 && i < 15 && j >= 0 && j < 20){
                    if(sala[i][j] == '-'){
                        sala[i][j] = '+';
                        cout << "Asiento reservado exitosamente.";
                    }else {
                        cout << "Este asiento ya se encuentra reservado";
                    }
                }else{
                    cout << "Asiento no encontrado";
                }
                break;
            }
            case '2':{
                cout << "Ingrese la fila. (Ej. 'A'): ";
                cin >> fila;
                fila = toupper(fila);
                cout << "Ingrese el numero de asiento (de 1 a 20): ";
                cin >> asiento;
                int i = fila - 'A';
                int j = asiento - 1;
                if(i >= 0 && i < 15 && j >= 0 && j < 20){
                    if(sala[i][j] == '+'){
                        sala[i][j] = '-';
                        cout << "Reserva cancelada exitosamente.";
                    }else {
                        cout << "Este asiento se encuentra disponible. NO esta reservado";
                    }
                }else{
                    cout << "Asiento no encontrado";
                }
                break;
            }
            case '3':{
                cout << "\n  ";
                for(int j = 1; j <= 20; j++){
                    if(j < 10) {
                        cout << " " << j << " ";
                    }else {
                        cout << j << " ";
                    }
                }
                cout << endl;
                for(int i = 0; i < 15; i++){
                    cout << char('A' + i) << " ";
                    for(int j = 0; j < 20; j++){
                        cout << " " << sala[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case '4':
                cout << ">>>>Saliendo<<<<" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while(opcion != '4');
}

bool problema12()
{
    int N;
    cout << "Ingrese un numero que defina el tamaño: ";
    cin >> N;
    if(N <= 1){
        cout << "Tamaño de la matriz invalido";
        return false;
    }
    int **matriz = new int*[N];
    for(int i = 0; i < N; i++){
        matriz[i] = new int[N];
    }
    for(int i = 0; i < N; i++){
        cout << "Ingrese el contenido de la fila " << i + 1 << " separada por espacios: ";
        for(int j =0; j < N; j++){
            cin >> matriz[i][j];
            //cout << matriz[i][j];
        }
    }
    cout << endl;
    cout << "Matriz: " << endl;
    for(int i = 0; i < N; i++){
        for(int j =0; j < N; j++){
            cout << "  " << matriz[i][j] << " ";
        }
        cout << endl;
    }
    int suma = 0;
    bool *numerosM = new bool[N * N + 1];
    for(int i = 0; i <= N * N; i++){
        numerosM[i] = false;
    }
    for(int j = 0; j < N; j++){//sumar primera fila
        int num = matriz[0][j];
        suma += num;
        if(num <= 0 || num > N * N || numerosM[num]){
            cout << endl;
            cout << "La matriz ingresada No es un cuuadrado magico" << endl;
            delete[] numerosM;
            for(int i = 0; i < N; i++){
                delete[] matriz[i];
            }
            delete[] matriz;
            return false;
        }
        numerosM[num] = true;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            int num = matriz[i][j];
            if(num <= 0 || num > N * N || numerosM[num]){
                cout << endl;
                cout << "La matriz ingresada No es un cuuadrado magico" << endl;
                delete[] numerosM;
                for(int i = 0; i < N; i++){
                    delete[] matriz[i];
                }
                delete[] matriz;
                return false;
            }
            numerosM[num] = true;
        }
    }
    for(int i = 0; i < N; i++){//filas
        int sumafilas = 0;
        for(int j = 0; j < N; j++){
            sumafilas += matriz[i][j];
        }
        if(sumafilas != suma){
            cout << endl;
            cout << "La matriz ingresada No es un cuuadrado magico" << endl;
            delete[] numerosM;
            for(int i = 0; i < N; i++){
                delete[] matriz[i];
            }
            delete[] matriz;
            return false;
        }
    }
    for(int j = 0; j < N; j++){//columnas
        int sumacolumnas = 0;
        for(int i = 0; i < N; i++){
            sumacolumnas += matriz[i][j];
        }
        if(sumacolumnas != suma){
            cout << endl;
            cout << "La matriz ingresada No es un cuuadrado magico" << endl;
            delete[] numerosM;
            for(int i = 0; i < N; i++){
                delete[] matriz[i];
            }
            delete[] matriz;
            return false;
        }
    }
    int sumadiagonal1 = 0, sumadiagonal2 = 0;//diagonales
    for(int i = 0; i < N; i++){
        sumadiagonal1 += matriz[i][i];
        sumadiagonal2 += matriz[i][N - 1 - i];
    }
    if(sumadiagonal1 != suma || sumadiagonal2 != suma){
        cout << endl;
        cout << "La matriz ingresada No es un cuuadrado magico" << endl;
        for(int i = 0; i < N; i++){
            delete[] matriz[i];
        }
        delete[] matriz;
        return false;
    }
    delete[] numerosM;
    cout << endl;
    cout << "La matriz ingresada es un cuadrado magico" << endl;
    for(int i = 0; i < N; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    return true;
}

const int filas = 6;
const int columnas = 8;
int estrellas(int (*matriz)[columnas]){
    int numeroestrellas = 0;
    float cantidadluz;
    for(int i = 1; i < filas - 1; i++){
        for(int k = 1; k < columnas - 1; k++){
            cantidadluz = ((matriz[i][k] + matriz[i][k - 1] + matriz[i - 1][k] + matriz[i + 1][k]) / 5.0);
            if(cantidadluz > 6){
                numeroestrellas++;
            }
        }
    }
    return numeroestrellas;
}
void problema13(){
    int matriz[filas][columnas] = {
        {0,3,4,0,0,0,6,8},
        {5,13,6,0,0,0,2,3},
        {2,6,2,7,3,0,10,0},
        {0,0,4,15,4,1,6,0},
        {0,0,7,12,6,9,10,4},
        {5,0,6,10,6,4,8,0}
    };
    int numeroestrellas = estrellas(matriz);
    cout << "Numero de estrellas encontradas: " << numeroestrellas << endl;
}

void problema14()
{
    int N = 5;
    int matriz[N][N];
    int rotada90[N][N];
    int rotada180[N][N];
    int rotada270[N][N];
    int valor = 1;
    char opcion;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j] = valor++;
        }
    }
    cout << endl;
    cout << "Matriz original: " << endl;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cout << " " << setw(3) << matriz[i][j] << " ";
        }
        cout << endl;
    }
    do {
        cout << "1. Rotar 90°" << endl;
        cout << "2. Rotar 180°" << endl;
        cout << "3. Rotar 270°" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch(opcion){
            case '1':{
                cout << endl;
                cout << "Matriz rotado 90°: " << endl;
                for(int  i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        rotada90[j][N - 1 - i] = matriz[i][j];
                    }
                }
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        cout << " " << setw(3) << rotada90[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case '2':{
                cout << endl;
                cout << "Matriz rotada 180: " << endl;
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        rotada180[N - 1 - i][N - 1 - j] = matriz[i][j];
                    }
                }
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        cout << " " << setw(3) << rotada180[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case '3':{
                cout << endl;
                cout << "Matriz rotada 270: " << endl;
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        rotada270[N - 1 - j][i] = matriz[i][j];
                    }
                }
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        cout << " " << setw(3) << rotada270[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case '4':
                cout << ">>>>Saliendo<<<<" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }while(opcion != '4');
}

void interseccion(int A[4], int B[4], int C[4]){
    int A_x1 = A[0];
    int A_y1 = A[1];
    int A_x2 = A[0] + A[2];
    int A_y2 = A[1] + A[3];

    int B_x1 = B[0];
    int B_y1 = B[1];
    int B_x2 = B[0] + B[2];
    int B_y2 = B[1] + B[3];

    int C_x1;
    if(A_x1 > B_x1){
        C_x1 = A_x1;
    }else {
        C_x1 = B_x1;
    }

    int C_y1;
    if(A_y1 > B_y1){
        C_y1 = A_y1;
    }else {
        C_y1 = B_y1;
    }

    int C_x2;
    if(A_x2 < B_x2) {
        C_x2 = A_x2;
    }else {
        C_x2 = B_x2;
    }

    int C_y2;
    if(A_y2 < B_y2){
        C_y2 = A_y2;
    }else {
        C_y2 = B_y2;
    }

    if(C_x1 < C_x2 && C_y1 < C_y2) {
        C[0] = C_x1;
        C[1] = C_y1;
        C[2] = C_x2 - C_x1;
        C[3] = C_y2 - C_y1;
    }else {
        C[0] = C[1] = C[2] = C[3] = 0;
    }
}
void problema15()
{
    int A[4] = {0, 0, 8, 4};
    int B[4] = {5, 2, 6, 7};
    int C[4];
    interseccion(A, B, C);
    cout << "Rectangulo interseccion C: " << "{" << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "}" << endl;
}

void problema16()
{
    int N, caminos;
    cout << "Ingrese un numero: ";
    cin >> N;
    int **matriz = new int*[N + 1];
    for(int i = 0; i <= N; i++){
        matriz[i] = new int[N + 1];
        for(int j = 0; j <= N; j++){
            if(i == 0 || j == 0){
                matriz[i][j] = 1;
            } else{
                matriz[i][j] = matriz[i - 1][j] + matriz[i][j - 1];
            }
        }
    }
    caminos = matriz[N][N];
    for(int i = 0; i < N; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    cout << "Para una malla de " << N << "x" << N << " puntos hay " << caminos << " caminos" << endl;
}

void problema17()
{
    int N, sumaT = 0;
    bool encontrado = false;
    cout << "Ingrese un numero: ";
    cin >> N;
    for(int i = 1; i < N; i++){
        int sumaX = 0;
        for(int j = 1; j <= i / 2; j++){
            if(i % j == 0){
                sumaX += j;
            }
        }
        if(sumaX > i && sumaX < N){
            int sumadivisores = 0;
            for(int k = 1; k <= sumaX / 2; k++){
                if(sumaX % k == 0){
                    sumadivisores += k;
                }
            }
            if(sumadivisores == i){
                cout << "Amigables: " << i << " y " << sumaX << endl;
                sumaT += i + sumaX;
                encontrado = true;
            }
        }
    }
    if(encontrado){
        cout << "El resulatado de la suma es: " << sumaT << endl;
    }else {
        cout << "No hay numeros amigables menores a " << N << endl;
    }
}


/*/void setup() {//Problema 17 - Arduino
    Serial.begin(9600);
    while (!Serial);
    int N = 0, sumaT = 0;
    bool encontrado = false;
    Serial.println("Ingrese un numero: ");
    while (Serial.available() == 0);
    N = Serial.parseInt();
    for (int i = 1; i < N; i++) {
        int sumaDdn = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sumaDdn += j;
            }
        }
        if (sumaDdn > i && sumaDdn < N) {
            int sumadivisores = 0;
            for (int k = 1; k <= sumaDdn / 2; k++) {
                if (sumaDdn % k == 0) {
                    sumadivisores += k;
                }
            }
            if (sumadivisores == i) {
                Serial.print("Amigables: ");
                Serial.print(i);
                Serial.print(" y ");
                Serial.println(sumaDdn);
                sumaT += i + sumaDdn;
                encontrado = true;
            }
        }
    }
    if (encontrado) {
        Serial.print("El resultado de la suma es: ");
        Serial.println(sumaT);
    } else {
        Serial.print("No hay numeros amigables menores a ");
        Serial.println(N);
    }
}
void loop() {

}/*/

void problema18()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    int numeros[10] = {0,1,2,3,4,5,6,7,8,9};
    int tamaño = 10;
    char permutacion[11];
    int copiaN = N;
    N--;
    for(int i = 9; i >= 0; i--){
        int factorial = 1;
        for(int j = 2; j <= i; j++){
            factorial *= j;
        }
        int x = N / factorial;
        permutacion[9 - i] = '0' + numeros[x];
        for (int j = x; j < tamaño - 1; j++) {
            numeros[j] = numeros[j + 1];
        }
        tamaño--;
        N = N % factorial;
    }
    permutacion[10] = '\0';
    cout << "La permutacion numero " << copiaN << " es: " << permutacion << endl;
}
