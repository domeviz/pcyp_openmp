#include <iostream>

#include <fmt/core.h>

//Libreria para openMP
#include <omp.h>
//Mide tiempo
#include <chrono>
#include <filesystem>

//# significa preprocesador
#define MAX_ITER 100
namespace ch=std::chrono;
namespace fs=std::filesystem;
int main() {
//    HILO MASTER
    fmt::println("Ejemplo OpenMP-02");

    auto start=ch::high_resolution_clock::now();
    #pragma omp parallel default(none)
    {
        int thread_id=omp_get_thread_num();
//        for paralelo
        #pragma omp for
        for(int i=0;i<MAX_ITER;i++){
            fmt::println("thread_id={:1} for index={:2}",thread_id,i);
        }
    }
    auto end=ch::high_resolution_clock::now();
    ch::duration<double, std::milli> tiempo=end-start;

    fmt::println("Tiempo de proceso: {}",tiempo.count());
    return 0;


}
