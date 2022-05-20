#include "peleador.h"
#include <iostream>
#include <math.h>
#include <stdio.h>


using namespace std;

peleador::peleador(int salud_int, int fuerza_int, int velocidad_int, int inteligencia_int, int resistencia_int){
    this -> salud_int = salud_int;
    this -> fuerza_int = fuerza_int;
    this -> velocidad_int = velocidad_int;
    this -> inteligencia_int = inteligencia_int;
    this -> resistencia_int = resistencia_int;
}
double peleador::desgaste(int turno){
    cout << "Resistencia: "<< resistencia_int << endl;
    double e = 2.72;
    double elevado = -20.0*turno/resistencia_int;
    double resistencia_nueva = pow(e,elevado)*(1+(20.0*turno/resistencia_int));
    return resistencia_nueva;
}