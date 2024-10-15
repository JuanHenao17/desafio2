#ifndef REDNACIONAL_H
#define REDNACIONAL_H

#include "EstacionServicio.h"

class RedNacional{
private:

    EstacionServicio* estaciones;
    unsigned short capacidad;
    unsigned short num_estaciones;

    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

public:

    RedNacional();
    ~RedNacional();

    void setPrecioRegular(double precio);
    void setPrecioPremium(double precio);
    void setPrecioEcoExtra(double precio);

    double getPrecioRegular();
    double getPrecioPremium();
    double getPrecioEcoExtra();

    void fijarPrecios();
    void crearES();
    void expandir();
    void eliminarES();
    void mostrarEstaciones();
    void FijarCapacidadTanques();

};

#endif // REDNACIONAL_H
