#include <iostream>
#include <sstream>
#include <fstream>
#include "peleador.h"

using namespace std;

int main(){
    ifstream entrada("data tarea 3.csv");

    string linea;
    char delimitador = ';';
    int player1[5];
    int player2[5];
    string names[2];
    while(getline(entrada, linea))
    {
        string titulo, nombre, leyenda, tipo;
        string salud, fuerza, velocidad, inteligencia, resistencia;
        int salud_int, fuerza_int, velocidad_int, inteligencia_int, resistencia_int;
        int contador_peleador=1;
        stringstream stream(linea);
        getline(stream, titulo, delimitador);
        titulo.erase(0,1);
        if(titulo == "Peleador" || titulo == "peleador" || titulo == "Arena" || titulo == "arena"){
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
        
        if(titulo == "Peleador" || titulo == "peleador"){
            if(contador_peleador == 1){
                player1[0] = salud_int;
                player1[1] = fuerza_int;
                player1[2] = velocidad_int;
                player1[3] = inteligencia_int;
                player1[4] = resistencia_int;
                names[0]= nombre;
            }
            else{
                player2[0] = salud_int;
                player2[1] = fuerza_int;
                player2[2] = velocidad_int;
                player2[3] = inteligencia_int;
                player2[4] = resistencia_int;
                names[1]= nombre;
            }
            contador_peleador ++;
        } else if(titulo == "Objeto" || titulo == "objeto"){


        }
        
    }
    peleador P1(names[0], player1[0], player1[1], player1[2], player1[3], player1[4]);
    peleador P2(names[1], player2[0], player2[1], player2[2], player2[3], player2[4]);
    cout << P1.get_nombre() << endl;



    return 0;
}