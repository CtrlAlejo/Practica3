#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
using namespace std;

char* cadena_a_binario();
char* metodo_codificacion_1 (char *sin_codificar, int semilla);
char* cadena_a_binario(string file, size_t tamaño);
void binario_a_cadena (char *bits, string file);
void decodificacion_1(string file1, string file2, size_t tamaño);
char* metodo_codificacion_1 (char *sin_codificar, int semilla, size_t tamaño);


#endif // FUNCIONES_H
