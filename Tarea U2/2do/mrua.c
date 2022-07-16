#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    
    double m, f, t, a;
    printf("Movimiento rectilineo uniformemente acelerado\n");
    printf("Ingrese el valor de la masa de su objeto (en Kg): \n"); scanf("%lg", &m);
    printf("Ingrese la fuerza con la que se impulsa el objeto (en N): \n"); scanf("%lg", &f);
    printf("Ingrese el tiempo transcurrido desde que el objeto se pone en movimiento (en segundos): \n"); scanf("%lg", &t);

    //dado que la aceleración es uniforme (constante) se puede hacer f=ma, es decir://
    a=f/m;
    //Por otro lado: v_f=at+v_i y x_f=x_i+v_i(t)+(1/2)at^2//
    //Por último: v_i=x_i=0//
    
    printf("El objeto va a una velocidad de %lg(m/s).\n", a*t);
    printf("El objeto está a una distancia de %lg metros de su posicion inicial, en la direccion de la fuerza.\n", (a/2)*(pow(t,2)));
    system("pause");

    return 0;
}