/*
Nombre: Rosila Muñoz Espinosa
Matricula: A01285958
Carrera: ITC
Fecha: 26-Mayo-24
¿Qué aprendí en el desarrollo de esta clase? Aprendí sobre el polimorfismo, y como se utiliza en la clase video en 
el metodo str, para llamar al mismo metodo pero para diferentes objetos, que en este caso sería para Pelicula o Serie.   
*/
#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <stdio.h>
#include <string>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;


const int MAX_VIDEOS = 100;
class Polimorfismo{
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:
    //Metodos Constructores
    Polimorfismo();
    //Otros Metodos
    void leerArchivo(string nombre);

    //Metodos Modifcadores -setters
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //Metodos de acceso - getters
    Video* getPtrVideo(int index);
    int getCantidad();


    //Otros métodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion); // calificacion o Calificacion
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};



#endif /* Polimorfismo_h */