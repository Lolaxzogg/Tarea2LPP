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
    funcionDis Diparo;
}Ds;

typedef struct Dg
{
    int id;
    char *nombre;
    funcionDis Diparo;

}Dg;

typedef struct Dl
{
    int id;
       
    char *nombre; //el area puede variar en este
    funcionDis Diparo;

}Dl;
typedef struct Dr
{
    int id;
    char *nombre;
    funcionDis Diparo;
}Dr;
typedef struct D5
{
    int id;
    char *nombre;
    funcionDis Diparo;

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