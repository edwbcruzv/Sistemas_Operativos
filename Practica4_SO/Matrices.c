#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include<time.h>
#include <unistd.h>
#include"oper_matriz.h"


void* Hilo_Suma(void* arg[]);
void* Hilo_Resta(void* arg[]);
void* Hilo_Mult(void* arg[]);
void* Hilo_Trasp(void* arg);
void* Hilo_Resultados(void* arg[]);

int main(){

    Matriz M1=NuevaMatriz(7,7);
    Matriz M2=NuevaMatriz(7,7);
    Randoms(M1,0,9);
    Randoms(M2,10,20);
    

    //inicio de tiempo
    clock_t inicio, final;
    inicio=clock();

    Matriz arreglo[]={M1,M2};
    Matriz R_Suma,R_Resta,R_Mult,R_Trasp1,R_Trasp2;

    //Hilo de suma//
    pthread_t hilo_suma;
    pthread_create(&hilo_suma,NULL,Hilo_Suma,(void*)arreglo);

    //Hilo de resta//
    pthread_t hilo_resta;
    pthread_create(&hilo_resta,NULL,Hilo_Resta,(void*)arreglo);

    //Hilo de multiplicacion//
    pthread_t hilo_mult;
    pthread_create(&hilo_mult,NULL,Hilo_Mult,(void*)arreglo);

    //Hilo de traspuesta1//
    pthread_t hilo_trasp1;
    pthread_create(&hilo_trasp1,NULL,Hilo_Trasp,(void*)M1);

    //Hilo de traspuesta2//
    pthread_t hilo_trasp2;
    pthread_create(&hilo_trasp2,NULL,Hilo_Trasp,(void*)M2);
    
    pthread_join(hilo_suma,(void*)&R_Suma);
    pthread_join(hilo_resta,(void*)&R_Resta);
    pthread_join(hilo_mult,(void*)&R_Mult);
    pthread_join(hilo_trasp1,(void*)&R_Trasp1);
    pthread_join(hilo_trasp2,(void*)&R_Trasp2);
   
    //Hilo de resultados//
    Matriz res[]={M1,M2,R_Suma,R_Resta,R_Mult,R_Trasp1,R_Trasp2};
    pthread_t hilo_res;
    pthread_create(&hilo_res,NULL,Hilo_Resultados,(void*)res);
    pthread_join(hilo_res,NULL);

    //fin de conteo de tiempo
    final=clock();

    double segundos=(double)(final-inicio)/CLOCKS_PER_SEC;

    printf("\nTiempo de ejecucion:%g segundos",segundos);
    printf("\nTiempo de ejecucion:%.16g milisegundos\n",segundos*1000);

    return 0;

}

void* Hilo_Suma(void* arg[]){

    Matriz M1=(Matriz)arg[0];
    Matriz M2=(Matriz)arg[1];
    Matriz res=Suma(M1,M2);

    pthread_exit((void*)res);
    
}

void* Hilo_Resta(void* arg[]){

    Matriz M1=(Matriz)arg[0];
    Matriz M2=(Matriz)arg[1];
    Matriz res=Resta(M1,M2);

    pthread_exit((void*)res);
    
}

void* Hilo_Mult(void* arg[]){

    Matriz M1=(Matriz)arg[0];
    Matriz M2=(Matriz)arg[1];
    Matriz res=Mult(M1,M2);

    pthread_exit((void*)res);
    
}

void* Hilo_Trasp(void* arg){

    Matriz M=(Matriz)arg;
    Matriz res=Traspuesta(M);

    pthread_exit((void*)res);
    
}

void* Hilo_Resultados(void* arg[]){

    Matriz M1=(Matriz)arg[0];
    Matriz M2=(Matriz)arg[1];

    Matriz res_suma=(Matriz)arg[0];
    Matriz res_resta=(Matriz)arg[1];

    Matriz res_mult=(Matriz)arg[0];

    Matriz T_M1=(Matriz)arg[0];
    Matriz T_M2=(Matriz)arg[1];

    printf("\n\nMatriz1:\n");
    Imp_Mat(M1);

    printf("\n\nMatriz2:\n");
    Imp_Mat(M2);

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



}
