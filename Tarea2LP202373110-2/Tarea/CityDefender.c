#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"
#include "string.h"
#include "time.h"


Mano Cartas;
int *cap; //capacidad del tablero
int cantidadBarcos; //cantidad de barcos existentes
//void ***tablero;


/* 
Nombre: limpiar
Parametros:
Funcion: Desocupa la memoria utilizada
Retorno: Nada
*/
void limpiar(){
    for(int i=0; i<*cap;i++){
        for(int j=0; j<*cap; j++){
            if(tablero[i][j]==NULL)continue;
            free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
    free(Cartas.carta);
}

int main(int argc, char const *argv[]){
    int tamaño, maxTurnos;
    int dificultad, iden=0;
    int barcosPequeños, barcosMedianos, barcosGrandes, barcosGigantes;
    //pequeños->2x1; medianos->3x1; grandes->4x1; gigantes->5x1
    printf("Que modalidad quieres jugar?: \n 1->Facil \n 2->Medio \n 3->Dificil\n");
    scanf("%d", &dificultad);
    if (dificultad==1){
        printf("este tablero tiene desde la casilla 0 a la casilla 10 \n");
        tamaño=11;
        maxTurnos=30;
        cap= &tamaño;
        cantidadBarcos= 16;
        inicializarTablero(tamaño);
        barcosPequeños=2;
        for(int i=0; i<barcosPequeños; i++){
            creacionBarcos(iden, tamaño,2 );
            iden+=1;
        }
        barcosMedianos=1;
        creacionBarcos(iden,tamaño,3);
        iden+=1;
        barcosGrandes=1;
        creacionBarcos(iden,tamaño,4);
        iden+=1;
        barcosGigantes=1;
        creacionBarcos(iden,tamaño,5);
        }
    
    else if (dificultad==2){
        printf("Este tablero tiene desde la casilla 0 hasta la 16 para poder disparar\n");
        tamaño=17;
        cap= &tamaño;
        maxTurnos=35;
        inicializarTablero(tamaño);
        cantidadBarcos=21;
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
        printf("Este tablero tiene desde la casilla 0 hasta la 20 para poder disparar\n");
        tamaño=21;
        cap= &tamaño;
        maxTurnos=15;
        inicializarTablero(tamaño);
        cantidadBarcos=30;
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
    inicializarMazo();
    for (int i=0;i<maxTurnos&&cantidadBarcos!=0;i++){
        printf("Turno: %d\n",i);
        mostrarTablero();
        mostrarMazo();
        usarCarta();
        if(cantidadBarcos==0){
            printf("Todos los barcos destruidos\n");
        }
        else if(i==(maxTurnos-1)){
            printf("Perdimos, ya no nos quedan más turnos\n");
        }
    }
    mostrarTableroFinal(tamaño);
    limpiar();
    return 0;
};
