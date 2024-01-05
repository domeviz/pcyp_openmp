#include <iostream>
#include <omp.h>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <vector>
#include <cmath>

#define MAX_ELEMENTOS 1024;

int main(){
//    std::vector<float> datos(MAX_ELEMENTOS);

    std::vector<float> datos={0,1,2,3,4,5,6,7};

    int num_thread_inicial=std::ceil(datos.size()/2);

    std::vector<float> tmp;

    std::copy(datos.begin(),datos.end(),std::back_inserter(tmp));

    omp_set_num_threads(num_thread_inicial);

    fmt::println("Se estan utilizando {} hilos",omp_get_num_threads());

    int suma=0.0f;

#pragma omp parallel default(none) shared(suma,datos,tmp)
    {
        int num_hilos=omp_get_num_threads();
//        fmt::println("Se estan utilizando {} hilos",num_hilos);
        //Obtener id del hilo
        int thread_id=omp_get_thread_num();
        for(int s=num_hilos;s>1;s= std::ceil(s/2)){
            if(thread_id<s){
                if(datos.size()%2==0) {
//                    tmp[0]=tmp[0]+tmp[4]
//                    tmp[1]=tmp[1]+tmp[5]
//                    tmp[2]=tmp[2]+tmp[6]
//                    tmp[3]=tmp[3]+tmp[7]
                    tmp[thread_id] = tmp[thread_id] + tmp[thread_id + s];

                }else{
                    if(thread_id+s != (2*s)-1){
                        tmp[thread_id] = tmp[thread_id] + tmp[thread_id + s];
                    }
                }
            }
            //Barrera que detiene la paralelizacion
            #pragma omp barrier
        }
        if(thread_id==0){
            suma=tmp[0]+tmp[1];
        }
    }
    fmt::println("{}",suma);

return 0;
}