#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <fstream>
#include <string>
using namespace std;

void crear_archivo(string name);
void escritura_de_archivo(string name, string info);
string read_file(string name);
string string_a_binario(string name);
string decimal_a_binario(int decimal);
int char_a_decimal(char letra);
char bit_a_numero(int bit);
void cadena_a_binario();
int cantidad_de_caracteres(const char *cadena);
char* decimal_a_binario_(int decimal);
string leer_archivo(string nombre);

#endif // AUXILIAR_H
