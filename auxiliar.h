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
char decimal_a_char(int decimal);
char bit_a_numero(int bit);
int cantidad_de_caracteres(const char *cadena);
char* decimal_a_binario_(int decimal);
string leer_archivo(string nombre);
int unos_y_ceros(char* bloque, int semilla, int &ceros);
void generacion_de_bloque(char* bloque, int semilla, char* cadena, int &cont);
void codificacion1_1(char* cadena, char* bloque, int semilla, int &guia);
void codificacion1_2(char* cadena, char* bloque, int semilla, int &guia);
void codificacion1_3(char* cadena, char* bloque, int semilla, int &guia);
unsigned long conversion_de_char_a_int(const char *cadena);
unsigned long binarioADecimal(long binario);
string codificar_bloque(const string& bloque);
string codificar_archivo(const string& entrada, int n);
char binario_a_char(const string& bloque);
string binario_a_caracteres(const string& entrada);

void segundo_metodo_codificacion();

string decodificar_bloque(const string& bloque);
string decodificar_archivo(const string& entrada, int n);

void decodificar_segundo_metodo();
string codificar_archivo(const string &binario, int n);
string codificar_bloque(const string &bloque);
char binario_a_char(const string& bloque);
string binario_a_caracteres(const string& entrada);
string decodificar_bloque(const string &bloque);
string decodificar_archivo(const string &binario_codificado, int n);
void decodificar_segundo_metodo();

#endif // AUXILIAR_H
