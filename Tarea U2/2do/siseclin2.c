#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, int argv[]){
    int a, b, c, d, e, f, t, x2, y2, j, p, aux, dety2, detx2, det2, aux2;
    double det, dety, detx, x, y;
    printf("Solucion de un sistema de ecuaciones");
    printf("Considerando el sistema de ecuaciones:\nax+by=c\ndx+ey=f\n\nIngrese los valores enteros de los coeficientes\n");
    printf("Ingrese el valor de a: "); scanf("%d",&a);
    printf("Ingrese el valor de b: "); scanf("%d",&b);
    printf("Ingrese el valor de c: "); scanf("%d",&c);
    printf("Ingrese el valor de d: "); scanf("%d",&d);
    printf("Ingrese el valor de e: "); scanf("%d",&e);
    printf("Ingrese el valor de f: "); scanf("%d",&f);

    printf("Ahora, ingrese el numero correspondiente al conjunto de numeros con los que desee trabajar:\n1. Reales\t2. Enteros\t3. Enteros modulo p\n");
    scanf("%d", &t);

    switch(t){
        case 1:
        det=a*e-d*b;
        detx=c*e-f*b;
        dety=a*f-d*c;
        if (det!=0){
            printf("Existe solucion unica y son\nx = %lg,\ty = %lg\n",detx/det,dety/det);
        }else{
            printf("No existe solucion unica\n");
            if((a%d==0 && b%e==0 && c%f==0)||(d%a==0 && e%b==0 && f%c==0)){
                printf("El sistema tiene infinitas soluciones :0\n");
            }else{
                printf("El sistema es inconsistente UnU\n");
            }
        }
        break;
        case 2:
        det=a*e-d*b;
        detx=c*e-f*b;
        dety=a*f-d*c;
        x = detx/det;
        y = dety/det;
        if (det!=0){
            if((ceil(x)==x && ceil(y)==y)||(floor(x)==x && floor(y)==y)||(floor(y)==y && ceil(x)==x) || (floor(x)==x && ceil(y)==y)){
                printf("Existe solucion unica y son\nx = %lg,\ty = %lg\n", x, y);
            }else{
                printf("No existen soluciones en el conjunto en el que estamos trabajando\n");
            }
        }else{
            printf("No existen soluciones unicas\n");
        if((a%d==0 && b%e==0 && c%f==0 && a/d==b/e && a/d==c/f)||(d%a==0 && e%b==0 && f%c==0 && d/a==e/b && d/a==f/c)){
            printf("El sistema tiene infinitas soluciones :0\n");
        }else{
            printf("El sistema es inconsistente UnU\n");
        }}
        break;
        case 3:
        printf("Ingrese un numero primo, por favor: "); scanf("%d", &p);
        for(j=0;j<p;j++){
            if((d*b+j)%p==0){
                aux = j;
            }
        }
        aux2=(a*e)%p;
        det2=(aux2+aux)%p;
//
        for(j=0;j<p;j++){
            if((f*b+j)%p==0){
                aux = j;
            }
        }
        aux2=(c*e)%p;
        detx2=(aux+aux2)%p;
//
        for(j=0;j<p;j++){
            if((d*c+j)%p==0){
                aux = j;
            }
        }
        aux2=(a*f)%p;
        dety2=(aux2+aux)%p;
//
        for(j=0; j<p; j++){
            if((det2*j)%p==1){
               aux = j;
            }
        }
        x2 = (detx2*aux)%p;

        for(j=0; j<p; j++){
            if((det2*j)%p==1){
               aux = j;
            }
        }
        y2 = (dety2 * aux)%p;

        if(det2!=0){
            printf("Existe solucion unica y son\nx = %d,\ty = %d\n", x2, y2);
        }else{
            printf("No existen soluciones unicas\n");
        }
        break;

        default:
        printf("Haz introducido una opcion invalida UnU");
        break;
    }

    system("pause");
    return 0;
}