#include <iostream>
#include <fstream>
#include <string>
#include "funciones.h"
using namespace std;

int main()
{
    char *binario, *codificado;
    binario = cadena_a_binario("prueba.txt");
    codificado = metodo_codificacion_1(binario, 4);
    binario_a_cadena(codificado);
    delete[] binario;
    return 0;
}
