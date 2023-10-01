#include <fstream>
#include <string>
using namespace std;

void create_file(string name){ //Crea un archivo
    fstream file;
    file.open(name,ios::out);
    file.close();
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
    string resultado;
    while (decimal > 0) {
        int bit = decimal % 2;
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





















