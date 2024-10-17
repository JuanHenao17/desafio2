#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H
#include "Surtidor.h"
#include <string>

using namespace std;

class EstacionServicio{

private:

    string nombre;
    unsigned short ID;
    static unsigned short count;
    string gerente;
    string ubicacion;
    string coords;

    unsigned short tanqueRegular;
    unsigned short tanquePremium;
    unsigned short tanqueEcoExtra;
    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

    Surtidor *surtidores;
    unsigned short numSurtidores;
    unsigned short capacidad;

public:

    EstacionServicio(const string& nombreEst, const string& gerenteEst, const string& ubicacionEst, const string& coordsEst, double _precioR, double _precioP,  double _precioE);
    EstacionServicio();
    ~EstacionServicio();

    string getNombre();
    string getGerente();
    string getubicacion();
    string getcoords();
    unsigned short getID();
    unsigned short getTanqueRegular();
    unsigned short getTanquePremium();
    unsigned short getTanqueEcoExtra();

    void setRegular(int nuevoR);
    void setPremium(int nuevoP);
    void setEcoExtra(int nuevoE);

    void FijarCapacidadTanques();
    EstacionServicio& operator=(const EstacionServicio& estacion);
    void crearSurt();
    void expandir();
    void eliminarSurtidor(unsigned short idSurtidor);
    void mostrarSurtidores();
    void activarSurtidor(unsigned short idSurtidor);
    void desactivarSurtidor(unsigned short idSurtidor);
    Surtidor* selectSurtidor();
    void calcularMonto();

};


#endif // ESTACIONSERVICIO_H
