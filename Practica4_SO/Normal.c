#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"oper_matriz.h"

//Se realiza el calculo matematico de dos matrices en un flujo comun
//en una funcion principal


int main(){

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
    
    //proceso2
    Matriz res_resta=Resta(M1,M2);
    
    //proceso3
    Matriz res_mult=Mult(M1,M2);
    
    //proceso4
    Matriz T_M1=Traspuesta(M1);
    Matriz T_M2=Traspuesta(M2);

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

    printf("\nTiempo de ejecucion:%g segundos",segundos);
    printf("\nTiempo de ejecucion:%.16g milisegundos\n",segundos*1000);


    return 0;

}

