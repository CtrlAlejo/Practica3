#include <fstream>
#include <string>
#include "auxiliar.h"
using namespace std;

void crear_archivo(string name){ //Crea un archivo
    ofstream archivo(name);
    archivo.close();
}

void write_file(string name, string info){ //Escribe informacion en un archivo
    fstream file;
    file.open(name,ios::out);
    file << info;
    file.close();
}

string read_file(string name){ //Lee un archivo y retorna su informacion en un string
    unsigned long long tam;
    fstream file;
    string data, data2;
    file.open(name,ios::in | ios::ate | ios::binary);

    if(file.is_open()){
        tam = file.tellg();
        file.seekg(tam-1);
        for(unsigned long long i=0;i<tam;i++){
            data.push_back(file.get());
            file.seekg(file.tellg()-2);
        }
    }
    tam -=1;
    for(unsigned long long i = 0; i <= tam; i++){
        data2 += data[tam-i];
    }

    file.close();
    return data2;
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
    if (bit >= 0) {
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
