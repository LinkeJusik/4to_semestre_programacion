#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    float a,b,c,d,e,f,det,detx,dety,x,y;

    printf("Digite a: "); scanf("%f",&a);
    printf("Digite b: "); scanf("%f",&b);
    printf("Digite c: "); scanf("%f",&c);
    printf("Digite d: "); scanf("%f",&d);
    printf("Digite e: "); scanf("%f",&e);
    printf("Digite f: "); scanf("%f",&f);

    det=a*e-d*b;
    detx=c*e-f*b;
    dety=a*f-d*c;

    x=detx/det;
    y=dety/det;

    printf("La solución es:\n\tx = %f.\n\ty = %f.\n",x,y);

    printf("Fin del programa\n");
    system("pause");

    return 0;
}