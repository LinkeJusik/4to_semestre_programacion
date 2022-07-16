#include <stdio.h>
#include <stdlib.h>

#define GRAD_MAX 10

struct poliR{
    int g;
    double c[GRAD_MAX+1];
};

int main(int argc, char *argv[]){
    struct poliR a;
    double r, eval;
    int i;

    printf("Programa para uso de polinomio de grado a lo más %d\n", GRAD_MAX);
    printf("Digite el grado del polinomio a usar: "); scanf("%d", &a.g);
    if(a.g<0 || a.g>GRAD_MAX){
        printf("El valor fuera de rango, por usar el grado igual a 5.\n");
        a.g=5;
    }

    printf("Por leer el polinomio: \n");
    for(i=0; i<=a.g; i++){
        printf("Digite el coeficiente de x^%d: ",i); scanf("%lg", &a.c[i]);
    }
    printf("\nDigite el valor r a evaluar en el polinomio\n");
    scanf("%lg", &r);

    for(eval=0.0, i=a.g; i>=0; i--){
        eval = (eval*r+a.c[i]);
    }

    printf("El resultado de a(%lg) es %lg.\n",r,eval);
    printf("\nFin del programa.\n");
    system("pause");
    return 0;
}