#include <iostream>
#include <fstream>
#include <string>
#include "funciones.h"
using namespace std;

int main()
{
    char* binario;
    binario = cadena_a_binario();
    metodo_codificacion_1(binario, 4);
    delete[] binario;
    return 0;
}
