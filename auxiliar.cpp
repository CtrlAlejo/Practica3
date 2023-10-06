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
    ofstream file(name, ios_base::app);
    file << info;
    file.close();
}

int char_a_decimal(char letra){
    int decimal = 0;
    decimal = static_cast<int>(static_cast<unsigned char>(letra));
    return decimal;
}

char decimal_a_char(int decimal){
    char caracter;
    caracter = static_cast<char>(decimal);
    return caracter;
}

char* decimal_a_binario_(int decimal){ //Convierte un decimal a binario
    char *resultado = new char[9], *resultado_f = new char[9]; int bit, cont = 0, cont2 = 0, cant;
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
    for (int n = cont, m = 0; n < 8; n++, m++){ //Se voltea el arreglo de caracteres
        resultado_f[n] = resultado[(cont2 - 1) - m];
        cont = n;
    }
    resultado_f[++cont] = '\0';
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

char bit_a_numero(int bit){ //Selecciona los bits entre 0 y 1
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

int unos_y_ceros(char* bloque, int semilla, int &ceros){ //Cuenta los unos y ceros del bloque
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

void generacion_de_bloque(char* bloque, int semilla, char* cadena, int &cont){//Genera el bloque para codificar
    for (int i = 0; i < semilla; i++){
        if (cadena[cont] != '\0'){
            bloque[i] = cadena[cont++];
        } else {
            break;
        }
    }
    bloque[cont] = '\0';
}

void codificacion1_1(char* cadena, char* bloque, int semilla, int &guia){
    for (int j = 0; j < semilla; j++){
        if (cadena[guia] != '\0'){
            if (bloque[j] == '0'){
                cadena[++guia] = '1';
            } else if (bloque[j] == '1') {
                cadena[++guia] = '0';
            }
        } else {
            break;
        }
    }
}

void codificacion1_2(char* cadena, char* bloque, int semilla, int &guia){
    for (int i = 0, j = 1; i < semilla; i++, j++){
        if (cadena[guia] != '\0'){
            if (j % 3 == 0){
                if (bloque[i] == '1'){
                    cadena[++guia] = '0';
                } else if (bloque[i] == '0') {
                    cadena[++guia] = '1';
                }
            } else {
                cadena[++guia] = bloque[i];
            }
        } else {
            break;
        }
    }
}

void codificacion1_3(char* cadena, char* bloque, int semilla, int &guia){
    for (int i = 0, j = 1; i < semilla; i++, j++){
        if (bloque[i] != '\0'){
            if (j % 2 == 0){
                if (bloque[i] == '1'){
                    cadena[++guia] = '0';
                } else if (bloque[i] == '0') {
                    cadena[++guia] = '1';
                }
            } else {
                cadena[++guia] = bloque[i];
            }
        } else {
            break;
        }
    }
}

unsigned long conversion_de_char_a_int(const char *cadena){
    //Recibe una cadena de caracteres numericos y la convierte a enteros
    unsigned long numero = 0, i = 0;
    if (cadena[0] == '-') {
        i = 1;
    }
    while(cadena[i] != '\0'){
        if(cadena[i] >= '0' && cadena[i] <= '9'){
            numero = numero * 10 + (cadena[i] - '0');
        }
        else{
            break;
        }
        i++;
    }
    return numero;
}

unsigned long binarioADecimal(long binario){
    //Convierte un numero binario a decimal
    //Argumentos --> binario: Es el numero binario que sera convertido a decimal
    unsigned long decimal = 0;
    int base = 1;  // Inicializar la base en 2^0 (1)

    while (binario > 0) {
        int digito = binario % 10;   // Obten el último dígito del número binario
        decimal = decimal + digito * base;
        binario = binario / 10;       // Elimina el último dígito del número binario
        base = base * 2;             // Incrementa la base a la siguiente potencia de 2
    }
    return decimal;
}

string codificar_bloque(const string &bloque) { // Aplicar la codificación dentro del bloque
    string bloque_codificado = bloque;
    int longitud = bloque.length();
    char bit; int indice_destino;


    for (int i = 0; i < longitud; i++) {
        bit = bloque[i];
        indice_destino = (i + 1) % longitud; // Calcular la posición de destino
        bloque_codificado[indice_destino] = bit;
    }

    return bloque_codificado;
}

// Función para dividir un archivo binario en bloques de n bits y aplicar la codificación
string codificar_archivo(const string &binario, int n) {
    string binario_codificado = ""; string bloqueCodificado; string bloque;
    int longitud = binario.length();

    for (int i = 0; i < longitud; i += n) {
        bloque = "";
        for (int j = i; j < i + n; j++) {
            if (j < longitud) {
                bloque += binario[j];
            }
        }
        bloqueCodificado = codificar_bloque(bloque);
        binario_codificado += bloqueCodificado;
    }

    return binario_codificado;
}

// Función para convertir un bloque de 8 bits en un carácter ASCII
char binario_a_char(const string& bloque) {
    int valor = 0; char caracter;
    for (int i = 0; i < 8; i++) {
        valor = (valor << 1) | (bloque[i] - '0'); // Convierte bits a valor entero
    }
    caracter = valor;
    return caracter; // Convierte el valor a un carácter
}

// Función para dividir una cadena binaria codificada en bloques de 8 bits y convertirla en caracteres ASCII
string binario_a_caracteres(const string& entrada) {
    string caracteres = ""; string bloque;
    int longitud = entrada.length();
    char caracter;

    // Dividir la cadena en bloques de 8 bits y convertirlos en caracteres
    for (int i = 0; i < longitud; i += 8) {
        bloque = "";
        for (int j = i; j < i + 8; j++) {
            if (j < longitud) {
                bloque += entrada[j];
            }
        }
        caracter = binario_a_char(bloque);
        caracteres += caracter;
    }

    return caracteres;
}

void segundo_metodo_codificacion(){
    string archivo_fuente; string archivo_salida; int n;
    cout << "Ingrese el nombre del archivo fuente: ";
    cin >> archivo_fuente;
    cout << "Ingrese el nombre del archivo de salida: ";
    cin >> archivo_salida;
    cout << "Ingrese la semilla de codificacion: ";
    cin >> n;
    string file = leer_archivo(archivo_fuente);
    string binario = string_a_binario(file);
    string codificado = codificar_archivo(binario, n);
    string caracteres = binario_a_caracteres(codificado);
    escritura_de_archivo(archivo_salida, caracteres);
}

string decodificar_bloque(const string &bloque) {
    string bloque_decodificado = bloque;
    int longitud = bloque.length();
    char bit;
    int indice_destino;

    for (int i = 0; i < longitud; i++) {
        bit = bloque[i];
        indice_destino = (i - 1 + longitud) % longitud; // Calcular la posición de destino
        bloque_decodificado[indice_destino] = bit;
    }

    return bloque_decodificado;
}
// Función para dividir un archivo binario codificado en bloques de n bits y aplicar la decodificación
string decodificar_archivo(const string &binario_codificado, int n) {
    string binario_decodificado = "";
    string bloque_decodificado;
    string bloque;
    int longitud = binario_codificado.length();

    for (int i = 0; i < longitud; i += n) {
        bloque = "";
        for (int j = i; j < i + n && j < longitud; j++) {
            bloque += binario_codificado[j];
        }
        bloque_decodificado = decodificar_bloque(bloque);
        binario_decodificado += bloque_decodificado;
    }

    return binario_decodificado;
}

void decodificar_segundo_metodo(){
    string archivo_fuente; string archivo_salida; int n;
    cout << "Ingrese el nombre del archivo fuente: ";
    cin >> archivo_fuente;
    cout << "Ingrese el nombre del archivo de salida: ";
    cin >> archivo_salida;
    cout << "Ingrese la semilla de decodificacion: ";
    cin >> n;
    string file = leer_archivo(archivo_fuente);
    string binario = string_a_binario(file);
    string decodificado = decodificar_archivo(binario, n);
    string caracteres = binario_a_caracteres(decodificado);
    escritura_de_archivo(archivo_salida, caracteres);

}
