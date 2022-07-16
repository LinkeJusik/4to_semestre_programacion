#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    
    double a, b, c, r, eval;
    printf("Calculo de la derivada y la integral de un polinomio de grado 2\nConsidere el polinomio a(x^2)+bx+c\n");
    printf("Ingrese el valor de a: \n"); scanf("%lg", &a); //termino cuadratico//
    printf("Ingrese el valor de b: \n"); scanf("%lg", &b); //termino lineal//
    printf("Ingrese el valor de c: \n"); scanf("%lg", &c); //termino constante//

    //para cualquier polinomio ax^2+bx+c, su derviada es de la forma 2ax+b, y su integral (a/3)x^3+(b/2)x^2+cx+d//

    printf("La derivada del polinomio es\n2(%lg)x+(%lg)\nO en otras palabras\n%lgx+%lg\n\n",a,b,2*a,b);
    printf("Por otro lado, la integral indefinida es\n(%lg/3)(x^3)+(%lg/2)(x^2)+%lgx+d\nEs decir: \n%lg(x^3)+%lg(x^2)+%lgx+d\n\n", a,b,c,a/3,b/2,c);

    system("pause");

    return 0;
}