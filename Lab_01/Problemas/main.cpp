#include <iostream>

using namespace std;

void problema1();

int problema3();

int problema5();

int problema7();

int problema9();

int problema11();

int problema13();

int problema15();

int problema17();


int main()
{
    problema13();
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
    int N, espacios, asteriscos;
    cout << "Ingrese un numero: ";
    cin >> N;
    if (N % 2 == 0){
        cout << N << " es un numero par";
    }
    else {
        asteriscos = 1;
        espacios = (N- 1)/2;
        for (int i = 1; i <= N; i+=2){
            for (int j = 1; j <= espacios; j++){
                if(asteriscos != N){
                    cout << " ";
                }
            }
            for (int j = 1; j <= asteriscos; j++){
                cout << "*";
            }
            for (int j = 1; j <= espacios; j++){
                if(asteriscos != N){
                    cout << " ";
                }
            }
            cout << endl;
            asteriscos += 2;
            espacios --;
        }
        asteriscos = N - 2;
        espacios = 1;
        for (int i = 1; i <= N/2; i++){
            for (int j = 1; j <= espacios; j++){
                if(asteriscos != N){
                    cout << " ";
                }
            }
            for (int j = 1; j <= asteriscos; j++){
                cout << "*";
            }
            for (int j = 1; j <= espacios; j++){
                if(asteriscos != N){
                    cout << " ";
                }
            }
            cout << endl;
            asteriscos -= 2;
            espacios ++;
        }
    }
}

int problema7()
{
    int N, a=0, b=1, c=0, suma = 0;
    cout << "Ingrese un numero: ";
    cin >> N;

    while (c < N){
        if (c % 2 == 0){
            suma += c;
        }

        //cout << "La serie de Fibonacci hasta " << N << " es: ";
        cout << c << ", ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << "El resultado de la suma es; " << suma << endl;
    return 0;
}

int problema9()
{
    int N, suma=0, P, digito;
    cout << "Ingrese un numeo: ";
    cin >> N;
    while (N>0) {
        digito = N%10;
        N /= 10;
        P = 1;
        for (int i = 0; i < digito; i++) {
            P *= digito;
        }
        suma += P;
    }
    cout << "Suma digitos: " << suma << endl;
    return 0;
}

int problema11()
{
    int N, a, b, c, mcm = 1, x;
    cout << "Ingrese un numero: ";
    cin >> N;
    for(int i = 2; i <= N; i++){
        a = mcm;
        b=i;
        while (b>0){
            x = b;
            b = a % b;
            a = x;
        }
        mcm = (mcm/a)*i;
    }
    cout << "El minimo comun multiplo es: " << mcm <<endl;
}

int problema13()
{
    int N, Primo;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 2; i <= N; i++){
        Primo = 1;
        for(int j=2; j<=i/2; j++) {
            if(i % j == 0) {
                Primo = 0;
            }
        }

        if(Primo == 1) {
            cout << i << " es un número primo." << endl;
        } else {
            cout << i << " no es un número primo." << endl;
        }

        return 0;
    }
}






