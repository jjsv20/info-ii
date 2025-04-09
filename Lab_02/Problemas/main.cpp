#include <iostream>
using namespace std;

void problema1();

void problema2();

void problema3();

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
    problema2();
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

void problema3()
{

}
