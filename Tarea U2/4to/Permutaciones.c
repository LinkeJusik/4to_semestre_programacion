#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int permuta(int n, int r);

int main(int argc, char *argv[]){
    int n, i, true=0;
    while(true==0){
        printf("Ingresa el número del que quieres calcular las permutaciones: "); scanf("%d", &n);
        if(n>=0){
            true = 1;
        }else{
            printf("Haz ingresado una opción invalidad.\n");
        }
    }
    printf("Las permutaciones de %d elementos son:\n");
    for(i=0; i<=n; i++){
        printf("%d\t",i);
    }
    printf("\n");
    for(i=0; i<=n; i++){
        printf("%d\t",permuta(n, i));
    }
    printf("\n\n");
    system("pause");
    return 0;
}

int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}
int permuta(int n, int r){
    int p;
    p=(factorial(n))/(factorial(n-r));
    return p;
}
