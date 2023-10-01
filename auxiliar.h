#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <fstream>
#include <string>
using namespace std;

void create_file(string name);
void write_file(string name, string info);
string read_file(string name);

string string_a_binario(string name);
string decimal_a_binario(int decimal);

#endif // AUXILIAR_H
