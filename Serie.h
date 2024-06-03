/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
¿Qué aprendí en el desarrollo de esta clase? Aprendí como se puede usar la herencia 
y la composicion en una clase y como esto ayuda para hacer más comprensible el código y poder tener 
más flexibilidad sobre el 
*/

#ifndef Serie_h
#define Serie_h

#include <stdio.h>
#include <string>
//Para herencia
#include "Video.h"
//Para composicion
#include "Episodio.h"

using namespace std;

class Serie : public Video{
private:
 Episodio episodios[5];
 int cantidad;


public:
//Metodos Constructores
Serie();
Serie(string _ID, string _titulo, int _duracion, string _genero,  double _calificacion);

//Duracion de la serie (se sumara la duración de los episodios)
void calculaDuracion();

//Metodos Modificadores
void setEpisodio(int posicion, Episodio episodio);
void setcantidad(int _cantidad);


//Metodos De Acceso
Episodio getEpisodio(int posicion);
int getCantidad();


//Otros Metodos
double calculaPromedio();

string str();

void agregaEpisodio(Episodio episodio);
};

#endif /* Serie_h */