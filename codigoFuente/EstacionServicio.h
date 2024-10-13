#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H
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


public:

    EstacionServicio(const string& nombreEst, const string& gerenteEst, const string& ubicacionEst, const string& coordsEst);

};

unsigned short EstacionServicio::count=0;

#endif // ESTACIONSERVICIO_H
