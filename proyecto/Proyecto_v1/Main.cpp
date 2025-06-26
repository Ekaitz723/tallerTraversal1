#include "EKF_GEOS3.h"
#include <chrono>
#include <iostream>

int main()
{
    auto inicio = std::chrono::high_resolution_clock::now();
    EKFResults *results = EKF_GEOS3();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin-inicio);
    std::cout << "Tiempo (microsegundos): " << duracion.count() << "us\n";

    // if (results == nullptr) {
    //     printf("Error: EKF_GEOS3 devuelve null.\n");
    //     return 1;
    // }
    // printf("Estado final estimado en t0:\n");
    // if (results->Y0 != nullptr) {
    //     results->Y0->print();
    // } else {
    //     printf("Y0 is null.\n");
    // }
    // printf("Matriz de covarianza final P:\n");
    // if (results->P != nullptr) {
    //     results->P->print();
    // } else {
    //     printf("P es null.\n");
    // }
    // printf("Errores de posicion: [%f, %f, %f]\n", results->position_error[0], results->position_error[1], results->position_error[2]);
    // printf("Velocity errors: [%f, %f, %f]\n", results->velocity_error[0], results->velocity_error[1], results->velocity_error[2]);

    return 0;
}

//  make clean; make Main; ./Main 