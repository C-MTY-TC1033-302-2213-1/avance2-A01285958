/*
Nombre: Rosila Muñoz Espinosa
Matricula: A01285958
Carrera: ITC
Fecha: 26-Mayo-24

*/

#include "Polimorfismo.h"

//Metodos Constructores
Polimorfismo::Polimorfismo(){
    for(int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    //Inicializar cantidad de videos
    cantidad = 0;
}
//Metodos Modifcadores -setters
void Polimorfismo::setPtrVideo(int index, Video *video){
    //validar index - >=0 && <cantidad
    if  ( index >= 0 && index <= cantidad){
        //Cambiar el apuntador
        arrPtrVideos[index] = video;
    }
}

void Polimorfismo::setCantidad(int _cantidad){
    // cambia el valor de atributo cantidad 
    // validar que _cantidad este entre 0 .. MAX_VIDEOS -1, de lo contrario NO se modifica el valor de la cantidad

    //validar el valor de _cantidad
    if(_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
    cantidad = _cantidad;
    }
}

//Metodos de acceso - getters
Video* Polimorfismo::getPtrVideo(int index){
    //Validar que exista el index - posicion
    if ( index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }

    //Si no existe
    return nullptr;

}

int Polimorfismo::getCantidad(){
    return cantidad;
}


//Otros métodos
void Polimorfismo::reporteInventario(){
    //declaracion de contadores
    int contPeliculas, contSeries;
    
    //Inicializar 
    contPeliculas = 0;
    contSeries = 0;

    //recorrer todo el areglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index] -> str() << endl;
        // * indirección (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index])==typeid(Pelicula)){
            contPeliculas++;
        }
        else if(typeid(*arrPtrVideos[index])==typeid(Serie)){
            contSeries++;
        }
    }
    //fuera del for desplegar los totales
    cout << "Peliculas: " << contPeliculas << endl;
    cout << "Series: " << contSeries << endl;
}

void Polimorfismo::reporteCalificacion(double _calificacion){
    //contador total
    int total;

    //Inicializar
    total = 0;
    for(int index = 0; index < cantidad; index++){
        //verificar si tiene la calificacion == _calificacion
        //si es un apuntador se usa ->
        if(arrPtrVideos[index] -> getCalificacion() == _calificacion){
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }

    }
    //desplegar el total, fuera del for
    cout << "Total = " << total << endl;
} 

void Polimorfismo::reporteGenero(string _genero){
    //contador total
    int total;

    //Inicializar
    total = 0;
    for(int index = 0; index < cantidad; index++){
        //verificar si tiene el genero == _genero
        // Si es apuntador se usa ->
        if(arrPtrVideos[index] -> getGenero() == _genero){
            cout << arrPtrVideos[index] -> str() <<endl;
            total++;
        }
    }
    //Desplegar el total fuera del for, para que solo se imprima el total al final
    cout << "Total = " << total << endl;

}

void Polimorfismo::reportePeliculas(){
    //Declarar contador
    int contPeliculas;

    //Inicializar
    contPeliculas = 0;

    //Recorrer el arreglo 
    for(int index = 0; index < cantidad; index++){
        if(typeid(*arrPtrVideos[index])==typeid(Pelicula)){
            cout << arrPtrVideos[index] -> str() << endl;
            contPeliculas++;
        }
        
    }
    //Fuera del for, si contador de peliculas es = 0, desplegar que no hay peliculas
    if(contPeliculas == 0){
            cout << "No peliculas"<<endl;
        } 
    else{
            //Desplegar el total
            cout << "Total Peliculas = "<< contPeliculas << endl;
        }
}

void Polimorfismo::reporteSeries(){
    //Declarar contador
    int contSeries;

    //Inicializar
    contSeries = 0;

    //Recorrer el arreglo 
    for(int index = 0; index < cantidad; index++){
        if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index] -> str() << endl;
            contSeries++;
        }
        
    }
    //Fuera del for, si contador de peliculas es = 0, desplegar que no hay peliculas
    if(contSeries == 0){
            cout << "No series"<<endl;
        } 
    else{
           //Desplegar el total
            cout << "Total Series = "<< contSeries << endl; 
        }
        
}


void Polimorfismo::leerArchivo(string _nombre){
    // Todas las declaraciones se hacen abajo del encabezado estandar c++ ITESM
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7]; //arreglo de 7 elementos de string, para almacenar datos de la linea del archivo ya separados
    string line, word; //line almacena la linea leida y word la palabra que se saca de la linea
    int cantidadPeliculas = 0; //Contador de Peliculas, inicia en 0
    int cantidadSeries = 0; //Contador de Series, inicia en 0
    int iR = 0, index;
    double promedio;

    entrada.open(_nombre, ios::in); //Abrir archivo de entrada

    while (getline(entrada, line)){ //Lee una linea del archivo y la almacena en line
        stringstream s(line); //Separa las palabras split()
        iR = 0; // Cada vez que inicie una nueva libea inicializar iR = 0

        //Ciclo que almacena caracteres de s y los almacena en word hasta el delimitador ','
        while (getline(s, word, ',')){
            row[iR++] = word; // añade word al arreglo row e incrementa iR para la prox palabra
        }

        //Determinar si el P-Pelicula, S-Serie, E-Episodio
        if (row[0] == "P"){
            //Se crea un apuntador usando el operador new y el constructor con Parametros y se guarda en arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas] ->str() << endl;
            cantidadPeliculas++; //incrementa cantidad de peliculas
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //cout << "Serie" << arrPtrSeries[cantidadSeries] ->str() << endl;
            cantidadSeries++;
        }
        else if(row[0] == "E"){
            //Calcula a que Serie le pertence el episodio
            index = stoi(row[1]) - 500;
            /*Se agrega el episodio usando agregaEpisodio
            Se crea el apuntador y se convierte a bojeto usando el
            operador de indirección*/
            arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            //cout << "Episodio" << arrPtrSeries[index]->str()<<endl;
        }

    }
    /* Se termino de leer todo el archivo 
    ahora se guardan todos los apuntadores de Pelicula y Serie en 
    arrPtrVideo*/

    /*Copiar los apuntadores del arreglo Serie al arreglo 
    de apuntadores de Video calculando su Calificacion Promedio
    ya que tiene todos los episodios*/
    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio(); //Calcula la calificacion de la Serie
        arrPtrSeries[index] -> setCalificacion(promedio); // Cambia la calificacion de la Serie
        //añade el calcular la duracion de la serie
        arrPtrSeries[index] -> calculaDuracion();
        
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    
    }

    //copiar todos los apuntadores del arreglo de Peliculas al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /* Desplegar todo el contenido del arreglo de apuntadores de
    la clase Video (Base)
    Se da el POLIMORFISMO
    se ejecuta el metodo str que corresponde al tipo de apuntador almacenado
    no el correspondiente al tipo de arreglo*/

    //Comentar para el avance 2
    /*
    for(int index = 0; index < cantidad; index++){
        cout << index << " "<<arrPtrVideos[index] ->str() <<endl;
    }
    */
    entrada.close(); //cerrar el archivo
}