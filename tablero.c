#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "string.h"
void *** tablero;
extern *cap;



void inicializarTablero(int casillas){
    tablero= (void***)malloc(casillas * sizeof(void(**)));
    for( int i=0; i<casillas; i++ ){
        tablero[i]=(void **)malloc(casillas * sizeof(void(**))); //fila 
        for(int j=0; j<casillas;j++){ //columna
            tablero[i][j]= NULL;
        }
    }
}



void mostrarTablero(){
    for(int i=0; i<*cap;i++){ //fila
        for(int j=0;j<*cap;j++){
            if(tablero[i][j]!=NULL){
                printf("|   B");
            }
            else{
                printf("|   ");
            }
        }
        printf("| \n");                   //columna
    }
}

/* --------------------------------------------------------------Barcos-----------------------------------------------------------------------------------------------*/


#include "time.h"
typedef struct barcos
{
    int id;
    int size;
    int *x;
    int *y;
    int *hits;
}barcos;


int comprobacion(int x, int y, int sentido, int medida){
    int retorno=1;

    if (sentido==1){ //horizontal

        for (int i = 0; i < medida; i++)
        {
            if((x+1)>=*cap||y>=*cap){

                retorno=0;
                break;
            }
            //cuando haya un uno significa que está ocupado
            else if(tablero[x+i][y]!=NULL){

                retorno=0;
                break;
            }

            
        }
    }
    else{
 
        for (int i=0; i<medida;i++){
            printf("x: %d, y: %d\n", x, y); 
            if (x>=*cap||(y+1)>=*cap){
                retorno=0;
                break;
            }
            else if(tablero[x][y+i]!=NULL){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

void asignacion(int x, int y, int sentido, int medida, int tamaño ){
    
    if(sentido==1){ //horizontal
        for (int i = 0; i < medida; i++)
        {
            tablero[x+i][y]=(void *) 1;

        }
    }
    else{;
        for (int i=0; i<medida; i++){
            tablero[x][y+i]=(void *) 1;

        }
    }
}


void creacionBarcos(int identidad, int tamaño, int longitud){
    mostrarTablero(tamaño);
    barcos barco;
    barco.id= identidad;
    barco.size=longitud;
    int largura=barco.size;
    int direccion;
    int y, x, respuesta; //representa al true
    printf("%d", longitud);
    do {     
        direccion= rand() % 2;  //0-> vertical, 1->horizontal
        if (direccion==0){
            x= rand() % tamaño;
            y= rand() %(tamaño-1);  //asi nos da intervalos entre 0-10
    }
        else{ 
            x=rand() % (tamaño-1);
            y= rand() & tamaño;
        }
        //printf("x: %d, y: %d\n", x, y);    
        respuesta=comprobacion(x, y,  direccion, largura); //1 es true

    
    
    }while(respuesta!=1); 
    asignacion(x,y, direccion, largura, tamaño);


    

}
