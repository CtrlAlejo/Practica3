#include "auxiliar.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void cadena_a_binario(){
    char caracter, *resultado; int decimal;
    ifstream archivo("prueba.txt");
    while (archivo >> caracter){
        decimal = char_a_decimal(caracter);
        resultado = decimal_a_binario_(decimal);
        escritura_de_archivo("prueba2.txt", resultado);
    }
    cout << resultado;
    delete[] resultado;
}
