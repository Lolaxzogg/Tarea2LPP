#ifndef H_CARTAS
#define H_CARTAS

void inicializarMazo();
void mostrarMazo();
typedef void *(*funcionDis)(int, int);
typedef struct Mano
{
    void ** carta;
    int disponibles;
} Mano;


typedef struct Ds //adjuntar las probabilidades
{
    int id;
    char *nombre;
    funcionDis Disparo;
}Ds;

typedef struct Dg
{
    int id;
    char *nombre;
    funcionDis Disparo;

}Dg;

typedef struct Dl
{
    int id;
       
    char *nombre; //el area puede variar en este
    funcionDis Disparo;

}Dl;
typedef struct Dr
{
    int id;
    char *nombre;
    funcionDis Disparo;
}Dr;
typedef struct D5
{
    int id;
    char *nombre;
    funcionDis Disparo;

}D5;







extern Mano Cartas;
void usarCarta();

void * disparoSimple(int x, int y);
void * disparoGrande(int x, int y);
void * disparoLineal(int x, int y);
void * disparoRadar(int x, int y);
void * disparo500KG(int x, int y);
int comprobrarCoordenadas(int x, int y);


#endif