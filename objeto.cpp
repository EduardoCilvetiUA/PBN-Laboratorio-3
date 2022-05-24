#include "objeto.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

objeto::objeto(string nombre, string peleador){
    this -> nombre = nombre;
    this -> peleador = peleador;
}
void objeto::set_nombre(string nombre, string peleador){
    this -> nombre =nombre;
    this -> peleador =peleador;
}
string objeto::get_nombre(){
    return nombre;
}