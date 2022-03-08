#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void* HiloX15(void* arg);
void* HiloX10(void* arg);
void* HiloX5(void* arg);
void* Hilo_Final(void* arg);


int main(){

    pthread_t hilo_padre;
    printf("Proceso padre: %d",gettid());
    pthread_create(&hilo_padre,NULL,HiloX15,NULL);

    pthread_join(hilo_padre, NULL);
    
    return 0;
}

void* HiloX15(void* arg){

    printf("\tHilo padre: %d, genera 15 hilos mas\n\n",getpid());
    
    pthread_t arreglo[15];

    for (int i = 0; i < 15; i++)
    {
        pthread_create(&arreglo[i],NULL,HiloX10,(void*)i);

        pthread_join(arreglo[i], NULL);
    }
}

void* HiloX10(void* arg){
    int n=(int*)arg;
    printf("\t\tHilo %d, id: %d, genera 10 hilos mas\n\n",n+1,gettid());

    pthread_t arreglo[10];

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&arreglo[i],NULL,HiloX5,(void*)i);

        pthread_join(arreglo[i], NULL);
    }
}


void* HiloX5(void* arg){

    int n=(int*)arg;
    printf("\t\t\tHilo %d, id: %d, genera 5 hilos mas\n\n",n+1,gettid());

    pthread_t arreglo[5];

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&arreglo[i],NULL,Hilo_Final,NULL);

        pthread_join(arreglo[i], NULL);
    }

}

void* Hilo_Final(void* arg){

    printf("\t\t\t\tPractica4\n");

}