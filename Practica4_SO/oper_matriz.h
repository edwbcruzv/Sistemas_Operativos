#include<stdlib.h>
#include<time.h>
//*****SE DEFINE EL DATO TIPO MATRIZ****
typedef struct matriz{
	int Fila;
	int Columna;
	int**Mat;
}*Matriz;


//****LA FUNCION CREA UN DATO TIPO MATRIZ****
Matriz NuevaMatriz(int fila,int colum){
  
	Matriz m=(Matriz)malloc(sizeof(struct matriz));
	int** mat;
	mat=(int**)calloc(fila,sizeof(int*));
	for(int i=0;i<fila;i++){
	  mat[i]=(int*)calloc(colum,sizeof(int));
	}
	m->Columna=colum;
	m->Fila=fila;
	m->Mat=mat;
	return m;
}

//****REGRESA EL NUMERO DE FILAS DE LA MATRIZ****
int FilaDe(Matriz e){return e->Fila;}
//****REGRESA EL NUMERO DE COLUMNAS DE LA MATRIZ****
int ColumnaDe(Matriz e){return e->Columna;}
     

int EsMayorFila(Matriz e1,Matriz e2){
	if(FilaDe(e1)>=FilaDe(e2)){
	  return 1;
	}
	else return 0;
}    

int EsMayorColum(Matriz e1,Matriz e2){
	if(ColumnaDe(e1)>=ColumnaDe(e2)){
	  return 1;
	}
	else return 0;
} 

//****VERIFICA SI DOS MATRICES CUMPLEN LAS PROPIEDADES PARA MULTIPLICARLAS****
int SonCompatibles(Matriz e1,Matriz e2){
	if(ColumnaDe(e1)==FilaDe(e2)){
	  return 1;
	}
	else return 0;
}

//****FUNCION PARA RECIBIR DATOS LLENAR LA MATRIZ****
void Llena_Mat(Matriz m){

	for(int i=0;i<FilaDe(m); i++){
		for(int j=0; j<ColumnaDe(m); j++){
			printf("[%d][%d]= ",i,j);
			scanf("%d",&(m->Mat[i][j]));
		}
	}	
}

//****FUNCION QUE IMPRIME LA MATRIZ****
void Imp_Mat(Matriz m){
	
	for(int i=0; i<FilaDe(m); i++){
		for(int j=0; j<ColumnaDe(m); j++){
			printf("%d ",m->Mat[i][j]);
		}
	printf("\n");
	}
	for(int k=0; k<ColumnaDe(m); k++){
		printf("+-");
	}
	printf("\n");
}
//****SUMA LAS MATRICES QUE RECIBE****
Matriz Suma(Matriz a,Matriz b){
	
	Matriz r=NuevaMatriz(FilaDe(a),ColumnaDe(a));

	for(int i=0; i<FilaDe(a); i++){
		for(int j=0; j<ColumnaDe(b); j++){
			r->Mat[i][j]=a->Mat[i][j]+b->Mat[i][j];
		}	
	}
	return r;
}

//****SUMA LAS MATRICES QUE RECIBE****
Matriz Resta(Matriz a,Matriz b){

	Matriz r=NuevaMatriz(FilaDe(a),ColumnaDe(a));

	for(int i=0; i<FilaDe(a); i++){
		for(int j=0; j<ColumnaDe(b); j++){
			r->Mat[i][j]=a->Mat[i][j]-b->Mat[i][j];
		}	
	}
	return r;
}

//****SUMA LAS MATRICES QUE RECIBE****
Matriz Traspuesta(Matriz a){

	Matriz r=NuevaMatriz(FilaDe(a),ColumnaDe(a));

	for(int i=0; i<ColumnaDe(a); i++){
		for(int j=0; j<FilaDe(a); j++){
			r->Mat[i][j]=a->Mat[j][i];
		}	
	}
	return r;
}

//****FUNCION QUE MULTIPLICA LAS MATRICES QUE RECIBE****
Matriz Mult(Matriz a,Matriz b){
	
	if(!SonCompatibles(a,b)){
		return NULL;
	}

	Matriz r=NuevaMatriz(FilaDe(a),ColumnaDe(b));

	for(int i=0; i<FilaDe(a); i++){
		for(int j=0; j<ColumnaDe(a); j++){
			for(int k=0;k<ColumnaDe(b);k++){
				r->Mat[i][j]=r->Mat[i][j]+((a->Mat[i][k])*(b->Mat[k][j]));
			}
		}	
	}
	return r;
}
//****LLENA DE CEROS LA MATRIZ QUE RECIBA****
void Zeros(Matriz m){
	
	for(int i=0; i<FilaDe(m); i++){
		for(int j=0; j<ColumnaDe(m); j++){
			m->Mat[i][j]=0;
		}	
	}
}

//****LLENA DE UNOS LA MATRIZ QUE RECIBA****
void Unos(Matriz m){
	
	for(int i=0; i<FilaDe(m); i++){
		for(int j=0; j<ColumnaDe(m); j++){
			m->Mat[i][j]=1;
		}	
	}
}

//****LLENA DE NUMEROS RANDOM LA MATRIZ QUE RECIBA****
//****RANGO SE DEFINE DESDE m HASTA n****
void Randoms(Matriz m,int x,int y){
	srand(time(NULL));

	for(int i=0; i<FilaDe(m); i++){
		for(int j=0; j<ColumnaDe(m); j++){
			m->Mat[i][j]=rand()%(y-x+1)+x;//numero entre X y Y
		}	
	}
}

//****SE CALCULA EL NUMERO DE OPERACIONES(PARA ELLO SE NECESITA VERIFICARLO)****
//int Operaciones(Elem e1,Elem e2){ return FilaDe(e1)*FilaDe(e2)*ColumnaDe(e2);}
