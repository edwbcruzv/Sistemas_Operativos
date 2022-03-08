#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define VALOR 1

/* Pipe
        -mecanimso IPc unidireccional
        -comunican procesos "relacionados"
        -envio de "byte streams"
        -pipe asociado a dos fd (descriptores de archivos)
*/


int main(void){

    //creando los 2 fd's: desc_arch[0]=lectura, desc_arch[1]=escritura
    int desc_arch[2];
    char bufer[100]; //es el espacio que compartiran los dos procesos

    if (pipe(desc_arch) != 0){
        //por si no se llega a crear correctamente el pipe
        exit(1);
    }

    if (fork() == 0){
        //reando un proceso hijo
        //este va a leer e imprimir lo que escriba el padre 
        while (VALOR){

            //funcion para leer
            read(desc_arch[0], bufer, sizeof(bufer));

            printf("Se recibió: %s \n", bufer);
        }
    }

    //codigo del proceso padre
    //este va a escribir y el hijo lo leera
    while (VALOR){
        //el proceso padre nos pide escribir una palabra
        gets(bufer);

        //funcion para escribir
        write(desc_arch[1], bufer, strlen(bufer) + 1);
    }
}