#include "EstacionServicio.h"
#include <random>
#include <iostream>

using namespace std;

EstacionServicio::EstacionServicio(const string& nombreEst, const string& gerenteEst, const string& ubicacionEst, const string& coordsEst)
    : nombre(nombreEst), gerente(gerenteEst), ubicacion(ubicacionEst), coords(coordsEst) {

    // Inicializar tanques con capacidad inicial (puedes ajustar los valores según las especificaciones)

    count++;
    ID = count;

    random_device rd;  // Inicializador con una semilla aleatoria
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<unsigned short> distribucion(100, 200); // Rango de 100 a 200

    tanqueRegular = distribucion(gen); // Litros
    tanquePremium = distribucion(gen); // Litros
    tanqueEcoExtra = distribucion(gen); // Litros

    cout << "Identificador " << ID << endl;
    cout << "Tanque regular " << tanqueRegular << "litros " << endl;
    cout << "Tanque premium " << tanquePremium << "litros " << endl;
    cout << "Tanque regular " << tanqueEcoExtra << "litros " << endl;

    // Vector de surtidores y histórico de transacciones se inicializan vacíos por defecto
}
