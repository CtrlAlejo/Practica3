#include "auxiliar.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

char* cadena_a_binario(string file, size_t tamaño){
    char caracter, letra = '\0', *resultado = nullptr; int decimal, cont = 0, cont2 = 0;
    char *binario = new char[1000];
    ifstream archivo(file, ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }
    while (archivo.read(&caracter, sizeof (caracter))){
        decimal = char_a_decimal(caracter);
        resultado = decimal_a_binario_(decimal);
        do{
            letra = resultado[cont++];
            binario[cont2++] = letra;
        } while (cont < 8);
        cont = 0;
    }
    binario[cont2] = '\0';
    archivo.close();
    delete[] resultado;
    return binario;
}

char* metodo_codificacion_1 (char *sin_codificar, int semilla, size_t tamaño){
    char *bloque = new char[tamaño]; char *codificado = new char[tamaño]; int cont = 0, cont2 = 0, unos = 0, ceros = 0;
    generacion_de_bloque(bloque, semilla, sin_codificar, cont);
    for (int j = 0; j < semilla; j++){
        if (bloque[j] == '0'){
            codificado[j] = '1';
        } else if (bloque[j] == '1') {
            codificado[j] = '0';
        }
        cont2 = j;
    }
    do{
        unos = unos_y_ceros(bloque, semilla, ceros);
        generacion_de_bloque(bloque, semilla, sin_codificar, cont);
        if (ceros == unos){
            codificacion1_1(codificado, bloque, semilla, cont2);
            ceros = 0;
        } else if (ceros < unos) {
            codificacion1_2(codificado, bloque, semilla, cont2);
            ceros = 0;
        } else if (ceros > unos) {
            codificacion1_3(codificado, bloque, semilla, cont2);
            ceros = 0;
        }
    } while (sin_codificar[cont] != '\0');
    codificado[cont] = '\0';
    delete[] bloque;
    return codificado;
}

char* metodo_decodificacion_1 (char *sin_codificar, int semilla){
    char *bloque = new char[1000]; char *codificado = new char[1000]; int cont = 0, cont2 = 0, unos = 0, ceros = 0;
    generacion_de_bloque(bloque, semilla, sin_codificar, cont);
    for (int j = 0; j < semilla; j++){
        if (bloque[j] == '0'){
            codificado[j] = '1';
        } else if (bloque[j] == '1') {
            codificado[j] = '0';
        }
        cont2 = j;
    }
    do{
        unos = unos_y_ceros(bloque, semilla, ceros);
        generacion_de_bloque(bloque, semilla, sin_codificar, cont);
        if (ceros == unos){
            codificacion1_1(codificado, bloque, semilla, cont2);
            ceros = 0;
        } else if (ceros > unos || ceros < unos) {
            codificacion1_3(codificado, bloque, semilla, cont2);
            ceros = 0;
        }
    } while (sin_codificar[cont] != '\0');
    delete[] bloque;
    return codificado;
}

void binario_a_cadena (char *bits, string file){
    int cont = 0;char bloque[9]; unsigned long binario; char letra; string caracter;
    while (bits[cont] != '\0'){
        for (int i = cont, j = 0; j < 8; i++, j++){
            bloque[j] = bits[i];
            cont = i;
        }
        bloque[++cont] = '\0';
        binario = conversion_de_char_a_int(bloque);
        binario = binarioADecimal(binario);
        letra = decimal_a_char(binario);
        caracter = letra;
        escritura_de_archivo(file, caracter);
    }
}

void decodificacion_1(string file1, string file2, size_t tamaño){
    char *decodificado, *codificado;
    codificado = cadena_a_binario(file1, tamaño);
    decodificado = metodo_decodificacion_1 (codificado, 4);
    binario_a_cadena(decodificado, file2);
    delete[] decodificado;
    delete[] codificado;
}
