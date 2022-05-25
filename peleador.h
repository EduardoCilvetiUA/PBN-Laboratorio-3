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
    int habilidad;
    int multiplicador;
    int critico;
    int salud_original_int;
public:
	peleador(string, int, int, int, int, int);
    double desgaste(int);
    int impacto(double);
    string get_nombre();
    int get_salud();
    int get_fuerza();
    int get_resistencia();
    int get_velocidad();
    int get_inteligencia();
    int get_habilidad();
    int get_critico();
    int set_critico();
    void set_salud_original(int);
    void set_habilidad(int);
    void set_salud(int);
    void set_fuerza(int);
    void set_velocidad(int);
    void set_resistencia(int);
    void set_inteligencia(int);
    void set_nombre(string);
    void change_salud(int, int);
    void change_fuerza(int, int);
    void change_velocidad(int, int);
    void change_resistencia(int, int);
    void change_inteligencia(int, int);
    void rey_muertos();
};
