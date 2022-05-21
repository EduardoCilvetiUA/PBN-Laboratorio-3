#include <iostream>
#include <sstream>
#include <fstream>
#include "peleador.h"
#include "objeto.h"

using namespace std;

int main(){
    ifstream entrada("data tarea 3.csv");

    string linea;
    char delimitador = ';';
    int player1[5];
    int player2[5];
    string names[2];
    int contador_peleador=1;
    peleador P1("", 0, 0, 0, 0, 0);
    peleador P2("", 0, 0, 0, 0, 0);
    while(getline(entrada, linea))
    {
        string titulo, nombre, leyenda, tipo;
        string salud, fuerza, velocidad, inteligencia, resistencia;
        int salud_int, fuerza_int, velocidad_int, inteligencia_int, resistencia_int;
        stringstream stream(linea);
        getline(stream, titulo, delimitador);
        titulo.erase(0,1);
        if(titulo == "Peleador" || titulo == "peleador"){
            getline(stream, nombre, delimitador);
            getline(stream, salud, delimitador);
            salud_int = stoi(salud);
            getline(stream, fuerza, delimitador);
            fuerza_int = stoi(fuerza);
            getline(stream, velocidad, delimitador);
            velocidad_int = stoi(velocidad);
            getline(stream, inteligencia, delimitador);
            inteligencia_int = stoi(inteligencia);
            getline(stream, resistencia, delimitador);
            resistencia_int = stoi(resistencia);
            if(contador_peleador == 1){
                P1.set_salud(salud_int);
                P1.set_fuerza(fuerza_int);
                P1.set_velocidad(velocidad_int);
                P1.set_inteligencia(inteligencia_int);
                P1.set_resistencia(resistencia_int);
                P1.set_nombre(nombre);
                contador_peleador = 2;
            }
            else{
                P2.set_salud(salud_int);
                P2.set_fuerza(fuerza_int);
                P2.set_velocidad(velocidad_int);
                P2.set_inteligencia(inteligencia_int);
                P2.set_resistencia(resistencia_int);
                P2.set_nombre(nombre);
            }
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
        if(titulo == "Objeto" || titulo == "objeto"){
            
        }
        
    }
    cout << P1.get_nombre() << endl;



    return 0;
}