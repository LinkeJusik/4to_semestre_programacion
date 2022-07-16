#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    
    double a, b, c, r, eval;
    printf("Evaluación de un polinomio en R\nConsidere el polinomio a(x^2)+bx+c\n");
    printf("Ingrese el valor de a: \n"); scanf("%lg", &a);
    printf("Ingrese el valor de b: \n"); scanf("%lg", &b);
    printf("Ingrese el valor de c: \n"); scanf("%lg", &c);

    printf("Ingrese el valor a evaluar: \n"); scanf("%lg", &r);
    
    eval = a*(pow(r,2))+b*r+c;
    printf("La evaluacion es:\n%lg(%lg^2)+%lg(%lg)+%lg = %lg\n",a,r,b,r,c,eval);
    system("pause");

    return 0;
}