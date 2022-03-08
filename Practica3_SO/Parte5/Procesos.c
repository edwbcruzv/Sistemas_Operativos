#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<wait.h>
#include<sys/types.h>
#include<time.h>
#include"oper_matriz.h"

//se realizan las mismas ejecuciones de Normal.c pero en cada proceso
//se realiza una operacion y so comparan tiempos 

int main(){
    int id_proceso2;
    id_proceso2=fork();

    Matriz M1=NuevaMatriz(7,7);
    Matriz M2=NuevaMatriz(7,7);
    Randoms(M1,0,9);
    Randoms(M2,10,20);
    //Unos(M1);
    //Unos(M2);
    
    printf("\n\nMatriz1:\n");
    Imp_Mat(M1);

    printf("\n\nMatriz2:\n");
    Imp_Mat(M2);
    //inicio de tiempo
    clock_t inicio, final;
    inicio=clock();
    //proceso1
    Matriz res_suma=Suma(M1,M2);


    if(id_proceso2==0){
        printf("\tHijo1:%d\n",getpid());
        printf("\tMi proceso padre es: %d\n",getppid());
        //proceso2
        Matriz res_resta=Resta(M1,M2);
        //exit(0);

        int id_proceso3;
        id_proceso3=fork();

        if(id_proceso3==0){
            printf("\t\tHijo2:%d\n",getpid());
            printf("\t\tMi proceso padre es: %d\n",getppid());
            //proceso3
            Matriz res_mult=Mult(M1,M2);
            //exit(0);
            int id_proceso4;
            id_proceso4=fork();

            if(id_proceso4==0){
                printf("\t\t\tHijo3:%d\n",getpid());
                printf("\t\t\tMi proceso padre es: %d\n",getppid());
                //proceso4
                Matriz T_M1=Traspuesta(M1);
                Matriz T_M2=Traspuesta(M2);
                //exit(0);
                int id_proceso5;
                id_proceso5=fork();

                if(id_proceso5==0){
                    printf("\t\t\t\tHijo4:%d\n",getpid());
                    printf("\t\t\t\tMi proceso padre es: %d\n",getppid());
                    //proceso5
                    printf("\n\nSuma:\n");
                    Imp_Mat(res_suma);

                    printf("\n\nResta:\n");
                    Imp_Mat(res_resta);

                    printf("\n\nMultiplicacion\n");
                    Imp_Mat(res_mult);

                    printf("\n\nTranspuesta de Matriz1:\n");
                    Imp_Mat(T_M1);
                    printf("\n\nTranspuesta de Matriz2:\n");
                    Imp_Mat(T_M2);
                    //fin de conteo de tiempo
                    final=clock();

                    double segundos=(double)(final-inicio)/CLOCKS_PER_SEC;

                    printf("\nTiempo de ejecucion:%f segundos",segundos);
                    printf("\nTiempo de ejecucion:%.16g milisegundos\n",segundos*1000);
                    //exit(0);
                }
            }

        }


        }

    else{
        
        printf("Proceso Principal: %d\n",getpid());
        printf("Mi proceso padre es: %d\n",getppid());
        //inicializacion de las matrices


        //exit(0);
        }
    wait(NULL);  //Evita que el proceso padre se detenga rapido, si se pone dentro del else no srive
}