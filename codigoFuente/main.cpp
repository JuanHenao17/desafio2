#include <iostream>
#include "RedNacional.h"
#include "EstacionServicio.h"

using namespace std;

void mostrarMenu() {

    cout << "=== Menu Principal ===" << endl;
    cout << "1. Agregar estacion de servicio" << endl;
    cout << "2. Eliminar estacion de servicio" << endl;
    cout << "3. Calcular monto total por combustible de ventas de una E/S" << endl;
    cout << "4. Fijar precios de combustible" << endl;
    cout << "5. Gestionar surtidores de una E/S" << endl;
    cout << "6. Consultar historico de transacciones" << endl;
    cout << "7. Simular venta de combustible" << endl;
    cout << "8. Verificar fugas de combustible" << endl;
    cout << "9. Asignar capacidades del tanque de suministro" << endl;
    cout << "10. Salir" << endl;
    cout << "Seleccione una opcion: ";

}

void mostrarSubMenu() {

    cout << endl << "=== SubMenu Gestion Surtidores ===" << endl;
    cout << "1. Agregar surtidor a una E/S" << endl;
    cout << "2. Eliminar surtidor a una E/S" << endl;
    cout << "3. Activar surtidor a una E/S" << endl;
    cout << "4. Desactivar surtidor a una E/S" << endl;
    cout << "Seleccione una opcion: ";

}

int main()
{
    unsigned short idSurt;
    unsigned short idES;
    unsigned short opcion2;
    unsigned short opcion;
    RedNacional redTerMax;
    EstacionServicio* estacion;
    Surtidor* surtidor;

    do {

        cout << endl;
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:

            cout << endl;
            redTerMax.crearES();
            redTerMax.mostrarEstaciones();

            break;

        case 2:

            cout << endl;
            redTerMax.eliminarES();
            redTerMax.mostrarEstaciones();

            break;

        case 3:

            cout << endl;
            cout << "Ingrese el ID de la estacion de servicio: ";
            cin >> idES;
            estacion = redTerMax.obtenerEstacionPorID(idES);

            if(estacion != nullptr){
                estacion -> calcularMonto();
            }
            else{
                cout << "Estacion de servicio no encontrada." << endl;
            }

            break;

        case 4:

            cout << endl;
            redTerMax.fijarPrecios();

            break;

        case 5:

            cout << endl;
            cout << "Ingrese el ID de la estacion de servicio: ";
            cin >> idES;
            estacion = redTerMax.obtenerEstacionPorID(idES);

            if(estacion != nullptr){

                mostrarSubMenu();
                cin >> opcion2;

                switch(opcion2){
                case 1:
                    cout << endl;
                    estacion -> crearSurt();
                    estacion -> mostrarSurtidores();
                    break;

                case 2:
                    cout << endl;
                    cout << "Ingrese el ID del surtidor a eliminar: ";
                    cin >> idSurt;
                    estacion -> eliminarSurtidor(idSurt);
                    estacion -> mostrarSurtidores();

                    break;

                case 3:
                    cout << endl;
                    cout << "Ingrese el ID del surtidor que quiere activar: ";
                    cin >> idSurt;
                    estacion -> activarSurtidor(idSurt);

                    break;

                case 4:
                    cout << endl;
                    cout << "Ingrese el ID del surtidor que quiere desactivar: ";
                    cin >> idSurt;
                    estacion -> desactivarSurtidor(idSurt);

                    break;

                default:
                    cout << endl;
                    cout << "Opcion no valida en el submenu." << endl;
                    break;
                }
            } else{
                cout << endl;
                cout << "Estacion de servicio no encontrada." << endl;
            }

            break;

        case 6:
            cout << endl;
            cout << "No se logró :(" << endl;
            break;

        case 7:
            cout << endl;
            cout << "Ingrese el ID de la estacion de servicio: ";
            cin >> idES;
            estacion = redTerMax.obtenerEstacionPorID(idES);

            if (estacion != nullptr){
                surtidor = estacion->selectSurtidor();

                if(surtidor == nullptr){
                    cout << endl;
                    cout << "No hay surtidores activos en esta estacion" << endl;
                    break;
                }
                else{
                    surtidor -> simularVenta();
                }
            }
            else{
                cout << endl;
                cout << "Estacion de servicio no encontrada." << endl;
            }

            break;

        case 8:
            cout << endl;
            cout << "No se logró :(" << endl;

            break;

        case 9:
            cout << endl;
            redTerMax.FijarCapacidadTanques();

            break;

        case 10:
            cout << endl;
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << endl;
            cout << endl << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 10);

    return 0;
}
