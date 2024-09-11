#include "Cartas.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

extern void ***tablero;
extern int cantidadBarcos;
extern int *cap;
int carta500=1;

Mano cartas;


void inicializarMazo(){
    cartas.carta=(void **)malloc(5* sizeof(void *));
    cartas.disponibles = 5;
    for(int i=0; i<5;i++){
        cartas.carta[i]=(void*)&disparoSimple;
    }
}
void mostrarMazo(){
    int desocupadas= cartas.disponibles;
    for(int i=0; i<5; i++){
        if(cartas.carta[i]==NULL){
            printf("Cañon roto:--\n");
        }else {
            printf("carta:");
        }
    }
}



int comprobarCoordenadas(int x, int y){
    printf("hola");
    return (tablero[x][y]!=NULL);
}
//mega=500kg poner esta funcion en cartas.h
void *(*asignarNueva(int simple, int grande, int lineal, int radar, int mega))(int, int){ 
    
    printf("vamos a asignar una nueva carta");
    int numeroRandom= rand() %100;
    printf("%d", numeroRandom);
    if(numeroRandom<simple){
        printf("nueva carta: disparo simple");
        return disparoSimple;
    }
    else if(numeroRandom<grande){
        printf("nueva carta: disparo grande");
        return disparoGrande;
    }
    else if(numeroRandom<lineal){
        printf("nueva carta:lineal");
        return disparoLineal;
    }
    else if(numeroRandom<radar){
        printf("nueva carta: radar");
        return disparoRadar;
    }
    else if(numeroRandom<mega){
        if(carta500==0){ //ya se ocupo una carta de 500 kg, entonces no puede volver a salir y buscamos hasta que salga una diferente
            return asignarNueva(simple, grande, lineal, radar, mega);
        }
        else{
            carta500=carta500-1;
            return disparo500KG;            
        }
    }
    else{
        printf("xd");
        return NULL;
    }
}

void usarCarta(){
    int numero_carta,x=0,y=0,condicion=0;
    fflush(stdin);
    fflush(stdout);
    printf("selecciona una carta: ");
    if (scanf("%d", &numero_carta) != 1) {
        printf("Error al leer el número.\n");
        return;
    }   
    fflush(stdin);
    printf("Número de carta seleccionado: %d\n", numero_carta);
    printf("seleccione las coordenada en x: ");
    scanf(" %d", &x);
    printf("seleccione las coordenada en y: ");
    scanf(" %d",&y);
    funcionDis cartaActual= (funcionDis)cartas.carta[numero_carta];
    if (cartas.carta[numero_carta] == NULL) {
        printf("Error: cartas.carta[%d] es NULL.\n", numero_carta);
        return;
    }
    funcionDis nuevaCarta = (void*)cartaActual(x,y);
    cartas.carta[numero_carta] = nuevaCarta;
    //comprobar que estan dentro del rango, guiar por lo de tablero.c
}

void *disparoSimple(int x, int y){
    if(*((int*)tablero[x][y])==1){
        tablero[x][y]=(void*)2;   
        printf("HIT");
        cantidadBarcos=cantidadBarcos-1;
    }
    else{
        printf("holaaa");
        tablero[x][y]=(void*)3;
        printf("MISS");
    }
    //Nueva carta
    return asignarNueva(65,85,90,100,0);
}

void *disparoGrande(int x, int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){ //caso que alguna coordenada este fuera del rango
            if(x+i>=*cap||x+i>=0||y+j>=*cap||y+j>=0){
                continue;
            }
            else if(tablero[x+i][y+j]==(void*)1){
                tablero[x][y]=(void *)2;
                printf("HIT");
                cantidadBarcos=cantidadBarcos-1;
            }
            else if(tablero[x+i][y+j]==NULL){
                tablero[x+i][y+j]=(void *)3;
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
                tablero[x+i][y]=(void *)2;
                printf("HIT");
                cantidadBarcos=cantidadBarcos-1;
            }
            else if(tablero[x+i][y]==NULL){
                tablero[x+i][y]=(void *)3;
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
                cantidadBarcos=cantidadBarcos-1;
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
                cantidadBarcos=cantidadBarcos-1;
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

