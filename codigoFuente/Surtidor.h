#ifndef SURTIDOR_H
#define SURTIDOR_H

using namespace std;

class Surtidor{

private:

    unsigned short id;
    static unsigned short contadorID;
    bool activo;

    double dineroRegular;
    double dineroPremium;
    double dineroEcoExtra;

    unsigned short CapacidadRegular;
    unsigned short CapacidadPremium;
    unsigned short CapacidadEcoExtra;

    double precioRegular;
    double precioPremium;
    double precioEcoExtra;

public:

    Surtidor(unsigned short capacidadReg, unsigned short capacidadPrem, unsigned short capacidadEco, double precioR, double precioP, double precioE);
    Surtidor();

    unsigned short getIDS();
    bool getActivo();
    double getDineroR();
    double getDineroP();
    double getDineroE();

    void activar();
    void desactivar();
    Surtidor& operator=(const Surtidor& surtidorA);
    void simularVenta();

};

#endif // SURTIDOR_H
