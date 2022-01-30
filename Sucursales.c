#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define D 30
#define M 6

struct sucursal{
int id;
char ciudad[20];
float descuento[30];
float descuentot;
float promedesc;
};

struct gerente{
int idGerente;
int id;
char nombre[30];
};


void LLenar_matriz(float matriz[][M],int n );
void LLENAR_DATOS(struct sucursal suc[],struct gerente ger[], int n);
void Total_de_descuentos_del_mes(struct sucursal suc[],int n);
void Promedio_Descuentos(struct sucursal suc[], float matriz [][M], int n);
int UBICACION(struct sucursal suc[],int tercerarray[], int n );
void IMPRESION(struct sucursal suc[], struct gerente ger[], int n , int tercerarray[], int cant);
void ORDENAMIENTO (struct sucursal suc[], int n);


int main(){
int i,j,n, cant;

printf("INGRESE CANTIDAD DE SUCURSALES A CARGAR:\n");
scanf("%d",&n);

struct sucursal suc[n];
struct gerente ger[n];
int tercerarray [n];
float matriz[n][M];

for (i=0; i<n; i++){
    tercerarray[i]= -1;

}


LLenar_matriz(matriz,n);
LLENAR_DATOS(suc,ger,n);
Total_de_descuentos_del_mes(suc, n);
Promedio_Descuentos(suc,matriz,n);
cant = UBICACION(suc, tercerarray, n);

IMPRESION(suc,ger, n, tercerarray, cant);
ORDENAMIENTO (suc,n);

// imprimo matriz para corroborar datos
for(i=0; i<n;i++){
    for(j=0;j<M;j++){
        printf("%.3f\t",matriz[i][j]);
    }
    printf("\n");
}
return 0;
}


void LLenar_matriz(float matriz[][M],int n ){
int i, j;

srand(time(NULL));


for(i= 0; i<n; i++){
    for(j =0; j<M; j++){
        matriz[i][j]= rand()%100;
    }
}
return;
}


void LLENAR_DATOS(struct sucursal suc[],struct gerente ger[], int n){
int i,j;

for(i=0; i<n; i++){
    printf("Numero de Id de la Sucursal:\n");
    scanf("%d",&suc[i].id);
    fflush(stdin);
    ger[i].id = suc[i].id;


    printf("Ciudad:\n");
    gets(suc[i].ciudad);
    fflush(stdin);

    printf("Numero de Id Gerente:\n");
    scanf("%d",&ger[i].idGerente);
    fflush(stdin);


    printf("Ingrese el Nombre del Gerente de la sucursal:\n");
    gets(ger[i].nombre);
    fflush(stdin);



for(j=0; j<30; j++){

    printf("El Descuento dia: %d\n", j+1);
    scanf("%f",&suc[i].descuento[j]);
    fflush(stdin);


}

}
return;
}


void Total_de_descuentos_del_mes(struct sucursal suc[],int n){
int i,j;
float suma= 0;

    for(i=0; i<n; i++){
            suma=0;
        for (j=0; j<30; j++ ){

            suma += suc[i].descuento[j];
        }
        suc[i].descuentot= suma;
    }



return;
}


void Promedio_Descuentos(struct sucursal suc[], float matriz [][M], int n){
int i,j;
float suma= 0;

    for (i=0; i<n ; i++){
            suma= 0;
        for (j=0; j<M; j++){
            suma += matriz[i][j];

        }
        suc[i].promedesc = suma/M;

    }

return;
}



int UBICACION(struct sucursal suc[],int tercerarray[], int n ){
int i, j = 0;

    for(i=0; i<n; i++){
        if(suc[i].descuentot > suc[i].promedesc){
            tercerarray[j]=i;
            j++;

        }

    }

return j;
}



void IMPRESION(struct sucursal suc[], struct gerente ger[], int n , int tercerarray[], int cant){
int i,j;

    for(i=0; i<cant ; i++){
        j=tercerarray[i];
        printf("Ciudad max promedio: %s\n\n",suc[j].ciudad);
        printf("El nombre del gerente: %s\n\n", ger[j].nombre);

    }

}

void ORDENAMIENTO (struct sucursal suc[], int n){
 int j,i;
 struct sucursal temp;

    for(i =0; i<n;i++){
        for(j=i+1;j<n;j++){
            if((strcmp(suc[i].ciudad,suc[j].ciudad) ) > 0){
                temp=suc[i];
                suc[i]=suc[j];
                suc[j]=temp;
            }
        }
    }
    printf("Las Ciudades ordenadas por Orden Ascendente:\n\n");
      for(i=0;i<n;i++){
    printf("Ciudad ordenado [%i]: %s \n",i,suc[i].ciudad);
    }

 return;
}
