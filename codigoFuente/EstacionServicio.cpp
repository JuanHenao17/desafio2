#include "EstacionServicio.h"
#include <random>
#include <iostream>

using namespace std;
unsigned short EstacionServicio::count=0;

EstacionServicio::EstacionServicio(const string& nombreEst, const string& gerenteEst, const string& ubicacionEst, const string& coordsEst, double _precioR, double _precioP,  double _precioE)
    : nombre(nombreEst), gerente(gerenteEst), ubicacion(ubicacionEst), coords(coordsEst), capacidad(2), numSurtidores(0) {

    surtidores = new Surtidor[capacidad];

    count++;
    ID = count;

    random_device rd;  // Inicializador con una semilla aleatoria
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<unsigned short> distribucion(100, 200); // Rango de 100 a 200

    tanqueRegular = distribucion(gen); // Litros
    tanquePremium = distribucion(gen); // Litros
    tanqueEcoExtra = distribucion(gen); // Litros

    if(ubicacionEst == "Norte" || ubicacionEst == "norte"){
        precioRegular = _precioR * 1.05;
        precioPremium = _precioP * 1.05;
        precioEcoExtra = _precioE * 1.05;
    }

    else if(ubicacionEst == "Centro" || ubicacionEst == "centro"){
        precioRegular = _precioR;
        precioPremium = _precioP;
        precioEcoExtra = _precioE;
    }

    else if(ubicacionEst == "Sur" || ubicacionEst == "sur"){

        precioRegular = _precioR * 0.97;
        precioPremium = _precioP * 0.97;
        precioEcoExtra = _precioE * 0.97;
    }

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

    precioRegular = 0;
    precioPremium = 0;
    precioEcoExtra = 0;
}

EstacionServicio::~EstacionServicio() {

    delete[] surtidores;

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

unsigned short EstacionServicio::getTanqueRegular(){
    return tanqueRegular;
}

unsigned short EstacionServicio::getTanquePremium(){
    return tanquePremium;
}

unsigned short EstacionServicio::getTanqueEcoExtra(){
    return tanqueEcoExtra;
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
    this->precioRegular = estacionA.precioRegular;
    this->precioPremium = estacionA.precioPremium;
    this->precioEcoExtra = estacionA.precioEcoExtra;

    return *this;
}

void EstacionServicio::crearSurt(){

    if (numSurtidores == 12){
        cout << "Se han creado el maximo de surtidores, no pueden anadir mas." << endl;
        return;
    }

    else if(numSurtidores >= capacidad){
        expandir();
    }

    surtidores[numSurtidores] = Surtidor(tanqueRegular, tanquePremium, tanqueEcoExtra, precioRegular, precioPremium, precioEcoExtra);
    numSurtidores++;
    cout << "Surtidor creado correctamente!" << endl;
}

void EstacionServicio::expandir() {

    capacidad++;
    Surtidor* nuevoArreglo = new Surtidor[capacidad];

    // Copia las estaciones existentes al nuevo arreglo
    for (int i = 0; i < numSurtidores; i++) {
        nuevoArreglo[i] = surtidores[i];
    }

    delete[] surtidores; // Libera la memoria del arreglo viejo
    surtidores = nuevoArreglo; // Actualiza el puntero al nuevo arreglo
}

void EstacionServicio::eliminarSurtidor(unsigned short idSurtidor) {

    bool encontrado = false;
    for (unsigned short i = 0; i < numSurtidores; i++) {
        if (surtidores[i].getIDS() == idSurtidor) {
            encontrado = true;

            for (unsigned short j = i; j < numSurtidores - 1; j++) {
                surtidores[j] = surtidores[j + 1];
            }
            numSurtidores--;
            cout << "Surtidor eliminado correctamente." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro el surtidor con el ID proporcionado." << endl;
    }
}

void EstacionServicio::mostrarSurtidores() {

    if (numSurtidores == 0) {
        cout << "No hay surtidores en esta estación." << endl;
    } else {
        for (unsigned short i = 0; i < numSurtidores; i++) {
            cout << "Surtidor ID: " << surtidores[i].getIDS() << endl;
        }
    }
}

void EstacionServicio::activarSurtidor(unsigned short idSurtidor) {
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i].getIDS() == idSurtidor) {

            if (surtidores[i].getActivo() == true){
                cout << "Surtidor " << idSurtidor << " ya se encuentra activo" << endl;
                return;
            }
            else{
                surtidores[i].activar();
                cout << "Surtidor " << idSurtidor << " activado." << endl;
                return;
            }
        }
    }
    cout << "Surtidor con ID " << idSurtidor << " no encontrado." << endl;
}

void EstacionServicio::desactivarSurtidor(unsigned short idSurtidor) {
    for (int i = 0; i < numSurtidores; ++i) {
        if (surtidores[i].getIDS() == idSurtidor) {

            if (surtidores[i].getActivo() == false){
                cout << "Surtidor " << idSurtidor << " ya se encuentra desactivado" << endl;
                return;
            }

            else{
                surtidores[i].desactivar();
                cout << "Surtidor " << idSurtidor << " desactivado." << endl;
                return;
            }
        }
    }
    cout << "Surtidor con ID " << idSurtidor << " no encontrado." << endl;
}

Surtidor* EstacionServicio::selectSurtidor(){

    for (int i = 0; i < numSurtidores; ++i) {
        if(surtidores[i].getActivo() == true){
            return &surtidores[i];
        }
    }

    return nullptr; //Si no hay surtidores activo retorna null
}

void EstacionServicio::calcularMonto(){

    double montoR = 0;
    double montoP = 0;
    double montoE = 0;

    for (int i = 0; i < numSurtidores; ++i) {
        montoR += surtidores[i].getDineroR();
        montoP += surtidores[i].getDineroP();
        montoE += surtidores[i].getDineroE();
    }

    cout << "Monto combustible Regular: " << montoR << " pesos" << endl;
    cout << "Monto combustible Premium: " << montoP << " pesos" << endl;
    cout << "Monto combustible EcoExtra: " << montoE << " pesos" << endl;

}
