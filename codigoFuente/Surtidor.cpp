#include "Surtidor.h"

unsigned short Surtidor::contadorID = 0;

Surtidor::Surtidor(unsigned short capacidadReg, unsigned short capacidadPrem, unsigned short capacidadEco){

    activo = true;

    contadorID++;
    id = contadorID;

    Fecha = "";
    Hora = "";
    CategoriaCombustible = "";
    Metodo_Pago = "";
    Doc = "";
    Dinero = 0;

    CapacidadRegular = capacidadReg;
    CapacidadPremium = capacidadPrem;
    CapacidadEcoExtra = capacidadEco;

}

Surtidor::Surtidor(){

    activo = true;

    //contadorID++;
    id = contadorID;

    Fecha = "";
    Hora = "";
    CategoriaCombustible = "";
    Metodo_Pago = "";
    Doc = "";
    Dinero = 0;

    CapacidadRegular = 0;
    CapacidadPremium = 0;
    CapacidadEcoExtra = 0;

}

unsigned short Surtidor::getIDS(){
    return id;
};

bool Surtidor::getActivo(){
    return activo;
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
    this->Fecha = surtidorA.Fecha;
    this->Hora = surtidorA.Hora;
    this->CategoriaCombustible = surtidorA.CategoriaCombustible;
    this->Metodo_Pago = surtidorA.Metodo_Pago;
    this->Doc = surtidorA.Doc;
    this->Dinero = surtidorA.Dinero;
    this->CapacidadRegular = surtidorA.CapacidadRegular;
    this->CapacidadPremium = surtidorA.CapacidadPremium;
    this->CapacidadEcoExtra = surtidorA.CapacidadEcoExtra;

    return *this;
}
