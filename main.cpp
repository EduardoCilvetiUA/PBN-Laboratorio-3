#include <iostream>
#include <sstream>
#include <fstream>
#include "peleador.h"
#include "objeto.h"
#include "arena.h"

using namespace std;

int main(){
    ifstream entrada("data tarea 3.csv");
    srand(time(NULL));
    string linea;
    char delimitador = ';';
    int contador_peleador=1;
    int contador_objeto1 = 1;
    int contador_objeto2 = 1;
    int contador_peleador_O = 1;
    peleador P1("", 0, 0, 0, 0, 0);
    peleador P2("", 0, 0, 0, 0, 0);
    objeto P101("", "");
    objeto P102("", "");
    objeto P201("", "");
    objeto P202("", "");
    arena Arena("");
    while(getline(entrada, linea))
    {
        string titulo, nombre, leyenda, tipo;
        string salud, fuerza, velocidad, inteligencia, resistencia;
        int salud_int, fuerza_int, velocidad_int, inteligencia_int, resistencia_int;
        stringstream stream(linea);
        getline(stream, titulo, delimitador);
        titulo.erase(0,1);
        if(titulo == "Peleador" || titulo == "peleador"){
            getline(stream, nombre, delimitador);
            getline(stream, salud, delimitador);
            salud_int = stoi(salud);
            getline(stream, fuerza, delimitador);
            fuerza_int = stoi(fuerza);
            getline(stream, velocidad, delimitador);
            velocidad_int = stoi(velocidad);
            getline(stream, inteligencia, delimitador);
            inteligencia_int = stoi(inteligencia);
            getline(stream, resistencia, delimitador);
            resistencia_int = stoi(resistencia);
            if(contador_peleador == 1){
                P1.set_salud(salud_int);
                P1.set_fuerza(fuerza_int);
                P1.set_velocidad(velocidad_int);
                P1.set_inteligencia(inteligencia_int);
                P1.set_resistencia(resistencia_int);
                P1.set_nombre(nombre);
                contador_peleador = 2;
            }
            else{
                P2.set_salud(salud_int);
                P2.set_fuerza(fuerza_int);
                P2.set_velocidad(velocidad_int);
                P2.set_inteligencia(inteligencia_int);
                P2.set_resistencia(resistencia_int);
                P2.set_nombre(nombre);
            }
        } else if (titulo == "Objeto" || titulo == "objeto"){
            getline(stream, nombre, delimitador);
            getline(stream, tipo, delimitador);
            getline(stream, salud, delimitador);
            salud_int = stoi(salud);
            getline(stream, fuerza, delimitador);
            fuerza_int = stoi(fuerza);
            getline(stream, velocidad, delimitador);
            velocidad_int = stoi(velocidad);
            getline(stream, inteligencia, delimitador);
            inteligencia_int = stoi(inteligencia);
            getline(stream, resistencia, delimitador);
            resistencia_int = stoi(resistencia);
            if(contador_peleador_O == 1 || contador_peleador_O == 2){
                if (contador_objeto1 == 1){
                    P101.set_nombre(nombre, P1.get_nombre());
                    contador_objeto1++;
                }
                else{
                    P102.set_nombre(nombre, P1.get_nombre());
                }
                P1.change_salud(salud_int, P1.get_salud());
                P1.change_fuerza(fuerza_int, P1.get_fuerza());
                P1.change_resistencia(resistencia_int, P1.get_resistencia());
                P1.change_velocidad(velocidad_int, P1.get_velocidad());
                P1.change_inteligencia(inteligencia_int, P1.get_inteligencia());
                contador_peleador_O ++;
            }
            else if (contador_peleador_O == 3 || contador_peleador_O == 4){
                if (contador_objeto2 == 1){
                    P201.set_nombre(nombre, P2.get_nombre());
                    contador_objeto2++;
                }
                else{
                    P202.set_nombre(nombre, P2.get_nombre());
                }
                P2.change_salud(salud_int, P2.get_salud());
                P2.change_fuerza(fuerza_int, P2.get_fuerza());
                P2.change_resistencia(resistencia_int, P2.get_resistencia());
                P2.change_velocidad(velocidad_int, P2.get_velocidad());
                P2.change_inteligencia(inteligencia_int, P2.get_inteligencia());
            }
        } else {
            getline(stream, nombre, delimitador);
            Arena.set_nombre(nombre);
            getline(stream, salud, delimitador);
                salud_int = stoi(salud);
                P1.set_salud(Arena.new_salud(P1.get_salud(), salud_int));
                P2.set_salud(Arena.new_salud(P2.get_salud(), salud_int));
                getline(stream, fuerza, delimitador);
                fuerza_int = stoi(fuerza);
                P1.set_fuerza(Arena.new_fuerza(P1.get_fuerza(), fuerza_int));
                P2.set_fuerza(Arena.new_fuerza(P2.get_fuerza(), fuerza_int));
                
                getline(stream, velocidad, delimitador);
                velocidad_int = stoi(velocidad);
                P1.set_velocidad(Arena.new_velocidad(P1.get_velocidad(), velocidad_int));
                P2.set_velocidad(Arena.new_velocidad(P2.get_velocidad(), velocidad_int));
                getline(stream, inteligencia, delimitador);
                inteligencia_int = stoi(inteligencia);
                P1.set_inteligencia(Arena.new_inteligencia(P1.get_inteligencia(), inteligencia_int));
                P2.set_inteligencia(Arena.new_inteligencia(P2.get_inteligencia(), inteligencia_int));
                getline(stream, resistencia, delimitador);
                resistencia_int = stoi(resistencia);
                P1.set_resistencia(Arena.new_resistencia(P1.get_resistencia(), resistencia_int));
                P2.set_resistencia(Arena.new_resistencia(P2.get_resistencia(), resistencia_int));
                salud_int = stoi(salud);
                getline(stream, leyenda, delimitador);
                Arena.set_leyenda(leyenda);

        }
    }
    
    P1.set_salud_original(P1.get_salud());
    P2.set_salud_original(P2.get_salud());
    ofstream archivo;
    archivo.open("OUTPUT.txt",ios :: out);// Abriendo el archivo
    if(archivo.fail()){
        cout <<"No se pudo abrir el archivo";
        exit(1);
    }
    if(P102.get_nombre() != ""){
        archivo << P1.get_nombre()<<" equipado con los objetos "<< P101.get_nombre() << " y " << P102.get_nombre() << endl;
    }
    else{
        archivo << P1.get_nombre()<<" equipado con el objeto "<< P101.get_nombre()<< endl;
    }

    archivo << "Se enfrenta contra:" << endl;

    if(P202.get_nombre() != ""){
        archivo << P2.get_nombre()<<" equipado con los objetos "<< P201.get_nombre() << " y " << P202.get_nombre() << endl;
    }
    else{
        archivo << P2.get_nombre()<<" equipado con el objeto "<< P201.get_nombre()<< endl;
    }
    archivo << "=====================================================================================================================" << endl;
    archivo << "Se enfrentaran en el la arena llamada: " << Arena.get_nombre()<<endl;
    archivo << "=====================================================================================================================" << endl;
    archivo << P1.get_nombre()<< endl;
    archivo <<"Salud P1: " << P1.get_salud() << endl;
    archivo <<"Fuerza: " << P1.get_fuerza() << endl;
    archivo <<"Velocidad: " << P1.get_velocidad() << endl;
    archivo <<"Inteligencia: " << P1.get_inteligencia() << endl;
    archivo <<"Resistencia: " << P1.get_resistencia() << endl;
    archivo << "=====================================================================================================================" << endl;
    archivo<<P2.get_nombre()<< endl;
    archivo <<"Salud P2: " << P2.get_salud() << endl;
    archivo <<"Fuerza: " << P2.get_fuerza() << endl;
    archivo <<"Velocidad: " << P2.get_velocidad() << endl;
    archivo <<"Inteligencia: " << P2.get_inteligencia() << endl;
    archivo <<"Resistencia: " << P2.get_resistencia() << endl;
    archivo << "=====================================================================================================================" << endl;
    P1.set_habilidad(Arena.habilidades_especiales());
    P2.set_habilidad(Arena.habilidades_especiales());
    if(P1.get_habilidad() != 0){
        if(P1.get_habilidad() == 1) archivo<<"La arena a conferido a "<<P1.get_nombre()<< " la habilidad 'rey de los muertos' "<< endl;
        else archivo<<"La arena a conferido a "<<P1.get_nombre()<< " la habilidad 'ultimo aliento' "<< endl;
    }
    if(P2.get_habilidad() != 0){
        if(P2.get_habilidad() == 1) archivo<<"La arena a conferido a "<<P2.get_nombre()<< " la habilidad 'rey de los muertos' "<< endl;
        else archivo<<"La arena a conferido a "<<P2.get_nombre()<< " la habilidad 'ultimo aliento' "<< endl;
    }
    archivo << "=====================================================================================================================" << endl;
    archivo << "INICIA LA PELEA"<< endl;
    int vivos = 0;
    int turnos = 1;
    while(vivos == 0){
        P1.set_critico();
        int golpe = P1.impacto(P1.desgaste(turnos));
        archivo << P1.get_nombre();
        if(golpe == 0){
            archivo << " pierde el ataque" << endl;
        }
        else{
            if(P1.get_critico() == 1) archivo << " ataca ";
            else archivo << " hace un critico, ";
            int nueva_salud = P2.get_salud() - golpe;
            int diferencia;
            if(nueva_salud < 0){
                diferencia = golpe - (nueva_salud*-1);
                P2.set_salud(0);
            }
            else{
                diferencia = golpe;
                P2.set_salud(nueva_salud);
            }
            archivo << "con un golpe de "<< golpe << " y "<< P2.get_nombre()<< " pierde " << diferencia<<" de vida y quedando con "<< P2.get_salud()<<" de salud."<< endl;
        }
        if(P2.get_salud() == 0){
            archivo<< "=============================================== "<<P2.get_nombre()<<" muere ==============================================="<< endl;
            if(P2.get_habilidad() == 1){
                P2.rey_muertos();
                if(P2.get_salud() != 0){
                    archivo<<"-------------------------------- Habilidad especial Rey de los muerto activada -----------------------------------------------"<<endl;
                }
                else{
                    vivos = 1;
                }
            }
            else{
                vivos =1;
            }
        }
        archivo << endl;
        if(vivos == 0){
            P2.set_critico();
            golpe = P2.impacto(P2.desgaste(turnos));
            archivo << P2.get_nombre();
            if(golpe <= 0){
                archivo << " pierde el ataque" << endl;
            }
            else{
                if(P1.get_critico() == 1) archivo << " ataca ";
                else archivo << " hace un critico, ";
                int nueva_salud = P1.get_salud() - golpe;
                int diferencia;
                if(nueva_salud < 0){
                    diferencia = golpe - (nueva_salud*-1);
                    P1.set_salud(0);
                }
                else{
                    diferencia = golpe;
                    P1.set_salud(nueva_salud);
                }
                archivo << "con un golpe de "<< golpe << " y "<< P1.get_nombre()<< " pierde " << diferencia<<" de vida y quedando con "<< P1.get_salud()<<" de salud."<< endl;
            }
            archivo << "============================================ Fin "<< turnos<<"° turno ============================================"<< endl;
            }
            if(P1.get_salud() == 0){
            archivo<< "=============================================== "<<P1.get_nombre()<<" muere ==============================================="<< endl;
            if(P1.get_habilidad() == 1){
                cout<<"Si hay rey de los muertos"<< endl;
                P1.rey_muertos();
                if(P1.get_salud() != 0){
                    archivo<< "-------------------------------------- Habilidad especial Rey de los muerto activada -----------------------------------------------------"<<endl;
                }
                else{
                    vivos = 1;
                }
            }
            else{
                vivos = 1;
            }
        }
        turnos++;
    }

    archivo.close();
    return 0;
}