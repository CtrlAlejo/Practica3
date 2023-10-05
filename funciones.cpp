#include "auxiliar.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

char* cadena_a_binario(string file){
    char caracter, letra = '\0', *resultado; int decimal, cont = 0, cont2 = 0;
    char *binario = new char[10]; char* binario2 = new char[10];
    ifstream archivo(file);
    while (archivo >> caracter){
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

char* metodo_codificacion_1 (char *sin_codificar, int semilla){
    char *bloque = new char[semilla]; char *codificado = new char[semilla]; int cont = 0, cont2 = 0, unos = 0, ceros = 0, cad_1 = 0, cont3 = 1;
    float tope;
    cad_1 = cantidad_de_caracteres(sin_codificar);
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
        cont3++;
        tope = redondeo(cad_1, semilla);
    } while (cont3 != tope);
    delete[] bloque;
    return codificado;
}

void binario_a_cadena (char *codificado){
    int cont = 0;char bloque[9]; unsigned long binario; char letra; string caracter;
    while (codificado[cont] != '\0'){
        for (int i = cont, j = 0; j < 8; i++, j++){
            bloque[j] = codificado[i];
            cont = i;
        }
        bloque[++cont] = '\0';
        binario = conversion_de_char_a_int(bloque);
        binario = binarioADecimal(binario);
        letra = decimal_a_char(binario);
        caracter = letra;
        escritura_de_archivo("prueba2.dat", caracter);
    }
}
