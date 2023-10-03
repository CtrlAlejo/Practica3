#include <fstream>
#include <iostream>
#include <string>
#include "auxiliar.h"
using namespace std;

void crear_archivo(string name){ //Crea un archivo
    ofstream archivo(name);
    archivo.close();
}

void escritura_de_archivo(string name, string info){ //Escribe informacion en un archivo
    fstream file;
    file.open(name,ios::out);
    file << info;
    file.close();
}

int char_a_decimal(char letra){
    int decimal = 0;
    decimal = static_cast<int>(letra);
    return decimal;
}

char* decimal_a_binario_(int decimal){
    char *resultado = new char[8], *resultado_f = new char[8]; int bit, cont = 0, cant;
    while (decimal > 0) {
        bit = decimal % 2;
        resultado[cont++] = bit_a_numero(bit);
        decimal /= 2;
    }
    resultado[cont] = '\0';
    cont = 0;
    cant = cantidad_de_caracteres(resultado);
    while (cont < (8 - cant)){
        resultado_f[cont++] = '0';
    }
    for (int i = cont, j = 0; i <= cant; i++, j++){
        resultado_f[i] = resultado[j];
    }
    resultado_f[++cant] = '\0';
    delete [] resultado;
    return resultado_f;
}

string decimal_a_binario(int decimal) { //Convierte un decimal a su correspondiente en binario con 8 bits
    string resultado; int bit;
    while (decimal > 0) {
        bit = decimal % 2;
        resultado = to_string(bit) + resultado;
        decimal /= 2;
    }
    while (resultado.length() < 8) {
        resultado = '0' + resultado;
    }
    return resultado;
}

string string_a_binario(string cadena){ //Convierte un string a binario
    string binario;
    int decimal;
    for(unsigned long long i = 0; i < cadena.length(); i++){
        decimal = cadena[i];
        binario += decimal_a_binario(decimal);
    }
    return binario;
}

char bit_a_numero(int bit){
    char bits[2] = {'0','1'}, caracter;
    {
        caracter = bits[bit];
    }
    return caracter;
}

int cantidad_de_caracteres(const char *cadena){
    /*
    cadena --> Argumento tipo puntero que contiene la primera cadena
    */
    int cant = 0;
    while (*cadena != '\0'){
        cadena++;
        cant++;
    }
    return cant;
}

string leer_archivo(string nombre){
    ifstream archivo(nombre, ios::binary); string contenido;

    archivo.seekg(0, ios::end);
    streampos tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    contenido.resize(static_cast<size_t>(tamano));
    archivo.read(&contenido[0], tamano);
    archivo.close();
    return contenido;
}
