#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "string.h"
void *** tablero;
extern *cap;
extern cantidadBarcos;



void inicializarTablero(int casillas){
    tablero= (void***)malloc(casillas * sizeof(void**));
    for( int i=0; i<casillas; i++ ){
        tablero[i]=(void **)malloc(casillas * sizeof(void*)); //fila 
        for(int j=0; j<casillas;j++){ //columna
            tablero[i][j]= NULL;
        }
    }
}



void mostrarTablero(){
    for(int i=0; i<*cap;i++){ //fila
        for(int j=0;j<*cap;j++){
            if(tablero[i][j]!=NULL){
                if (tablero[i][j]==2)
                {
                    printf("| x ");
                }
                else if (tablero[i][j]==3){
                    printf("| 0 ");
                }
                else{
                printf("| B ");
                }
            }
            else{
                printf("|   ");
            }
        }
        printf("|\n");                   //columna
    }
}

/* --------------------------------------------------------------Barcos-----------------------------------------------------------------------------------------------*/


#include "time.h"

int comprobacion(int x, int y, int sentido, int medida){
    int retorno=1;

    if (sentido==1){ //horizontal

        for (int i = 0; i < medida; i++)
        {
            if((x+i)>=*cap||y>=*cap){

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
            if (x>=*cap||(y+i)>=*cap){
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
            tablero[x+i][y]=malloc(sizeof(int)); //pone un uno en el valor de la casilla
            *((int*)tablero[x+i][y]) = 1;
        }
    }
    else{;
        for (int i=0; i<medida; i++){
            tablero[x][y+i]=malloc(sizeof(int)); //pone un uno en el valor de la casilla
            *((int*)tablero[x][y+i]) = 1;

        }
    }
}


void creacionBarcos(int identidad, int tamaño, int longitud){
    mostrarTablero(tamaño);
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
        respuesta=comprobacion(x, y,  direccion, longitud); //1 es true

    
    
    }while(respuesta!=1); 
    asignacion(x,y, direccion, longitud, tamaño);


    

}
