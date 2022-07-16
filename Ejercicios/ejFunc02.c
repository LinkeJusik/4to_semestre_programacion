#include <stdio.h>
#include <stdlib.h>

double a_a_la_n(double a, int n);

int main(int argc, char *argv[]){
    double x, r;
    int n;
    printf("digite x: \n"); scanf("%lg", &x);
    printf("digite n: \n"); scanf("%d", &n);

    r=a_a_la_n(x, n);
    printf("\n%lg^%d = %lg\n", x, n, r);
    printf("\nFin del programa\n");

    return 0;
}
double a_a_la_n(double a, int n){
    double ret, cuad;
    if (n<0 return -1.0);
    for(ret = 1.0, cuad=a; n>0; n>>=1){
        if(n&1 != 0) ret *=cuad;
        cuad *= cuad;

        printf("%04x, %lg, %lg\n", n, ret, cuad);
    }
    return ret;
}