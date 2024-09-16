#include "Cartas.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

extern void ***tablero;
extern int cantidadBarcos;
extern int *cap;
int carta500=1;


void inicializarMazo(){
    Cartas.carta=(void **)malloc(5* sizeof(void *));
    Cartas.disponibles = 5;
    for(int i=0; i<5;i++){
        Cartas.carta[i]=(void*)&disparoSimple;
    }
}
void mostrarMazo(){
    for(int i=0; i<5; i++){
       printf("%d.-",i);
       if(Cartas.carta[i]==disparoSimple)printf("Simple \n");
       else if(Cartas.carta[i]==disparoGrande)printf("Grande \n");
       else if(Cartas.carta[i]==disparoLineal)printf("Lineal \n");
       else if(Cartas.carta[i]==disparoRadar)printf("Radar \n");
       else if (Cartas.carta[i]==disparo500KG)printf("NUCLEAR \n");
       else printf("cañon roto \n");
    }
}



void *(*asignarNueva(int simple, int grande, int lineal, int radar, int mega))(int, int){ 
    int numeroRandom= rand() %100;
    if(numeroRandom<simple){
        printf("nueva carta: disparo simple\n");
        return disparoSimple;
    }
    else if(numeroRandom<grande){
        printf("nueva carta: disparo grande\n");
        return disparoGrande;
    }
    else if(numeroRandom<lineal){
        printf("nueva carta:lineal\n");
        return disparoLineal;
    }
    else if(numeroRandom<radar){
        printf("nueva carta: radar\n");
        return disparoRadar;
    }
    else if(numeroRandom<mega){
        printf("nueva carta: Nuclear\n");
        if(carta500==0){ 
            return asignarNueva(simple, grande, lineal, radar, mega);
        }
        else{
            carta500=carta500-1;
            return disparo500KG;            
        }
    }
    else{
        return NULL;
    }
}

void usarCarta(){
    int numero_carta,x,y;
    do
    {
    printf("selecciona una carta: \n");
    if (scanf("%d", &numero_carta) != 1) {
        printf("Error al leer el número.\n");
            return;
        }
    } while (numero_carta>=4);
    fflush(stdin);
    printf("Número de carta seleccionado: %d\n", numero_carta);
    printf("seleccione las coordenada en x: \n");
    scanf(" %d", &x);
    printf("seleccione las coordenada en y: \n");
    scanf(" %d",&y);
    while (x>=*cap||y>=*cap||x<0||y<0)
    {
    printf("Las coordenadas que ingreso estaban fuera del limite\n");
    printf("seleccione las coordenada en x: \n");
    scanf(" %d", &x);
    printf("seleccione las coordenada en y: \n");
    scanf(" %d",&y);       
    }
    
    funcionDis cartaActual= (funcionDis)Cartas.carta[numero_carta];
    if (Cartas.carta[numero_carta] == NULL) {
        printf("Error: Cartas.carta[%d] es NULL.\n", numero_carta);
        return;
    }
    funcionDis nuevaCarta = (void*)cartaActual(x,y);
    Cartas.carta[numero_carta] = nuevaCarta;
}

void *disparoSimple(int x, int y){
    if(*((int*)tablero[x][y])==2){
        *(int *)tablero[x][y]=3;   
        printf("HIT\n");
        cantidadBarcos=cantidadBarcos-1;
    }
    else if(*(int *)tablero[x][y]==1){
        *(int *)tablero[x][y]=4;
        printf("MISS\n");
    }
    return asignarNueva(65,85,90,100,0);
}

void *disparoGrande(int x, int y){
    int contadorHits=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){ 
            if((x+i<0||x+i>=*cap)||(y+j<0||y+j>=*cap)){
                continue;
            }
            if(*(int*)tablero[x+i][y+j]==2){
                *(int *)tablero[x+i][y+j]=3;
                contadorHits+=1;
                cantidadBarcos-=1;
            }
            else if(*(int *)tablero[x+i][y+j]==1){
                *(int *)tablero[x+i][y+j]=4;
                printf("MISS\n");

            }
            else{
            }
        }
    }
    printf("este fue el contador de HITS que hubo :%d\n", contadorHits);
    return asignarNueva(80,83,93,98,100);
}

void *disparoLineal(int x, int y){
    int seleccion=0;
    printf("horizontal 1, vetical 2. Selecciona: %d\n", seleccion);
    scanf("%d", &seleccion);
    int contadorHITS=0;
    if(seleccion==1){
        printf("disparo horizontal\n");
        for(int i=-2;i<=2;i++){
            if((x+i<0||x+i>=*cap)){
                continue;
            }
            if(*(int *)tablero[x+i][y]==2){
                *(int *)tablero[x+i][y]=3;
                contadorHITS+=1;
                cantidadBarcos-=1;
            }
            else if(*(int *)tablero[x+i][y]==1){
                *(int *)tablero[x+i][y]=4;
                printf("MISS\n");
            }
        }
    }
    else{ 
        for(int i=-2;i<=2;i++){
            if((y+i<0||y+i>=*cap)){
                continue;
            }
            if(*(int *)tablero[x][y+i]==2){
                *(int *)tablero[x][y+i]=3;
                contadorHITS+=1;
                cantidadBarcos-=1;
            }
            else if(*(int *)tablero[x][y+i]==1){
                *(int *)tablero[x][y+i]=4;
                printf("MISS\n");
            }
        }
    }
    printf("Estos fueron los hits: %d\n",contadorHITS);
    return asignarNueva(85,90,92,98,100);
}
void *disparoRadar(int x, int y){
    int descubiertos=0;
    for(int i=-2;i<=2;i++){
        for(int j=-2;i<=2;i++){
            if((x+i<0||x+i>=*cap)||(y+j<0||y+j>=*cap)){
                continue;
            }
            if(*(int*)tablero[x+i][y+j]==1){
                descubiertos+=1;
            }
        }
    }
    printf("se han descubierto esta cantidad de partes de barcos presentes en la zona: %d\n",descubiertos);
    return asignarNueva(75,90,95,97,100);
}
void *disparo500KG(int x, int y){
    int contadorHits=0;
    for (int i=-5;i<=5;i++){
        for(int j=-5;j<=5;j++){
            if((x+i<0||x+i>=*cap)||(y+j<0||y+j>=*cap)){
                continue;
            }
            if(*(int *)tablero[x+i][y+j]==2){
                *(int *)tablero[x+i][y+j]=3;
                contadorHits+=1;
                cantidadBarcos-=1;
            }
            else if(*(int *)tablero[x+i][y+j]==1){
                *(int *)tablero[x+i][y+j] = 4;
            }

        }
    }
    printf("Estos fueron los hits: %d",contadorHits);
    return NULL;
}


