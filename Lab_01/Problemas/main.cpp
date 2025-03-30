#include <iostream>

using namespace std;

void problema1();

int problema3();

int problema5();

void problema7();

void problema9();

void problema11();

void problema13();

void problema15();

void problema17();


int main()
{
    problema3();
    return 0;
}


void problema1()
{
    char caracter;
    cout << "Ingrese un caracter cualquiera: ";
    cin >> caracter;
    if ((caracter >='a' && caracter <='z') || (caracter >='A' && caracter <='Z')){
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u' ||
            caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U') {
            cout << caracter << " es una vocal" << endl;
        } else {
            cout << caracter << " es una consonante" << endl;
        }
    }
    else {
        cout << caracter << " no es una letra" << endl;
    }
}

int problema3()
{
    int mes, dia;
    cout << "Ingrese un mes del año (01 ó 1): ";
    cin >> mes;
    if (mes < 1 || mes > 12) {
        cout << mes << " es un mes inválido" << endl;
        return 0;
    }
    cout << "Ingrese und dia del mes: ";
    cin >> dia;
    if (mes == 2){
        if (dia == 28){
            cout << dia << "/" << mes << " es valida en bisiesto" << endl;
        } else if (dia >= 1 && dia <= 28) {
            cout << dia << "/" << mes << " es una fecha válida" << endl;
        } else {
            cout << dia << "/" << mes << " es una fecha inválida" << endl;
        }
    }
    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if (dia >= 1 && dia <= 31){
            cout << dia << "/" << mes << " es una fecha valida" << endl;
        } else {
            cout << dia << "/" << mes << " es una fecha inválida" << endl;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia >= 1 && dia <= 30){
            cout << dia << "/" << mes << " es una fecha valida" << endl;
        } else {
            cout << dia << "/" << mes << " es una fecha inválida" << endl;
        }
    }
    return 0;
}

int problema5()
{

}
