#include <stdio.h> /* Programa creador de un nuevo proceso */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){

    pid_t pid;
    char *argv[3];
    argv[0]="/hola"; /*cambiar por ruta propia*/
    argv[1]="Desde el Hijo";
    argv[2]=NULL;

    if((pid=fork())==-1){
        printf("Error al crear el proceso hijo\n");
        }

    if(pid==0){
        printf("Soy el hijo ejecutando: %s\n", argv[0]);
        execv(argv[0],argv);
        }

    else{
        wait(0);
        printf("Soy el Padre\n");
        exit(0);
        }
}