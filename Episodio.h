/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
¿Qué aprendí en el desarrollo de esta clase? Reforze lo que habia aprendido
 el semestre pasado
*/

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>
using namespace std;
class Episodio{
private:
    string titulo;
    int temporada;
    int calificacion;

public: 
    Episodio();
    Episodio(string _titulo,
    int _temporada,
    int _calificacion);

//Metodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

//Metodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

//Otros Metodos
    string str();
};


#endif /* Video_h */