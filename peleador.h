#include <string>
#include <iostream>

using namespace std;

class peleador {//En las clases puedo DEJAR COSAS ESCONDIDAS
private: //Es una constumbre que las propiedades sean privadas
	string nombre;
    int salud_int;
    int fuerza_int;
    int velocidad_int;
    int inteligencia_int;
    int resistencia_int;
public:
	peleador(string, int, int, int, int, int);
    double desgaste(int);
    string get_nombre();
};
