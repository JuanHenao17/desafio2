#include "Surtidor.h"
#include <iostream>

unsigned short Surtidor::contadorID = 0;

Surtidor::Surtidor(unsigned short capacidadReg, unsigned short capacidadPrem, unsigned short capacidadEco, double precioR, double precioP, double precioE)
    : CapacidadRegular(capacidadReg), CapacidadPremium(capacidadPrem), CapacidadEcoExtra(capacidadEco), precioRegular(precioR), precioPremium(precioP), precioEcoExtra(precioE){

    activo = true;

    contadorID++;
    id = contadorID;

    dineroRegular = 0;
    dineroPremium = 0;
    dineroEcoExtra = 0;

}

Surtidor::Surtidor(){

    activo = true;

    id = contadorID;
    dineroRegular = 0;
    dineroPremium = 0;
    dineroEcoExtra = 0;

    CapacidadRegular = 0;
    CapacidadPremium = 0;
    CapacidadEcoExtra = 0;

    precioRegular = 0;
    precioPremium = 0;
    precioEcoExtra = 0;

}

unsigned short Surtidor::getIDS(){
    return id;
};

bool Surtidor::getActivo(){
    return activo;
}

double Surtidor::getDineroR(){
    return dineroRegular;
}

double Surtidor::getDineroP(){
    return dineroPremium;
}

double Surtidor::getDineroE(){
    return dineroEcoExtra;
}

void Surtidor::activar() {
    activo = true;
}

void Surtidor::desactivar() {
    activo = false;
}

Surtidor& Surtidor::operator=(const Surtidor& surtidorA){ //Sobrecarga del operador =

    this->activo = surtidorA.activo;
    this->id = surtidorA.id;
    this->dineroRegular = surtidorA.dineroRegular;
    this->dineroPremium = surtidorA.dineroPremium;
    this->dineroEcoExtra = surtidorA.dineroEcoExtra;
    this->CapacidadRegular = surtidorA.CapacidadRegular;
    this->CapacidadPremium = surtidorA.CapacidadPremium;
    this->CapacidadEcoExtra = surtidorA.CapacidadEcoExtra;
    this->precioRegular = surtidorA.precioRegular;
    this->precioPremium = surtidorA.precioPremium;
    this->precioEcoExtra = surtidorA.precioEcoExtra;

    return *this;
}

void Surtidor::simularVenta() {
    double precio = 0;
    double cantidadLitros;
    string tipoCombustible;


    cout << endl;
    cout << "Bienvenido! Que tipo de gasolina desea?(Regular, Premium, EcoExtra)" << endl;
    cin >> tipoCombustible;

    cout << "Cuanta gasolina desea?" << endl;
    cin >> cantidadLitros;

    if (tipoCombustible == "Regular" && cantidadLitros <= CapacidadRegular) {
        precio = cantidadLitros * precioRegular;  // precioRegular es un valor global o de RedNacional
        CapacidadRegular -= cantidadLitros;       // Actualiza la capacidad restante
        dineroRegular += precio;

    } else if (tipoCombustible == "Premium" && cantidadLitros <= CapacidadPremium) {
        precio = cantidadLitros * precioPremium;
        CapacidadPremium -= cantidadLitros;
        dineroPremium += precio;

    } else if (tipoCombustible == "EcoExtra" && cantidadLitros <= CapacidadEcoExtra) {
        precio = cantidadLitros * precioEcoExtra;
        CapacidadEcoExtra -= cantidadLitros;
        dineroEcoExtra += precio;

    } else {
        cout << "Cantidad de litros solicitada excede la capacidad disponible o tipo de combustible no valido." << endl;
        return;
    }


    cout << endl << "----------Transaccion Realizada----------" << endl;
    cout << "Se han bombeado " << cantidadLitros << " litros."<<endl;
    cout << "Valor: " << precio << " pesos." <<endl;

}

