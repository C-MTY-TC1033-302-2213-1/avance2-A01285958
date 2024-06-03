/*Nombre: Rosila Muñoz
Carrera: ITC
Matricula: A01285958
Fecha: 20/05/2024
*/

#include "Serie.h"

//Metodos Constructores
Serie::Serie() : Video(){
    //solo vamos a inicializar cantidad
    cantidad = 0;
}

Serie::Serie(string _ID, string _Titulo, int _duracion, string _genero,  double _Calificacion):Video(_ID, _Titulo, _duracion, _genero, _Calificacion){
    cantidad = 0;
}

//Duracion de la serie (se sumaran los episodios con el atributo temporada )
void Serie::calculaDuracion(){
    duracion = 0;
    //Suma de todos los episodios (usando el atributo temporada)
    for (int index = 0; index < cantidad; index++){
        duracion += episodios[index].getTemporada();

    }
}

//Metodos Modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    //primero validar que exista ese episodio
    if (posicion >= 0 && posicion < cantidad ){
        episodios[posicion] = episodio;
    }
}

//Cambiar el valor del atributo cantidad con el nuevo valor recibido _cantidad
void Serie::setcantidad(int _cantidad){
    cantidad = _cantidad;
}


//Metodos De Acceso
Episodio Serie::getEpisodio(int posicion){
    //Crea un objeto del tipo episodio y lo inicializa con el constructor default
    Episodio epi;
    //Validar que exista el episodio solicitado (posicion)
    if(posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }
    //Si no exsite se retorna un default, si se cumple la condicion if no se retorna el valor, si no se cumple se retorna el valor
    return epi;
}

//Retorna el valor del atributo cantidad
int Serie::getCantidad(){
    return cantidad;
}


//Otros Metodos
double Serie::calculaPromedio(){
    double acum = 0;

    for(int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }
    //validar que tenga episodios
    if(cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
}

//overriding del metodo str() de la clase Base
string Serie::str(){
    string serie = ID  + ' ' +  Titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(Calificacion) + ' ' + to_string(cantidad);
    string InfoEpisodios;

    //Concatenar información de todos los episodios
    for(int index = 0; index < cantidad; index++){
        InfoEpisodios += episodios[index].str() + '\n';
        /*Otra forma de obtenr la información de los episodios es
        InfoEpisodios += episodios[i].getTitulo() + ' ' + to_string(episodios[i].getTemporada()) + ' ' + to_string(episodios[i].getCalificacion()) + '\n';
        */ 
    }

    //Verificar si la serie tiene episodios, sino solo retornar la información de la serie
    if(cantidad == 0){
        return serie;
    } else{
        return serie + '\n' + InfoEpisodios;
    }
}

//Agrega un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++]= episodio;
    }
}