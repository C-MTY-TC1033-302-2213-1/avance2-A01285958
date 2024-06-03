/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
¿Qué aprendí en el desarrollo de esta clase? Aprendí sobre la herencia, sobre la clase base y sus clases derivadas, 
y como esto ayuda a organizar el codigo de una maner más clara y comprensible 
*/

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include <string>
#include "Video.h"
#include <iostream>

using namespace std;
//Clase Pelicula es derivada de Video
class Pelicula : public Video{
    private:
    int oscares;


    public:
    //Constructores: vacio y con parametros
    Pelicula();
    Pelicula(string _ID,
    string _Titulo,
    int _duracion,
    string _genero,
    double _Calificacion, int _oscares);

    //Metodos modificadores
    void setOscares(int _oscares);

    //Metodos de acceso
    int getOscares();

    //Otros metodos
    string str();
};

#endif /* Pelicula_h */