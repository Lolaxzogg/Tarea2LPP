#ifndef H_TABLERO
#define H_TABLERO

extern void *** tablero;

void inicializarTablero(int tamano);
void mostrarTablero();
void creacionBarcos(int identidad, int tamaño, int longitud);
void asignacion(int x, int y, int sentido, int medida);
void comprobacion(int x, int y, int sentido, int medida);
//void inicializarBarcos(int pequeño, int mediano, int grande, int gigante);

#endif
