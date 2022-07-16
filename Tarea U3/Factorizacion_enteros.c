#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int comprobar(long int x,long int y,long int aux);
long int cota(double x);
long int multiplicidad(long int x,long int y);

int main(){
    long int a, cx, comprobador=0;
    double ax;
    while(comprobador==0){
        printf("Ingresa un numero entero positivo: "); scanf("%lg", &ax);
        if(ceil(ax)==floor(ax) && ax>0){
            comprobador=1;
            a=ax;
        }else{
            printf("El numero ingresado es invalido.\nIntentalo una vez más.\n");
        }
    }
    comprobar(cota(a),ax,0);
    system("pause");
    return 0;
}

long int comprobar(long int x, long int y, long int aux){
    long int i, sosprimo=0, xd=aux;
    for(i=2; i<=x; i++){
        if(y%i==0){
            if(aux==0 && comprobar(cota(i),i,1)==0){
                printf("%ld es factor de %ld de multiplicidad %ld\n", i, y, multiplicidad(i, y));
            }
            if(aux==0 && comprobar(cota(y/i),y/i,1)==0 && i!=y/i){
                printf("%ld es factor de %ld de multiplicidad %ld\n", y/i, y, multiplicidad(y/i, y));
            }
            sosprimo=1;
        }
    }
    if(sosprimo==0 && xd==0){
        printf("El número es primo\n");
    }
    return sosprimo;
}

long int cota(double x){
    long int cx;
    float c;
    c = sqrt(x);
    if(ceil(c)==floor(c)){
        cx=c;
        return cx;
    }else{
        return floor(c);
    }
}

long int multiplicidad(long int x,long int y){
    long int aux=y, r=0, i=0;
    while(aux%x==0){
        aux=aux/x;
        i++;
    }
    return i;
}