#include <stdio.h>
#include <stdlib.h>

#include "Q.h"
#include "Qi.h"

int main(int argc, char argv[]){
    Q a,b,r;
    Qi z, w, t;
    int num, den;
    char saludo1[32];
    char saludo2[]={'H','o','l','a','\0'};
    char saludo3[]="Hola";
    //printf("saludo1 = <<%s>>\nsaludo2=<<%s>>\nsaludo3=<<%s>>\n", saludo1, saludo2, saludo3);//

    printf("Racional complejo.\n");
	z=leerQi("de z\n");
	printf("Racional complejo\n");
	w=leerQi("de w\n");
	
	t=sumaQi(z,w);
	printf("El resultado de la suma es: \n");
	escQi(t);

    a = leeQ("a");
    b = leeQ("b");

    r=sumaQ(a,b);
    escQ(a); printf(" + "); escQ(b); printf(" = "); escQ(r);
    printf("\n");
    r=prodQ(a,b);
    escQ(a); printf(" * "); escQ(b); printf(" = "); escQ(r);
    system("pause");
    return 0;
}