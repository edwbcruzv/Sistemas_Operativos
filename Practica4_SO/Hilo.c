#include <stdio.h>
#include <pthread.h>
//

void *hilo(void *arg);

int main(){

    pthread_t id_hilo;
    

    int hilo_creado=pthread_create(&id_hilo, NULL,hilo,NULL);

    pthread_join(id_hilo, NULL);
    return 0;
}
void *hilo(void *arg){

    printf("Hola mundo desde un hilo en UNIX\n");

    return NULL;
}