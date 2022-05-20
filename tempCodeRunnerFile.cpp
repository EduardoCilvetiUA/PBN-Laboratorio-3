#include <iostream>
#include <sstream>
#include <fstream>
#include "peleador.h"

using namespace std;

int main(){
    ifstream entrada("data tarea 3.csv");

    string linea;
    char delimitador = ';';

    while(getline(entrada, linea))
    {
        string titulo, nombre, leyenda, tipo;
        string salud, fuerza, velocidad, inteligencia, resistencia;
        int salud_int, fuerza_int, velocidad_int, inteligencia_int, resistencia_int;
        stringstream stream(linea);
        getline(stream, titulo, delimitador);
        titulo.erase(0,1);
        if(titulo == "Peleador" || titulo == "peleador" || titulo == "Arena" || titulo == "arena"){
            getline(stream, nombre, delimitador);
            getline(stream, salud, delimitador);
            salud_int = stoi(salud);
            getline(stream, velocidad, delimitador);
            velocidad_int = stoi(velocidad);
            getline(stream, inteligencia, delimitador);
            inteligencia_int = stoi(inteligencia);
            getline(stream, resistencia, delimitador);
            resistencia_int = stoi(resistencia);
        } else {
            getline(stream, nombre, delimitador);
            getline(stream, tipo, delimitador);
            getline(stream, salud, delimitador);
            salud_int = stoi(salud);
            getline(stream, velocidad, delimitador);
            velocidad_int = stoi(velocidad);
            getline(stream, inteligencia, delimitador);
            inteligencia_int = stoi(inteligencia);
            getline(stream, resistencia, delimitador);
            resistencia_int = stoi(resistencia);
        }
        peleador p(salud_int, fuerza_int, velocidad_int, inteligencia_int, resistencia_int);
        cout << p.desgaste(1)<<endl;
    }
    return 0;
}