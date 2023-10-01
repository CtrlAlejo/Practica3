#include <iostream>
#include <fstream>
#include <string>
#include "auxiliar.h"
using namespace std;

int main()
{
    //create_file("prueba.txt");
    //string info = "AbCd";
    //write_file("prueba.txt", info);

    string file = read_file("prueba.txt");
    cout << file << endl;

    cout <<endl << string_a_binario(file) <<endl;
    return 0;
}
