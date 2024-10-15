#include "EstacionServicio.h"
#include <random>
#include <iostream>

using namespace std;
unsigned short EstacionServicio::count=0;

EstacionServicio::EstacionServicio(const string& nombreEst, const string& gerenteEst, const string& ubicacionEst, const string& coordsEst)
    : nombre(nombreEst), gerente(gerenteEst), ubicacion(ubicacionEst), coords(coordsEst) {

    count++;
    ID = count;

    random_device rd;  // Inicializador con una semilla aleatoria
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<unsigned short> distribucion(100, 200); // Rango de 100 a 200

    tanqueRegular = distribucion(gen); // Litros
    tanquePremium = distribucion(gen); // Litros
    tanqueEcoExtra = distribucion(gen); // Litros

}

EstacionServicio::EstacionServicio(){

    nombre = "";
    gerente = "";
    ubicacion = "";
    coords = "";
    ID = 0;

    tanqueRegular = 0;
    tanquePremium = 0;
    tanqueEcoExtra = 0;

}

EstacionServicio::~EstacionServicio() {

}

string EstacionServicio::getNombre(){
    return nombre;
}

string EstacionServicio::getGerente(){
    return gerente;
}

string EstacionServicio::getubicacion(){
    return ubicacion;
}

string EstacionServicio::getcoords(){
    return coords;
}

unsigned short EstacionServicio::getID(){
    return ID;
}

void EstacionServicio::setRegular(int nuevoR){

    if(nuevoR > 200 || nuevoR < 100){
        cout << "Capacidad de combustible fuera de rango, se conservara el valor original del tanque" << endl;
        return;
    }

    else{
        tanqueRegular = nuevoR;
        cout << "Capacidad actualizada correctamente" << endl;
    }

}

void EstacionServicio::setPremium(int nuevoP){

    if(nuevoP > 200 || nuevoP < 100){
        cout << "Capacidad de combustible fuera de rango, se conservara el valor original del tanque" << endl;
        return;
    }

    else{
        tanquePremium = nuevoP;
        cout << "Capacidad actualizada correctamente" << endl;
    }

}

void EstacionServicio::setEcoExtra(int nuevoE){

    if(nuevoE > 200 || nuevoE < 100){
        cout << "Capacidad de combustible fuera de rango, se conservara el valor original del tanque" << endl;
        return;
    }

    else{
        tanqueEcoExtra = nuevoE;
        cout << "Capacidad actualizada correctamente" << endl;
    }

}

EstacionServicio& EstacionServicio::operator=(const EstacionServicio& estacionA){ //Sobrecarga del operador =

    this->nombre = estacionA.nombre;
    this->gerente = estacionA.gerente;
    this->ubicacion = estacionA.ubicacion;
    this->coords = estacionA.coords;
    this->ID = estacionA.ID;
    this->tanqueRegular = estacionA.tanqueRegular;
    this->tanquePremium = estacionA.tanquePremium;
    this->tanqueEcoExtra = estacionA.tanqueEcoExtra;

    return *this;
}
