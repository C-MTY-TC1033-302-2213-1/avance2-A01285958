/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
*/

#include "Pelicula.h"

//Constructores: vacio y con parametros
Pelicula::Pelicula():Video(){
    oscares = 100;
}

Pelicula::Pelicula(string _ID,
string _Titulo,
int _duracion,
string _genero,
double _Calificacion, int _oscares):Video(_ID, _Titulo, _duracion, _genero, _Calificacion){
    oscares = _oscares;
}

//Metodos modificadores
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

//Metodos de acceso
int Pelicula::getOscares(){
    return oscares;
}

//Otros metodos
string Pelicula::str(){
    //Tenemos acceso directo a los atributos de la clase Padre porque son Protected
    return ID  + ' ' +  Titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(Calificacion) + ' ' + to_string(oscares);
}