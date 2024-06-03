/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
*/

#include "Video.h"

//Constructores
Video::Video(){
    ID = "A01285958";
    Titulo = "Rosila Munoz";
    duracion = 100;
    genero = "Femenino";
    Calificacion = 100;
}

Video::Video(string _ID,
    string _Titulo,
    int _duracion,
    string _genero,
    double _Calificacion){
        ID = _ID;
        Titulo = _Titulo;
        duracion = _duracion;
        genero = _genero;
        Calificacion = _Calificacion;
    }

//Metodos modificadores
void Video::setID(string _ID){
    ID = _ID;
}

void Video::setTitulo(string _Titulo){
    Titulo = _Titulo;
}

void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}

void Video::setCalificacion(double _Calificacion){
    Calificacion = _Calificacion;
}

//Metodos de acceso
string Video::getID(){
    return ID;
}

string Video::getTitulo(){
    return Titulo;
}

int Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}

double Video::getCalificacion(){
    return Calificacion;
}

//Otros Metodos
string Video::str(){
    return ID  + ' ' +  Titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(Calificacion);
}