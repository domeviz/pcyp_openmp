#include <iostream>

#include <fmt/core.h>

//Libreria para openMP
#include <omp.h>

int main() {
//    HILO MASTER
    fmt::println("Ejemplo OpenMP");

    int thread_num;
//    SECCION PARALELA QUE NOHACE NADA
#pragma omp parallel master default(none) shared(thread_num)
    {
//        fmt::println("Ejemplo con MASTER");
        thread_num=omp_get_num_threads();
        fmt::println(" {} threads",thread_num);
        fmt::println("");
    }
    //    Abrir 1 seccion paralela
//    seccion paralela:
//#hilos=#cores (por defecto)
//SECCION PARALELA QUE IMPRIME LOS HILOS
#pragma omp parallel default(none) shared(thread_num)
    {
//        fmt::println("Ejemplo sin MASTER");
//        Obtiene el ID del hilo actual

        int thread_id=omp_get_thread_num();
//Saca el id de los hilos
        fmt::println(" [{:1}/{:1}] Seccion paralela",thread_id,thread_num);

//Saca el numero de hilos
//        int thread_num=omp_get_num_threads();
//        fmt::println(" {} threads",thread_num);
//        fmt::println("");
//        k=5;
    }
    return 0;


}