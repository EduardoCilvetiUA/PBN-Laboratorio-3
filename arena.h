#include <string>
#include <iostream>

using namespace std;

class arena {//En las clases puedo DEJAR COSAS ESCONDIDAS
private: //Es una constumbre que las propiedades sean privadas
	string nombre;
    string leyenda;
public:
	arena(string);
    void set_nombre(string);
    void set_leyenda(string);
    string get_nombre();
    string get_leyenda();
    int new_salud(int, int);
    int new_fuerza(int, int);
    int new_resistencia(int, int);
    int new_velocidad(int, int);
    int new_inteligencia(int, int);
    int habilidades_especiales();
};