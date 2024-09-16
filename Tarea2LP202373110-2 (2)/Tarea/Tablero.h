#ifndef H_TABLERO
#define H_TABLERO

extern void *** tablero;

/* 
Nombre: Inicializar tablero
Parametros: int tamaño
Funcion: Inicializa el tablero segun la dificultad
Retorno: Nada
*/
void inicializarTablero(int tamano);
/* 
Nombre: Mostrar tablero
Parametros:
Funcion: Muestra el tablero, si se falló algun disparo, si le dio a algun barzo.
Retorno: Nada
*/
void mostrarTablero();
/* 
Nombre: Creacion de barcos
Parametros: int identidad, int tamaño, int longitud
Funcion: Asigna las coordenadas a los barcos de forma aleatoria.
Retorno: Nada
*/
void creacionBarcos(int identidad, int tamaño, int longitud);
/* 
Nombre: Asignación
Parametros: int x, int y, int sentido, int medida
Función: Asigna en el tablero el barco segun las coordenadas dadas y el tamaño de los barcos.
Retorno: Nada
*/
void asignacion(int x, int y, int sentido, int medida);
/* 
Nombre: comprobacion
Parametros: int x, int y, int sentido, int medida
Función: Comprueba las coordenadas que se le entregaron para ver si la asignacion se puede realizar.
Retorno: Nada
*/
void comprobacion(int x, int y, int sentido, int medida);
/* 
Nombre: Mostrar tablero final
Parametros: int tamaño
Función: Muestra el tablero una vez se haya acabado el juego con los barcos que no se destruyeron o con el
mapa final segun el contexto del juego
Retorno: Nada
*/
void mostrarTableroFinal(int tamaño);

#endif
