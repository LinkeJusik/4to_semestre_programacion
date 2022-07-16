/*
 * Veronica Bola~nos
 * Materia: Programaci'on I
 *
 */

#ifndef _MI_LOGO_H_ //a
#define _MI_LOGO_H_ //para ponerle nombre

#ifdef __cplusplus //a
extern "C" {
#endif     //para que funicones en c++

#include <math.h>

#define ARRIBA 0   //macros
#define ABAJO !(ARRIBA)

#ifndef G2R
#  define G2R (M_PI/180.0)  //cada vez que pongamos gr2 va a ser esto, trnaforma de grados a rad
#endif

typedef int (*misFractales)(void); //puntero o funcion 	

typedef struct _logo_{
  double x, y;
  char pluma;
  int grados;
  void (*dibujaSegmento)(double, double, double, double); //puntero funcion
}LOGO;
//declaracion de funciones
int asignaModoDibujarSegmento(void (*dibujaSegmento)(double, double, double, double), LOGO* tortuga);
int inicia(double x, double y, int grados, char pluma, LOGO* tortuga);
int der(int g, LOGO* tortuga);
int izq(int g, LOGO* tortuga);
int avanza(double l, LOGO* tortuga);
int retrocede(double l, LOGO* tortuga);



#ifdef __cplusplus
}
#endif

#endif
