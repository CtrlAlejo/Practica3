#include <iostream>
#include <fstream>
#include <string>
#include "auxiliar.h"
using namespace std;

int main()
{
    string cadena;
    cadena = leer_archivo("prueba.txt");
    cout << cadena;
    return 0;
}
