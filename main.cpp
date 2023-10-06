#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "funciones.h"
using namespace std;

int main()
{
    char *binario = nullptr, *codificado = nullptr; size_t tamano; int semilla;
    string archivo_entrada_n, archivo_salida_n;
    int seleccion = 0;
    cout << "Ingrese 1 para codificacion y 2 para decodificacion: ";
    cin >> seleccion;
    if (seleccion == 1){
        ifstream archivo_entrada;
        cout << "Ingrese la semilla: ";
        cin >> semilla;
        cout << "Ingrese el nombre del archivo de entrada: ";
        getline(cin, archivo_entrada_n);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Ingrese el nombre del archivo de salida: ";
        getline(cin, archivo_salida_n);
        archivo_entrada.seekg(0, ios::end);
        tamano = archivo_entrada.tellg();
        archivo_entrada.seekg(0, ios::beg);
        binario = cadena_a_binario(archivo_entrada_n, tamano);
        codificado = metodo_codificacion_1(binario, semilla, tamano);
        binario_a_cadena(codificado, archivo_salida_n);
    } else if (seleccion == 2){
        ifstream archivo_entrada;
        cout << "Ingrese el nombre del archivo de entrada: ";
        getline(cin, archivo_entrada_n);
        cout << "Ingrese el nombre del archivo de salida: ";
        getline(cin, archivo_salida_n);
        cout << "Ingrese la semilla: ";
        cin >> semilla;
        archivo_entrada.seekg(0, ios::end);
        tamano = archivo_entrada.tellg();
        archivo_entrada.seekg(0, ios::beg);
        decodificacion_1(archivo_entrada_n, archivo_salida_n, tamano);
    }
    delete[] binario;
    delete[] codificado;
    return 0;
}
