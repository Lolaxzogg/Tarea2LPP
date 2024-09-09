#include "Cartas.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

extern void ***tablero;
Mano cartas;
const Ds DisparoSimple = {1, "Simple",disparoSimple};
const Dg DisparoGrande = {2, "Grande",disparoGrande};
const Dl DisparoLineal = {3, "Lineal",disparoLineal};//cambiar esta area
const Dr DisparoRadar = {4, "Radar",disparoRadar};
const D5 Disparo500KG = {5 , "500KG",disparo500KG};


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
    printf("Carta: %s id = %d" ,cartaActual->nombre, cartaActual->id);
    }
}



int comprobarCoordenadas(int x, int y){
    if(tablero[x][y]!=NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//mega=500kg poner esta funcion en cartas.h
void *(*asignarNueva(int simple, int grande, int lineal, int radar, int mega))(int, int){ 
    int numeroRandom= rand() %100;
    if(numeroRandom<simple){
        return disparoSimple;
    }
    else if(numeroRandom<grande){
        return disparoGrande;
    }
    else if(numeroRandom<lineal){
        return disparoLineal;
    }
    else if(numeroRandom<radar){
        return disparoRadar;
    }
    else if(numeroRandom<mega){
        return disparo500KG;
    }
    else{
        return NULL;
    }
}

void usarCarta(){
    int numero_carta,x,y;
    printf("selecciona una carta: ");
    scanf("%d", &numero_carta);
    //void *cartaActual= cartas.carta[numero_carta];
    //int id_carta= ((Ds *)cartaActual)->id;
    funcionDis cartaActual= (funcionDis)cartas.carta[numero_carta];
    do
    {
        printf("seleccione las coordenadas: ");
        scanf("x= %d, y =%d", x, y);
        if(comprobarCoordenadas(x,y)){
            printf("coordenadas ya descubiertas, digite otras");
        }
    
    
    } while (comprobarCoordenadas(x,y));
    funcionDis nuevaCarta= (funcionDis)cartaActual(x,y);
    cartas.carta[numero_carta]= nuevaCarta;
    //comprobar que estan dentro del rango, guiar por lo de tablero.c
}

void *disparoSimple(int x, int y){
    if(tablero[x][y]==(void*)1){
        tablero[x][y]==(void*)2;   
        printf("HIT"); 
    }
    else{
        tablero[x][y]==(void*)3;
        printf("MISS");
    }
    //Nueva carta
    return asignarNueva(65,20,5,10,0);
}

void *disparoGrande(int x, int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(tablero[x+i][y+j]==(void*)1){
                tablero[x][y]==(void *)2;
                printf("HIT");
            }
            else if(tablero[x+i][y+j]==NULL){
                tablero[x+i][y+j]==(void *)3;
                printf("MISS");

            }
            else{
                break; //caso que la casilla tenga ya asignado un valor
            }
        }
    }
    return asignarNueva(80,3,10,5,2);
}

void *disparoLineal(int x, int y){
    if(x>y){
        for(int i=-2;i<=2;i++){
            if(tablero[x+i][y]==(void *)1){
                tablero[x+i][y]==(void *)2;
                printf("HIT");
            }
            else if(tablero[x+i][y]==NULL){
                tablero[x+i][y]==(void *)3;
                printf("MISS");
            }
            else{
                break;
            }
        }
    }
    else{
        for(int i=-2;i<=2;i++){
            if(tablero[x][y+i]==(void *)1){
                tablero[x][y+i]==(void *)2;
                printf("HIT");
            }
            else if(tablero[x][y+i]==NULL){
                tablero[x][y+i]==(void *)3;
                printf("MISS");
            }
            else{
                break;
            }
        }
    }
    return asignarNueva(85,5,2,6,2);
}
void *disparoRadar(int x, int y){
    int descubiertos=0;
    for(int i=-2;i<=2;i++){
        for(int j=-2;i<=2;i++){
            if(tablero[x+i][y+j]==(void *)1){
                descubiertos+=1;
            }
        }
    }
    printf("se han descubierto esta cantidad de partes de barcos presentes en la zona: %d",descubiertos);
    return asignarNueva(75,15,5,2,3);
}
//ver como hacer para restringirlo una vez
void *disparo500KG(int x, int y){
    for (int i=-5;i<=5;i++){
        for(int j=-5;j<=5;j++){
            if(tablero[x+i][y+j]==(void *)1){
                tablero[x+i][y+j]==(void *)2;
                printf("HIT");
            }
            else if(tablero[x+i][y+j]==NULL){
                tablero[x+i][y+j]==(void *)3;
                printf("MISS");
            }
            else{
                break;
            }
        }
    }
    //hay que quitar este cañon
}

