#include "auxiliar.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void cadena_a_binario(){
    char caracter, letra = '\0', *resultado; int decimal, cont = 0, cont2 = 0;
    char *binario = new char[10];
    ifstream archivo("prueba.txt");
    while (archivo >> caracter){
        decimal = char_a_decimal(caracter);
        resultado = decimal_a_binario_(decimal);
        do{
            letra = resultado[cont++];
            binario[cont2++] = letra;
        } while (cont < 8);
        cont = 0;
    }
    binario[cont2] = '\0';
    cout << resultado;
    delete[] resultado;
    delete[] binario;
}

void metodo_codificacion_1 (){

}
