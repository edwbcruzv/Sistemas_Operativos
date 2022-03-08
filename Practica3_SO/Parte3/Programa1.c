#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
Programa sencillo que crea un proceso 
hijo a partir del padre con fork()
*/
int main(){
    int id_proceso;
    id_proceso=fork();

    if(id_proceso==0){
        printf("\t\tSoy el proceso Hijo\n");
        //exit(0);
        }

    else{
        printf("Soy el proceso Padre\n");
        //exit(0);
        }

}