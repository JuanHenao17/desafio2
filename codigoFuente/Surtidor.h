#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <string>

using namespace std;

class Surtidor{

private:

    unsigned short id;
    static unsigned short contadorID;
    bool activo;
    string Fecha;
    string Hora;
    string CategoriaCombustible;
    string Metodo_Pago;
    string Doc;
    double Dinero;

    unsigned short CapacidadRegular;
    unsigned short CapacidadPremium;
    unsigned short CapacidadEcoExtra;
    bool verificarFuga();
public:

    Surtidor(unsigned short capacidadReg, unsigned short capacidadPrem, unsigned short capacidadEco);
    Surtidor();
    unsigned short getIDS();
    bool getActivo();
    void activar();
    void desactivar();
    Surtidor& operator=(const Surtidor& surtidorA);

};

#endif // SURTIDOR_H
