#include <string>
#include <iostream>

using namespace std;

class objeto {//En las clases puedo DEJAR COSAS ESCONDIDAS
private: //Es una constumbre que las propiedades sean privadas
	string nombre;
    string peleador;
public:
	objeto(string, string);
    void set_nombre(string, string);
    string get_nombre();
};