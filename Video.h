/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
¿Qué aprendí en el desarrollo de esta clase? Aprendí sobre los atributos protected y como se 
utilizan dentro de una clase, también sobre la herencia, siendo esta la clase base.
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>

using namespace std;

//Atrubutos
class Video{
protected: 
    string ID;
    string Titulo;
    int duracion;
    string genero;
    double Calificacion;

//Metodos
public:
    Video();
    Video(string _ID,
    string _Titulo,
    int _duracion,
    string _genero,
    double _Calificacion);

//Metodos modificadores
    void setID(string _ID);
    void setTitulo(string _Titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _Calificacion);

//Metodos de acceso
    string getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

//Otros Metodos
 virtual string str();
};


#endif /* Video_h */