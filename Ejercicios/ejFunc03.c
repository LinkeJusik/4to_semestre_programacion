#include <stdio.h>
#include <stdlib.h>
#define tam(x) printf("sizeof("#X") = %d\n", sizeof(X))
#define valor(X) printf("La variable " #X " tiene el valor " fmt "\n", X)

int asigna(int x, int *y);

int main(int argc, char *argv[]){
    int a,b,e,n, *pint;
    short s, *pshort;
    double d, *pdouble;
    char c, *pchar;

    tam(n);
    tam(s);
    tam(d);
    tam(c);
    tam(pint);
    tam(pshort);
    tam(pdouble);
    tam(pchar);

    valor(n, "%d");
    valor(s, "%d");
    valor(d, "%lg");
    valor(c, "%c");
    valor(pint, "%p");
    valor(pshort, "%p");
    valor(pdouble, "%p");
    valor(pchar, "%p");

    pint = &n;
    *pint = 2+3*5;

    valor(n, "%d");

    a = 1; b = 2;

    printf("\na=%d, b=%d, e=%d\n",a,b,e);
    e = asigna(a, &b);
    printf("\na=%d, b=%d, e=%d\n",a,b,e);

    printf("\nFin del programa\n")

}

int asigna(int x, int *y){
    int r;
    r= x* *y;
    *y +=3*r;
    x -= 7;
    return x+*y+r;
}