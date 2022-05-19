class peleador {//En las clases puedo DEJAR COSAS ESCONDIDAS
private: //Es una constumbre que las propiedades sean privadas
	int salud;
    int fuerza;
    int velocidad;
    int inteligencia;
    int resistencia;
public:
	peleador(double, double);
	double ataque();
	double get_base();
	void set_base(double);
};
