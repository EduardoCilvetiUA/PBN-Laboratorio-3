#include "arena.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

arena::arena(string nombre){
    this -> nombre = nombre;
}
void arena::set_nombre(string nombre){
    this -> nombre =nombre;
}
void arena::set_leyenda(string leyenda){
    this -> leyenda =leyenda;
}
string arena::get_nombre(){
    return nombre;
}
string arena::get_leyenda(){
    return leyenda;
}
int arena::new_salud(int personaje, int arena){
    return personaje + (personaje * arena * 0.01);
}
int arena::new_fuerza(int personaje, int arena){
    return personaje + (personaje * arena* 0.01);
}
int arena::new_resistencia(int personaje, int arena){
    return personaje + (personaje * arena* 0.01);
}
int arena::new_velocidad(int personaje, int arena){
    return personaje + (personaje * arena* 0.01);
}
int arena::new_inteligencia(int personaje, int arena){
    return personaje + (personaje * arena* 0.01);
}