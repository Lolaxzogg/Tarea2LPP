#include <stdio.h>

int *global;

void mostrar(){
    printf("%d", *global);
}

int main(){
    int a;
    a=2;
    global= &a;
    a=2;
    mostrar();
    a = 3;
    mostrar();
    a=5;
    mostrar();
    int numero;
    printf("ingrese un numero: ");
    scanf("%d", &numero);
    printf("%d", numero);
    return 0;
}

void inicializarBarcos(int tamaño,int pequeños, int medianos, int grandes, int gigantes){
    int identificacion=0;
    for(int i=0; i<pequeños;i++){
        creacionBarcos(identificacion, tamaño, 2);
        identificacion+=1;
    }
    for(int i=0; i<medianos;i++){
        creacionBarcos(identificacion, tamaño, 3);
        identificacion+=1;

    }
    for(int i=0; i<grandes;i++){
        creacionBarcos(identificacion, tamaño, 4 );
        identificacion+=1;
    }
    for(int i=0; i<gigantes;i++){
        creacionBarcos(identificacion,tamaño, 5 );
        identificacion+=1;
    }
}















/*
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
    int id_carta= ((Ds *)cartaActual)->id;
    switch (id_carta)
    {
    case 1:
        disparoSimple(x,y);
        break;
    
    case 2:
        disparoGrande(x,y);
    
    case 3:
    disparoLineal(x,y);

    }
    
}
*/















/* 
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
            //cuando haya un uno significa que está ocupado
            if(tablero[x+i][y]!=NULL){
                retorno=0;
                break;
            }
        }
    }
    else{
        for (int i=0; i<medida;i++){
            if(tablero[x][y+i]!=NULL){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

void asignacion(int x, int y, int sentido, int medida){
    if(sentido==1){ //horizontal
        for (int i = 0; i < medida; i++)
        {
            tablero[x+i][y]==(void *) 1;
        }
    }
    else{
        for (int i=0; i<medida; i++){
            tablero[x][y+1]=(void *) 1;
        }
    }
}

void creacionBarcos(int identidad, int tamaño, int longitud){
    barcos barco;
    barco.id= identidad;
    barco.size=longitud;
    int direccion;
    int y, x, respuesta; //representa al true
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
        respuesta=comprobacion(x, y,  direccion, size); //1 es true

    
    
    }while(respuesta!=1); 
    asignacion(x,y, direccion, size);
*/