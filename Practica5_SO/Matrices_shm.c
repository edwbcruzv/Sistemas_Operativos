#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<wait.h>
#include<sys/types.h>
#include<time.h>
#include"oper_matriz.h"

int main(){
    
    int id_proceso2;
    id_proceso2=fork();

    Matriz M1=NuevaMatriz(10,10);
    Matriz M2=NuevaMatriz(10,10);
    Randoms(M1,0,9);
    Randoms(M2,10,20);

    printf("\n\nMatriz1:\n");
    Imp_Mat(M1);

    printf("\n\nMatriz2:\n");
    Imp_Mat(M2);

    //seccion de pipes
    int tubo_1a2[2]; //enviar 
    int tubo_2a1[2]; //regreso

    Matriz buffer[]={M1,M2};
    Matriz retorno1[2];

    if (pipe(tubo_1a2) == -1){
        //por si no se llega a crear correctamente el pipe de enviar
        exit(1);
    }
    if (pipe(tubo_2a1) == -1){
        //por si no se llega a crear correctamente el pipe de regreso
        exit(1);
    }
    write(tubo_1a2[1], buffer,sizeof(buffer));
    //fin de pipes

    //proceso1=padre

    if(id_proceso2==0){
        //printf("\tHijo1:%d\n",getpid());
        
        //printf("\tMi proceso padre es: %d\n",getppid());
        //proceso2=hijo
        read(tubo_1a2[0], buffer, sizeof(buffer));
        Matriz m1=(Matriz)buffer[0];
        Matriz m2=(Matriz)buffer[1];

        Matriz res1=Mult(m1,m2);
        //Imp_Mat(res_resta);
        //seccion de pipes
        int tubo_2a3[2]; //envio
        int tubo_3a2[2]; //regreso
        Matriz buffer2[]={m1,m2};
        Matriz retorno2;

        if (pipe(tubo_2a3) == -1){
            //por si no se llega a crear correctamente el pipe de envio
            exit(1);
        }
        if (pipe(tubo_3a2) == -1){
            //por si no se llega a crear correctamente el pipe de regreso
            exit(1);
        }
        write(tubo_2a3[1], buffer2,sizeof(buffer2));
        //fin de pipes

        int id_proceso3;
        id_proceso3=fork();

        if(id_proceso3==0){
            
            //printf("\t\tHijo2:%d\n",getpid());
            
            //printf("\t\tMi proceso padre es: %d\n",getppid());
            //proceso3=nieto
            
            read(tubo_2a3[0], buffer2, sizeof(buffer2));
            
            Matriz n1=(Matriz)buffer2[0];
            Matriz n2=(Matriz)buffer2[1];    

            Matriz res2=Suma(n1,n2);

            //Imp_Mat(res_mult);
            retorno2=res2;

            write(tubo_3a2[1], retorno2,sizeof(retorno2));

        }

        wait(NULL);
        //Imp_Mat(retorno2);
        retorno1[0]=retorno2;
        retorno1[1]=res1;
        write(tubo_2a1[1], retorno1,sizeof(retorno1));

        }

    //esperando al hijo
    printf("Suma de matrices:\n");
    Imp_Mat(retorno1[0]);
    printf("Multiplicacion de matrices:\n");
    Imp_Mat(retorno1[1]);
    
    wait(NULL);  //Evita que el proceso padre se detenga rapido, si se pone dentro del else no srive

    
}