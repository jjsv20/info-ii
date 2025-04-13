#include <iostream>
using namespace std;
#include <cstring>
#include <iomanip>

void problema1();//

void problema2();//pendiente//

bool problema3();//

void problema4();//

void problema5();//

void problema6();//

void problema7();//

void problema8();//
void problema8puntero();//

void problema9();//pendiente//

void problema10();//

void problema11();//

bool problema12();//

void problema13();//pendiente//

void problema14();//

void problema15();

void problema16();

void problema17();

void problema18();



int main()
{
    problema15();
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

void problema2()
{
    char letras[200];
    for(int i = 0; i < 200; i++){
        letras[i] = 'A' + (i*7+3*i*i) % 26;
    }
    cout << "Arreglo: ";
    for(int i = 0; i < 200; i++){//************PENDIENTE***************
        cout << letras[i];
    }
    cout << endl;
    for(int i = 0; i < 200; i++){
        cout << letras[i] << ": " << i << endl;;
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
                *k++;
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

/*/void problema9()
{
    int N, suma=0;
    char caracteresnum[100];
    char separacion[100];
    cout << "Ingrese un numero: ";
    cin >> N;
    if(N <= 0){
        cout << "Ingrese un numero valido";
    }
    cout << "Ingrese una cadena de caracteres: ";
    cin >> caracteresnum;
    if(strlen(caracteresnum) % N == 0){
        for(int i = 0; i < strlen(caracteresnum); i += N){
            for(int j = 0; j < N; j++){
                separacion[j] = caracteresnum[i + j];
            }
            separacion[N] = '\0';
        }


    }else{
        int ceros = N - (strlen(caracteresnum) % N);
        for(int j - ceros - 1; j >= 0; i--){
            caracteresnum[i + ceros] = caracteresnum[i];
        }
        for(int i = 0; i < ceros; i++){
            caracteresnum[i] = '0';
        }
    }
}/*/

void problema10()
{
    int total=0;
    string romano;
    cout << "Ingrese un numero romano: ";
    cin >> romano;
    for(int i = 0; i < romano.length(); i++){
        int caracter = 0;
        int caractersiguiente = 0;
        if(romano[i] == 'M'){
            romano[i] += 32;
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
                romano[i] += 32;
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
        return 1;
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
            return 0;
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
                return 0;
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
            return 0;
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
            return 0;
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
        return 0;
    }
    delete[] numerosM;
    cout << endl;
    cout << "La matriz ingresada es un cuadrado magico" << endl;
    for(int i = 0; i < N; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}

void problema13()
{
    //pendiente
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

void problema15()
{

}
