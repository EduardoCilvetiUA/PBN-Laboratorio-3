#include "peleador.h"
#include <iostream>

using namespace std;

peleador::peleador(int salud_int, int fuerza_int, int velocidad_int, int inteligencia_int, int resistencia_int){
    this -> salud_int = salud_int;
    this -> fuerza_int = fuerza_int;
    this -> velocidad_int = velocidad_int;
    this -> inteligencia_int = inteligencia_int;
    this -> resistencia_int = resistencia_int;
}
int peleador::desgaste(int turno){
    cout << turno << endl;
    cout << "Resistencia: "<< resistencia_int << endl;
    int e = 2.72;
    int resistencia_nueva = e^(-20*turno/resistencia_int)*(1+(20*turno/resistencia_int));
    return resistencia_nueva;
}