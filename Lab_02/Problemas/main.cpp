#include <iostream>
using namespace std;
#include <cstring>

void problema1();

void problema2();

bool problema3();

void problema4();

void problema5();

void problema6();

void problema7();

void problema8();

void problema9();

void problema10();

void problema11();

void problema12();

void problema13();

void problema14();

void problema15();

void problema16();

void problema17();

void problema18();



int main()
{
    problema8();
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

}
