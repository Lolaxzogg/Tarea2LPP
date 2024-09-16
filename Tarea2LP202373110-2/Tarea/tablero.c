#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "string.h"
void *** tablero;
extern int *cap;
extern int cantidadBarcos;


/* */
void inicializarTablero(int casillas){
    tablero= (void***)malloc(casillas * sizeof(void**));
    for( int i=0; i<casillas; i++ ){
        tablero[i]=(void **)malloc(casillas * sizeof(void*));  
        for(int j=0; j<casillas;j++){ 
            tablero[i][j]=malloc(sizeof(int));
            *(int *)tablero[i][j]= 1;
        }
    }
}



void mostrarTablero(){
    printf("\n");
    for(int i=0; i<*cap;i++){
        for(int j=0;j<*cap;j++){
            if(*(int*)tablero[i][j]!=1){
                if (*(int*)tablero[i][j]==3)
                {
                    printf("| x ");
                }
                else if (*(int*)tablero[i][j]==4){
                    printf("| 0 ");
                }
                else if(*(int*)tablero[i][j]==2){
                    printf("|   ");
                }
            }
            else{
                printf("|   ");
            }
        }
        printf("|\n");                   
    }
}

void mostrarTableroFinal(int tamaño){
    printf("\n");
    for(int i=0; i<*cap;i++){
        for(int j=0;j<*cap;j++){
            if(*(int*)tablero[i][j]!=1){
                if (*(int*)tablero[i][j]==3)
                {
                    printf("| x ");
                }
                else if (*(int*)tablero[i][j]==4){
                    printf("| 0 ");
                }
                else if(*(int*)tablero[i][j]==2){
                    printf("| B ");
                }
            }
            else{
                printf("|   ");
            }
        }
        printf("|\n");                   
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
            else if(*(int *)tablero[x+i][y]!=1){
                retorno=0;
                break;
            }
        }
    }
    else{
 
        for (int i=0; i<medida;i++){
            if (x>=*cap||(y+i)>=*cap){
                retorno=0;
                break;
            }
            else if(*(int *)tablero[x][y+i]!=1){

                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

void asignacion(int x, int y, int sentido, int medida, int tamaño ){
    if(sentido==1){
        for (int i = 0; i < medida; i++)
        {
            *((int*)tablero[x+i][y]) = 2;
        }
    }
    else{;
        for (int i=0; i<medida; i++){
            *((int*)tablero[x][y+i]) = 2;
        }
    }
}


void creacionBarcos(int identidad, int tamaño, int longitud){
    int direccion;
    int y, x, respuesta;
    do {     
        direccion= rand() % 2; 
        if (direccion==0){
            x= rand() % tamaño;
            y= rand() %(tamaño-1);
        }
        else{ 
            x=rand() % (tamaño-1);
            y= rand() & tamaño;
        }
        respuesta=comprobacion(x, y,  direccion, longitud);

    
    }while(respuesta!=1); 
    asignacion(x,y, direccion, longitud, tamaño);
        
}


