#ifndef H_CARTAS
#define H_CARTAS

void inicializarMazo();
void mostrarMazo();
typedef struct Mano
{
    void ** carta;
    int disponibles;
} Mano;


typedef struct Ds //adjuntar las probabilidades
{
    int id;
    int area;
}Ds;

typedef struct Dg
{
    int id;
    int area;
}Dg;

typedef struct Dl
{
    int id;
       
    int area; //el area puede variar en este
}Dl;






extern Mano Cartas;
void usarCarta();

void * disparoSimple(int x, int y);
void * disparoGrande(int x, int y);
void * disparoLineal(int x, int y);
void * disparoRadar(int x, int y);
void * disparo500KG(int x, int y);

#endif