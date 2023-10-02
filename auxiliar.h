#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <fstream>
#include <string>
using namespace std;

void crear_archivo(string name);
void write_file(string name, string info);
string read_file(string name);
string string_a_binario(string name);
string decimal_a_binario(int decimal);
char bit_a_numero(int bit);
int cantidad_de_caracteres(const char *cadena);
char* decimal_a_binario_2(int decimal);
string leer_archivo(string nombre);

#endif // AUXILIAR_H
