#include <iostream>
#include "RedNacional.h"
#include "EstacionServicio.h"
#include <limits>

using namespace std;

RedNacional::RedNacional() : capacidad(2), num_estaciones(0){

    estaciones = new EstacionServicio[capacidad];

    precioRegular = 3170.0;
    precioPremium = 3700.0;
    precioEcoExtra = 3430.0;
}

RedNacional::~RedNacional(){

    delete[] estaciones;

}

void RedNacional::setPrecioRegular(double precio){

    if (precio > 0){
        precioRegular = precio;
    }

    else{
        cout << endl << "El precio debe ser mayor a 0 " << endl;
    }
}

void RedNacional::setPrecioPremium(double precio){
    precioPremium = precio; }

void RedNacional::setPrecioEcoExtra(double precio){
    precioEcoExtra = precio; }

double RedNacional::getPrecioRegular(){
    return precioRegular; }

double RedNacional::getPrecioPremium(){
    return precioPremium; }

double RedNacional::getPrecioEcoExtra(){
    return precioEcoExtra; }

void RedNacional::fijarPrecios(){

    double nuevoprecioR;
    double nuevoprecioP;
    double nuevoprecioE;

    cout << endl << "Introduzca el nuevo precio del combustible Regular: " << endl;
    cin >> nuevoprecioR;
    setPrecioRegular(nuevoprecioR);

    cout << endl << "Introduzca el nuevo precio del combustible Premium: " << endl;
    cin >> nuevoprecioP;
    setPrecioPremium(nuevoprecioP);

    cout << endl << "Introduzca el nuevo precio del combustible EcoExtra: " << endl;
    cin >> nuevoprecioE;
    setPrecioEcoExtra(nuevoprecioP);

    cout << endl << "Precios fijados correctamente! ";

}

void RedNacional::crearES(){

    if(num_estaciones >= capacidad){
        expandir();
    }

    string _nombre;
    string _gerente;
    string _ubicacion;
    string _coords;

    cout << "Introduzca el nombre de la nueva estacion de servicio: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, _nombre);

    cout << "Introduzca el nombre del gerente: " << endl;
    getline(cin, _gerente);

    cout << "Introduzca la region a la que pertenece la estacion " << endl;
    getline(cin, _ubicacion);

    cout << "Introduzca las coordenadas: " << endl;
    getline(cin, _coords);

    EstacionServicio est(_nombre, _gerente, _ubicacion, _coords);

    estaciones[num_estaciones] = est;
    num_estaciones++;

    cout << endl << "Estacion creada correctamente!" << endl;

}

void RedNacional::expandir() {

    capacidad++;
    EstacionServicio* nuevoArreglo = new EstacionServicio[capacidad];

    // Copia las estaciones existentes al nuevo arreglo
    for (int i = 0; i < num_estaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }

    delete[] estaciones; // Libera la memoria del arreglo viejo
    estaciones = nuevoArreglo; // Actualiza el puntero al nuevo arreglo
}

void RedNacional::mostrarEstaciones() {
    for (int i = 0; i < num_estaciones; i++) {
        cout << "Estacion ID: " << estaciones[i].getID()
        << " - " << estaciones[i].getNombre() << endl;
    }
}

void RedNacional::eliminarES(){

    unsigned short codigo;
    cout << "Introduzca el codigo de la estacion a eliminar: ";
    cin >> codigo;

    int indice = -1;

    for (int i = 0; i < num_estaciones; i++) {
        if (estaciones[i].getID() == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "No se encontro ninguna estacion con el codigo proporcionado." << endl;
        return;
    }

    for (int i = indice; i < num_estaciones - 1; i++) {
        estaciones[i] = estaciones[i + 1];
    }

    num_estaciones--;
    cout << "Estacion eliminada correctamente." << endl;

}

void RedNacional::FijarCapacidadTanques(){

    unsigned short codigo;
    cout << "Introduzca el codigo de la estacion a la que quiere asignar la capacidad del tanque: ";
    cin >> codigo;

    int indice = -1;

    for (int i = 0; i < num_estaciones; i++) {
        if (estaciones[i].getID() == codigo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "No se encontro ninguna estacion con el codigo proporcionado." << endl;
        return;
    }

    int nuevaCapacidadR;
    int nuevaCapacidadP;
    int nuevaCapacidadE;

    cout << endl << "Introduzca la nueva capacidad del combustible Regular (valor entero entre 100 y 200 litros): " << endl;
    cin >> nuevaCapacidadR;
    estaciones[indice].setRegular(nuevaCapacidadR);

    cout << endl << "Introduzca la nueva capacidad del combustible Premium (valor entero entre 100 y 200 litros): " << endl;
    cin >> nuevaCapacidadP;
    estaciones[indice].setPremium(nuevaCapacidadP);

    cout << endl << "Introduzca la nueva capacidad del combustible EcoExtra (valor entero entre 100 y 200 litros): " << endl;
    cin >> nuevaCapacidadE;
    estaciones[indice].setEcoExtra(nuevaCapacidadE);

}

EstacionServicio* RedNacional::obtenerEstacionPorID(unsigned short id) {
    for (int i = 0; i < num_estaciones; ++i) {
        if (estaciones[i].getID() == id) {
            return &estaciones[i];
        }
    }
    return nullptr; // Si no se encuentra la estación, devuelve nullptr
}
