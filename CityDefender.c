#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"
#include "string.h"
#include "time.h"


//Mano cartas;

int *cap; //capacidad del tablero
//void ***tablero;
//const Ds DisparoSimple = {1, 1};
//const Dg DisparoGrande = {2, 9};
//const Dl DisparoLineal = {3, 3}; //cambiar esta area


/*   
int *cap; //capacidad del tablero
void ***tablero;
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
            printf("| ");
        }
        printf("| \n");                   //columna
    }
}

*/

/* 
void inicializarMazo(){
    cartas.carta=(void **)malloc(5* sizeof(void *));
    cartas.disponibles = 5; 
    for(int i=0; i<5;i++){
        cartas.carta[i] = malloc(sizeof(Ds));   
        *(Ds *)(cartas.carta[i])=DisparoSimple;
    }
}
*/



/*
void mostrarMazo(){
    int desocupadas= cartas.disponibles;
    for(int i=0; i<5; i++){
        Ds *cartaActual = (Ds* )(cartas.carta[i]);
printf("Carta %d: id = %d, area = %d\n", i+1, cartaActual->id, cartaActual->area);
    }
}
*/


/*
----------------------------------------------------------------------
                            Barcos
------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------
*/



int main(int argc, char const *argv[]){
    int tamaño;
    //cap= &tamaño;
    int dificultad, iden=0;
    int barcosPequeños, barcosMedianos, barcosGrandes, barcosGigantes;
    //pequeños->2x1; medianos->3x1; grandes->4x1; gigantes->5x1
    
    printf("Que modalidad quieres jugar?: 1->Facil \n 2->Medio \n 3->Dificil");
    scanf("%d", &dificultad);
    if (dificultad==1){
        tamaño=11;
        inicializarTablero(tamaño);

        cap= &tamaño;
        barcosPequeños=2;
        for(int i=0; i<barcosPequeños; i++){
            mostrarTablero(tamaño);
            printf("primer barco pequeño:%d", iden );
            creacionBarcos(iden, tamaño,2 );
            iden+=1;
        }
        printf("terminamos barcos pequeños");
        barcosMedianos=1;
        creacionBarcos(iden,tamaño,3);
        iden+=1;
        printf("terminamos barcos medianos");
        barcosGrandes=1;
        creacionBarcos(iden,tamaño,4);
        iden+=1;
        barcosGigantes=1;
        creacionBarcos(iden,tamaño,5);
        }
    
    else if (dificultad==2){
        tamaño=17;
        cap= &tamaño;
        inicializarTablero(tamaño);
        barcosPequeños=3;
        for (int i=0; i<barcosPequeños; i++){ 
            creacionBarcos(iden,tamaño,2);
            iden+=1;
        }
        barcosMedianos=2;
        for (int i=0; i<barcosMedianos; i++){
            creacionBarcos(iden, tamaño, 3);
            iden+=1;
        }     
        barcosGrandes=1;
        for (int i=0; i<barcosGrandes; i++){   
            creacionBarcos(iden, tamaño, 4);
            iden+=1;
        }
        barcosGigantes=1;
        for (int i = 0; i < barcosGigantes; i++)
        {
            creacionBarcos(iden, tamaño, 5);
            iden+=1;
        }
        
    }
    else{
        tamaño=21;
        cap= &tamaño;
        inicializarTablero(tamaño);
        barcosPequeños=3;
        for(int i=0; i<barcosPequeños; i++){
            creacionBarcos(iden, tamaño,2);
            iden+=1;
        }
        barcosMedianos=2;
        for (int i=0; i<barcosMedianos; i++){
            creacionBarcos(iden, tamaño, 3);
            iden+=1;
        }
        barcosGrandes=2;
        for( int i=0; i<barcosGrandes;i++){
            creacionBarcos(iden, tamaño,4);
            iden+=1;
        }
        barcosGigantes=2;
        for(int i=0; i<barcosGigantes; i++){
            creacionBarcos(iden, tamaño, 5);
            iden+=1;
        }
    }
//    inicializarTablero(tamaño);
    mostrarTablero();
    inicializarMazo();
    mostrarMazo();    
    return 0;
};
