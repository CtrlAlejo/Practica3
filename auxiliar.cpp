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
    char *resultado = new char[8], *resultado_f = new char[8]; int bit, cont = 0, cont2 = 0, cant;
    while (decimal > 0) {
        bit = decimal % 2;
        resultado[cont++] = bit_a_numero(bit);
        decimal /= 2;
    }
    resultado[cont] = '\0';
    cont2 = cont;
    cont = 0;
    cant = cantidad_de_caracteres(resultado);
    while (cont < (8 - cant)){
        resultado_f[cont++] = '0';
    }
    for (int n = cont, m = 0; n <= cont2; n++, m++){ //Se voltea el arreglo de caracteres
        resultado_f[n] = resultado[(cont2 - 1) - m];
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

int unos_y_ceros(char* bloque, int semilla, int &ceros){
    int unos = 0;
    for (int i = 0; i < semilla; i++){
        if (bloque[i] == '1'){
            unos++;
        } else if (bloque[i] == '0'){
            ceros++;
        }
    }
    return unos;
}

void generacion_de_bloque(char* bloque, int semilla, char* cadena, int &cont){
    for (int i = 0; i < semilla; i++){
        bloque[i] = cadena[cont++];
    }
    bloque[cont] = '\0';
}

void codificacion1_1(char* cadena, char* bloque, int semilla, int &guia){
    for (int j = 0; j < semilla; j++){
        if (bloque[j] == '0'){
            cadena[++guia] = '1';
        } else if (bloque[j] == '1') {
            cadena[++guia] = '0';
        }
    }
}

void codificacion1_2(char* cadena, char* bloque, int semilla, int &guia){
    for (int i = 0, j = 1; i < semilla; i++, j++){
        if (j % 3 == 0){
            if (bloque[i] == '1'){
                cadena[++guia] = '0';
            } else if (bloque[i] == '0') {
                cadena[++guia] = '1';
            }
        } else {
            cadena[++guia] = bloque[i];
        }
    }
}

void codificacion1_3(char* cadena, char* bloque, int semilla, int &guia){
    for (int i = 0, j = 1; i < semilla; i++, j++){
        if (j % 2 == 0){
            if (bloque[i] == '1'){
                cadena[++guia] = '0';
            } else if (bloque[i] == '0') {
                cadena[++guia] = '1';
            }
        } else {
            cadena[++guia] = bloque[i];
        }
    }
}

int redondeo(int num1, int num2){
    float resultado_dec, resultado, dec;
    dec = 0.1;
    resultado = num1/num2;
    resultado_dec = resultado - int(resultado);
    if (resultado_dec >= dec){
        resultado = resultado+1;
        resultado = int(resultado);
    }
    else{
        resultado = int(resultado);
    }
    return resultado;
}
