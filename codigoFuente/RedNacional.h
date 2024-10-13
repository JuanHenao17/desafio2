#ifndef REDNACIONAL_H
#define REDNACIONAL_H

class RedNacional{
private:

    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

public:

    RedNacional();

    void setPrecioRegular(double precio);
    void setPrecioPremium(double precio);
    void setPrecioEcoExtra(double precio);

    double getPrecioRegular();
    double getPrecioPremium();
    double getPrecioEcoExtra();

    void fijarPrecios();
    void crearES();

};

#endif // REDNACIONAL_H
