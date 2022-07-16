#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char argv[]){
    int a, b, g, d, e, h, t, n, i, aux=0, x, x1, p, q, r, s, xx1, xx2, xx11, xx22, res;
    float x2, a2, b2, alf, bet, gam, del, a1, a3, a4, b1, b3, b4, inv, prod1, prod2, prod3, prod4;
    double dou;
    
    printf("Programa para resolver una ecuacion lineal de la forma\nax+b=0\n\n");
    printf("Ingresa la opcion correspondiente al tipo de ecuacion que deseas resolver: "); scanf("%d", &t);

    //ax+b=0 --> x=-b/a//

    switch(t){
        case 1:
        printf("Ingresa el valor de a: "); scanf("%d", &a);
        printf("Ingresa el valor de b: "); scanf("%d", &b);
        if(a<0 || b<0){
            printf("Los coeficientes de la ecuacion deben de ser numeros naturales\nLa ecuacion (%d)x+(%d) no esta definida en N\n",a,b);
        }else{
            if((floor(-(b/a))>0 && floor(-(b/a))==-(b/a)) || (ceil(-(b/a))>0 && ceil(-(b/a))==-(b/a))){
                printf("Solucion:\nx = %d\n", -(b/a));
            }else{
                printf("La ecuacion no tiene solucion en los numeros Naturales\n");
            }
        }
        break;
        case 2:
        printf("Ingresa el valor de a: "); scanf("%d", &a);
        printf("Ingresa el valor de b: "); scanf("%d", &b);
        dou=abs(b/a);
        if(b%a==0){
            printf("Solucion:\nx = %d\n", -(b/a));
        }else{
            printf("La ecuacion no tiene solucion en los numeros Enteros (Z)\n");
        }
        break;
        case 3:
        printf("Ingresa el valor de a: "); scanf("%d", &a);
        printf("Ingresa el valor de b: "); scanf("%d", &b);
        printf("Ingresa un natural n: "); scanf("%d", &n);
        for(i=0;i<n;i++){
            if((a*i+b)%n==0){
                aux = 1;
                x = i;
            }
        }
        if(aux!=0){
            printf("Solucion:\nx = %d\n", x);
        }else{
            printf("La ecuacion no tiene solucion mod %d\n", n);
        }
        break;
        case 4:
        printf("Ingresa el valor del numerador de a: "); scanf("%d", &p);
        printf("Ingresa el valor del denominador de a: "); scanf("%d", &q);
        printf("Ingresa el valor del numerador de b: "); scanf("%d", &r);
        printf("Ingresa el valor del denominador de b: "); scanf("%d", &s);

        xx1 = r*q; xx11 = r*q;
        xx2 = p*s; xx22 = p*s;

        if(xx11<0) xx11=-xx11;
        if(xx22<0) xx22=-xx22;
        if(xx22==0 && xx11!=0) return xx11;
        if(xx11==0 && xx22!=0) return xx22;
        if(xx11==0 && xx22==0) return 0;
    
        while((res=a%b) != 0){
            xx11=xx22;
            xx22=res;
        }
        //xx22 = mcd//
        if(xx22 == 0){
            printf("La ecuacion no tiene solucion\n");
        }else{
            if(xx1*xx2<0){
                if(xx2/xx22==1||xx2/xx22==-1){
                    printf("Solucion:\nx = %d\n", abs(xx1)/xx22);
                }else{
                    printf("Solucion:\nx = %d/%d\n", abs(xx1)/xx22, abs(xx2)/xx22);
                }
            }else{
                if(xx2/xx22==1||xx2/xx22==-1){
                    printf("Solucion:\nx = -%d\n", abs(xx1)/xx22);
                }else{
                    printf("Solucion:\nx = -%d/%d\n", abs(xx1)/xx22, abs(xx2)/xx22);
                }
            }
        }
        break;
        case 5:
        printf("Ingresa el valor de a: "); scanf("%d", &a2);
        printf("Ingresa el valor de b: "); scanf("%d", &b2);
        printf("Solucion:\nx = %f\n", -(b2/a2));
        break;
        case 6:
        printf("Ingresa el valor de la parte real de a: "); scanf("%f", &alf);
        printf("Ingresa el valor de la parte imaginaria de a: "); scanf("%f", &bet);
        printf("Ingresa el valor de la parte real de b: "); scanf("%f", &gam);
        printf("Ingresa el valor de la parte imaginaria de b: "); scanf("%f", &del);
        a2 = -((alf*gam+del*bet)/(pow(alf,2)+pow(bet,2)));
        b2 = ((gam*bet-alf*del)/(pow(alf,2)+pow(bet,2)));
        printf("Solucion:\n x = %f + (%f)i\n",a2,b2);
        break;
        case 7:
        //Cuaterniones//
        printf("Ingresa el valor de la parte real de a: "); scanf("%f", &a1);
        printf("Ingresa el valor de la parte imaginaria i de a: "); scanf("%f", &a2);
        printf("Ingresa el valor de la parte imaginaria j de a: "); scanf("%f", &a3);
        printf("Ingresa el valor de la parte imaginaria k de a: "); scanf("%f", &a4);
        printf("Ingresa el valor de la parte real de b: "); scanf("%f", &b1);
        printf("Ingresa el valor de la parte imaginaria i de b: "); scanf("%f", &b2);
        printf("Ingresa el valor de la parte imaginaria j de b: "); scanf("%f", &b3);
        printf("Ingresa el valor de la parte imaginaria k de b: "); scanf("%f", &b4);
        ///De forma analoga a los complejos: -b/a=-(1/||a||^2)(conj(a)*b)/
        inv = -1/(a1*a1+a2*a2+a3*a3+a4*a4);
        prod1 = a1*b1+a2*b2+a3*b3+a4*b4;
        prod2 = a1*b2-a2*b1-a3*b4+a4*b3;
        prod3 = a1*b3+a2*b4-a3*b1-a4*b2;
        prod4 = a1*b4-a2*b3+a3*b2-a4*b1;
        printf("Solucion:\n x = %f + (%f)i + (%f)j + (%f)k\n", inv*prod1, inv*prod2, inv*prod3, inv*prod4);
        break;
        case 8:
        printf("Ingresa el termino lineal de a: "); scanf("%d", &a);
        printf("Ingresa el termino constante de a: "); scanf("%d", &b);
        printf("Ingresa el termino lineal de b: "); scanf("%d", &e);
        printf("Ingresa el termino constante de b: "); scanf("%d", &h);
        // (ay+b)(gy+d)+(ey+h)=0 --> agy^2+(bg+ad+e)y+(bd+h)=0 por lo que g=0 y d=-e/a y d=-h/b //
        dou= -e/a;
        if(-(e/a)==-(h/b)){
            if(e%a==0){
                printf("Solucion:\nx = 0y + %d\n",-e/a);
            }else{
                printf("No existe solucion en los enteros");
            }
        }else{
            printf("No existen soluciones a la ecuacion\n");
        }
        break;
        case 9:
        printf("Ingresa el valor de la parte real de a: "); scanf("%d", &a);
        printf("Ingresa el valor de la parte imaginaria de a: "); scanf("%d", &b);
        printf("Ingresa el valor de la parte real de b: "); scanf("%d", &g);
        printf("Ingresa el valor de la parte imaginaria de b: "); scanf("%d", &d);
        xx1 = a*a+b*b;
        e = a*g+d*b;
        h = g*b-a*d;
        if(((e%xx1)==0) && ((h%xx1)==0)){
            e = -((a*g+d*b)/(pow(a,2)+pow(b,2)));
            h = ((g*b-a*d)/(pow(a,2)+pow(b,2)));
            printf("Solucion:\n x = %d + %di\n",e,h);
        }else{
            printf("No existen soluciones enteras\n");
        }
        break;
        default:
        printf("No haz introducido ninguna opcion valida UnU");
        break;
    }
    
    system("pause");
    return 0;
}