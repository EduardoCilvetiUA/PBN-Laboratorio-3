class peleador {//En las clases puedo DEJAR COSAS ESCONDIDAS
private: //Es una constumbre que las propiedades sean privadas
	int salud_int;
    int fuerza_int;
    int velocidad_int;
    int inteligencia_int;
    int resistencia_int;
public:
	peleador(int, int, int, int, int);
    double desgaste(int);
};
