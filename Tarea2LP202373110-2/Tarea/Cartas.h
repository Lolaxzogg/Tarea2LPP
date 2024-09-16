#ifndef H_CARTAS
#define H_CARTAS

/* 
Nombre: Inixializar mazo
Parametros:
Funcion: Inicializa el mazo y entrega las cartas iniciales que son puros disparos simples.
Retorno: Nada
*/
void inicializarMazo();
/* 
Nombre: Mostrar mazo
Parametros:
Funcion: Muestra las cartas acutales de la mano.
Retorno: Nada
*/
void mostrarMazo();

typedef void *(*funcionDis)(int, int);
typedef struct Mano
{
    void ** carta;
    int disponibles;
} Mano;
extern Mano Cartas;
/* 
Nombre: Usar carta
Parametros:
Funcion: Se selecciona alguna carta del mazo y se usa segun sus caracteristicas.
Retorno: Nada
*/

void usarCarta();


/* 
Nombre: Disparo Simple
Parametros: int x, int y
Funcion: usa las caracteristicas de disparo simple y ocupa su carta en las coordenadas x y.
Retorno: Nada
*/
void * disparoSimple(int x, int y);
/* 
Nombre: Disparo Grande
Parametros: int x, int y
Funcion: usa las caracteristicas de disparo Grande y ocupa su carta en las coordenadas x y.
Retorno: Nada
*/
void * disparoGrande(int x, int y);
/* 
Nombre: Disparo Lineal
Parametros: int x, int y
Funcion: usa las caracteristicas de disparo lineal y ocupa su carta en las coordenadas x y, con sentido horizontal o vertical.
Retorno: Nada
*/
void * disparoLineal(int x, int y);
/* 
Nombre: Disparo Radar
Parametros: int x, int y
Funcion: usa las caracteristicas de disparo Radar y ocupa su carta en las coordenadas x y.
Retorno: Nada
*/
void * disparoRadar(int x, int y);
/* 
Nombre: Disparo 500 KG
Parametros: int x, int y
Funcion: usa las caracteristicas de disparo 500Kg y ocupa su carta en las coordenadas x y.
Retorno: Nada
*/
void * disparo500KG(int x, int y);
/* 
Nombre: asignar nueva
Parametros: int simple, int grande, int lineal, int radar, int mega 
Funcion: Asigna nueva carta segun las probabilidades que tienen.
Retorno: Nada
*/
//void *(*asignarNueva(int simple, int grande, int lineal, int radar, int mega))(int, int){ 

#endif