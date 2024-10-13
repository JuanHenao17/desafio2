#include <iostream>
#include "RedNacional.h"
#include "EstacionServicio.h"

using namespace std;

void mostrarMenu() {

    cout << "=== Menu Principal ===" << endl;
    cout << "1. Agregar estacion de servicio" << endl;
    cout << "2. Eliminar estacion de servicio" << endl;
    cout << "3. Calcular monto total de ventas" << endl;
    cout << "4. Fijar precios de combustible" << endl;
    cout << "5. Gestionar surtidores de una E/S" << endl;
    cout << "6. Consultar historico de transacciones" << endl;
    cout << "7. Simular venta de combustible" << endl;
    cout << "8. Verificar fugas de combustible" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opcion: ";

}

int main()
{
    unsigned short opcion;
    RedNacional redTerMax;

    do {

        cout << endl;
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            redTerMax.crearES();
            break;

        case 2:
            // Llamar a la función para eliminar una estación de servicio
            break;
        case 3:
            // Calcular y mostrar el monto total de ventas
            break;

        case 4:

            redTerMax.fijarPrecios();

            break;

        case 5:
            // Submenú para gestionar surtidores
            break;
        case 6:
            // Consultar histórico de transacciones
            break;
        case 7:
            // Simular venta de combustible
            break;
        case 8:
            // Verificar fugas de combustible
            break;
        case 9:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << endl << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 9);

    return 0;
}
