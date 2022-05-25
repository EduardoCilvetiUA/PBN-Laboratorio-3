#include "peleador.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>


using namespace std;

peleador::peleador(string nombre, int salud_int, int fuerza_int, int velocidad_int, int inteligencia_int, int resistencia_int){
    this -> salud_int = salud_int;
    this -> fuerza_int = fuerza_int;
    this -> velocidad_int = velocidad_int;
    this -> inteligencia_int = inteligencia_int;
    this -> resistencia_int = resistencia_int;
    this -> nombre = nombre;
    this -> habilidad = habilidad;
    this -> multiplicador = multiplicador;
    this -> critico = critico;
}
double peleador::desgaste(int turno){
    double e = 2.72;
    double elevado = -20.0*turno/resistencia_int;
    double multiplicador = pow(e,elevado)*(1+(20.0*turno/resistencia_int));
    return multiplicador;
}

int peleador::impacto(double desgaste){
    int golpe = critico*(((velocidad_int*fuerza_int)/(velocidad_int + fuerza_int)) + inteligencia_int)*desgaste;
    return golpe;
}
int peleador::set_critico(){
    int valor_random = rand() %3;
    this -> critico =valor_random;
    return critico;
}
string peleador::get_nombre(){
    return nombre;
}
int peleador::get_salud(){
    return salud_int;
}
int peleador::get_fuerza(){
    return fuerza_int;
}
int peleador::get_resistencia(){
    return resistencia_int;
}
int peleador::get_velocidad(){
    return velocidad_int;
}
int peleador::get_inteligencia(){
    return inteligencia_int;
}
int peleador::get_critico(){
    return critico;
}
void peleador::set_salud(int salud_int){
    this -> salud_int =salud_int;
}
void peleador::set_fuerza(int fuerza_int){
    this -> fuerza_int =fuerza_int;
}
void peleador::set_velocidad(int velocidad_int){
    this -> velocidad_int =velocidad_int;
}
void peleador::set_resistencia(int resistencia_int){
    this -> resistencia_int =resistencia_int;
}
void peleador::set_inteligencia(int inteligencia_int){
    this -> inteligencia_int =inteligencia_int;
}
void peleador::set_nombre(string nombre){
    this -> nombre =nombre;
}

void peleador::change_salud(int salud_O, int salud_int){
    this -> salud_int = salud_int + salud_O;
}
void peleador::change_fuerza(int fuerza_O, int fuerza_int){
    this -> fuerza_int = fuerza_int + fuerza_O;
}
void peleador::change_velocidad(int velocidad_O, int velocidad_int){
    this -> velocidad_int = velocidad_int + velocidad_O;
}
void peleador::change_resistencia(int resistencia_O, int resistencia_int){
    this -> resistencia_int = resistencia_int + resistencia_O;
}
void peleador::change_inteligencia(int inteligencia_O, int inteligencia_int){
    this -> inteligencia_int = inteligencia_int + inteligencia_O;
}
void peleador::set_habilidad(int habilidad){
    this -> habilidad = habilidad;
}

int peleador::get_habilidad(){
    return habilidad;
}
void peleador::set_salud_original(int salud){
    this -> salud_original_int = salud;
}
void peleador::rey_muertos(){
    int valor_random = (rand() %10) +1;
    cout<<valor_random<<endl;
    if(valor_random < 5){
        cout<<"el numero "<<valor_random << " < 5"<<endl;
        this -> salud_int = salud_original_int / 2;
    }
    else{
        this -> salud_int = 0;
    }
}