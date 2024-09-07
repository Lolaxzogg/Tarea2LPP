#include "Cartas.h"

Mano cartas;
const Ds DisparoSimple = {1, 1};
const Dg DisparoGrande = {2, 9};
const Dl DisparoLineal = {3, 3}; //cambiar esta area

void inicializarMazo(){
    cartas.carta=(void **)malloc(5* sizeof(void *));
    cartas.disponibles = 5; 
    for(int i=0; i<5;i++){
        cartas.carta[i] = malloc(sizeof(Ds));   
        *(Ds *)(cartas.carta[i])=DisparoSimple;
    }
}
void mostrarMazo(){
    int desocupadas= cartas.disponibles;
    for(int i=0; i<5; i++){
        Ds *cartaActual = (Ds* )(cartas.carta[i]);
printf("Carta %d: id = %d, area = %d\n", i+1, cartaActual->id, cartaActual->area);
    }
}