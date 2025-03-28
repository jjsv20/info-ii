#include <iostream> //entrada y salida

using namespace std; // Espacio

/*
Ejercicio 1. Escriba un programa que pida dos números A y B e imprima en pantalla el residuo
de la división A/B.
*/
void ejercicio1();

int ejercicio3();

int ejercicio5();

int ejercicio7();

int ejercicio9();

int ejercicio11();

void ejercicio13();

void ejercicio15();

void ejercicio17();

void ejercicio19();

void ejercicio21();

void ejercicio23();

void ejercicio25();

void ejercicio27();

void ejercicio29();


int main()
{
    ejercicio23();
    return 0;
}

void ejercicio1()
{
    int a, b;
    cout << "Ingrese dos numeros: ";
    cin >> a >> b;
    cout << "El residuo de la division " << a << "/" << b << " es: " << a % b << endl;
}

int ejercicio3()
{
    int a, b;
    cout << "Ingrese dos numero: ";
    cin >> a >> b;
    if (a > b)
        cout << "El numero mayor es " << a << endl;
    else
        cout << "El numero menor es " << b << endl;
    return 0;
}

int ejercicio5()
{
    int a, b;
    cout << "Ingrese dos numeros: ";
    cin >> a >> b;
    cout << "La division " << a << "/" << b << " es: " << a / b << endl;
    return 0;
}

int ejercicio7()
{
    int N, suma = 0;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 0; i <= N; i++){
        suma += i;
    }
    cout << "La sumatoria desde 0 hasta " << N << " es " << suma << endl;
    return 0;
}

int ejercicio9()
{
    int N;
    float area, perimetro;
    cout << "Ingrese un numero: ";
    cin >> N;
    perimetro = 2 * 3.1416 * N;
    area = 3.1416 * (N*N);
    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;
    return 0;
}


int ejercicio11()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 1; i <= 10; i++){
        cout << i << " x " << (N) << " = " << i * N << endl;
    }
    return 0;
}

void ejercicio13()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 1; i <= N; i++){
        if (N % i == 0){
            cout << i << endl;
        }
    }
}

void ejercicio15()
{
    int N, sumatoria;
    cout << "Ingrese un numero: ";
    cin >> N;
    sumatoria = 0;
    while(N != 0 ){
        sumatoria += N;
        cout << "Ingrese un numero: ";
        cin >> N;
    }
    cout << sumatoria << endl;
}


void ejercicio17()
{
    int N, num_mayor;
    cout << "Ingrese un numero: ";
    cin >> N;
    num_mayor = N;
    while (N != 0){
        cout << "Ingrese un numero: ";
        cin >> N;
        if (N > num_mayor)
            num_mayor = N;
    }
    cout << "El numero mayor fue: " << num_mayor << endl;
}

void ejercicio19()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    if (N % 2 == 0)
        cout << N << " NO es un numero primo" << endl;
    else
        cout << N << " es un numero primo" << endl;
}

void ejercicio21()
{
    char C;
    cout << "Ingrese un caracter: ";
    cin >> C;

    if (C >= 'a' && C <= 'z'){
        C = C - 32;
    }
    cout << "Letra convertida: " << C << endl;
}

void ejercicio23()
{
    int A, B, x, mcd, mcm;
    cout << "Ingrese dos nuemros: ";
    cin >> A >> B;
    int a_c = A;
    int b_c = B;
    while (B != 0) {
        x = B;
        B = A % B;
        A = x;
    }
    mcd = A;
    mcm = (a_c * b_c)/mcd;
    cout << "El MCM de " << a_c << " y " << b_c << " es: " << mcm << endl;
}

void ejercicio25()
{
    int N, longitud;
    cout << "Ingrese un numero: ";
    cin >> N;
    int N_c = N;
    for (N = N; N > 0; N /= 10){
        longitud++;
    }
    cout << N_c << " tiene " << longitud << " digitos" << endl;
}

void ejercicio27()
{
    int a, b, suma, resta, multiplicacion, division;
    char signo;
    cout << "Ingrese el operando de la operacion que desea realiza: ";
    cin >> signo;
    if (signo == '+'){
        cout << "Ingrese el primero numero: ";
        cin >> a;
        cout << "Ingrese el segundo numero: ";
        cin >> b;
        suma = a + b;
        cout << a << signo << b << "=" << suma << endl;
    } else if (signo == '-'){
        cout << "Ingrese el primero numero: ";
        cin >> a;
        cout << "Ingrese el segundo numero: ";
        cin >> b;
        resta = a - b;
        cout << a << signo << b << "=" << resta << endl;
    } else if (signo == 'x' || 'X'){
        cout << "Ingrese el primero numero: ";
        cin >> a;
        cout << "Ingrese el segundo numero: ";
        cin >> b;
        multiplicacion = a * b;
        cout << a << signo << b << "=" << multiplicacion << endl;
    } else if (signo == '/'){
        cout << "Ingrese el primero numero: ";
        cin >> a;
        cout << "Ingrese el segundo numero: ";
        cin >> b;
        division = a / b;
        cout << a << signo << b << "=" << division << endl;
    }
}

void ejercicio29()
{
    int x=0, y=100, B=0;
    char respuesta;
    cout << "Piensa un numero del uno al 100, voy a adivinarlo: ";

    while (true){
        B = (x+y)/2;
        cout << "El numero es: " << B << " ?" << endl;
        cout << "Utilice '<' si el numero es mayor, '>' si es menor o '=' si es igual: ";
        cin >> respuesta;
        if (respuesta == '<'){
            x = B + 1;
            cout << B << endl;
        } else if (respuesta == '>') {
            y = B - 1;
            cout << B << endl;
        } else if (respuesta == '='){
            cout << "Numero adivinado: " << B << endl;
            break;
        }
    }
}
