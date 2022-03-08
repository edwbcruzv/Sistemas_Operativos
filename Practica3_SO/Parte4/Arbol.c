#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<wait.h>
#include<sys/types.h>

/*
Programa sencillo que crea un proceso 
hijo a partir del padre con fork()
*/
int main(){
    int id_proceso2;
    id_proceso2=fork();

    if(id_proceso2==0){
        printf("\tHijo1:%d\n",getpid());
        printf("\tMi proceso padre es: %d\n",getppid());
        //exit(0);

        int id_proceso3;
        id_proceso3=fork();

        if(id_proceso3==0){
            printf("\t\tHijo2:%d\n",getpid());
            printf("\t\tMi proceso padre es: %d\n",getppid());
            //exit(0);
            int id_proceso4;
            id_proceso4=fork();

            if(id_proceso4==0){
                printf("\t\t\tHijo3:%d\n",getpid());
                printf("\t\t\tMi proceso padre es: %d\n",getppid());
                //exit(0);
                int id_proceso5;
                id_proceso5=fork();

                if(id_proceso5==0){
                    printf("\t\t\t\tHijo4:%d\n",getpid());
                    printf("\t\t\t\tMi proceso padre es: %d\n",getppid());
                    //exit(0);
                }
            }

        }


        }

    else{
        
        printf("Proceso Principal: %d\n",getpid());
        printf("Mi proceso padre es: %d\n",getppid());
        //exit(0);
        }
    wait(NULL);  //Evita que el proceso padre se detenga rapido, si se pone dentro del else no srive
}