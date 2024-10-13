#include <iostream>
#include "RedNacional.h"
#include "EstacionServicio.h"

using namespace std;

RedNacional::RedNacional(){

    precioRegular = 3170.0;
    precioPremium = 3700.0;
    precioEcoExtra = 3430.0;
}

void RedNacional::setPrecioRegular(double precio){
    precioRegular = precio; }

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
    cin >> nuevoprecioR;
    setPrecioPremium(nuevoprecioP);

    cout << endl << "Introduzca el nuevo precio del combustible EcoExtra: " << endl;
    cin >> nuevoprecioR;
    setPrecioEcoExtra(nuevoprecioP);

    cout << endl << "Precios fijados correctamente! ";

}

void RedNacional::crearES(){

    string _nombre;
    string _gerente;
    string _ubicacion;
    string _coords;

    cout << "Introduzca el nombre de la nueva estacion de servicio: " << endl;
    cin >> _nombre;

    cout << "Introduzca el nombre del gerente: " << endl;
    cin >> _gerente;

    cout << "Introduzca la region a la que pertenece la estacion " << endl;
    cin >> _ubicacion;

    cout << "Introduzca las coordenadas: " << endl;
    cin >> _coords;

    EstacionServicio est(_nombre, _gerente, _ubicacion, _coords);

}
