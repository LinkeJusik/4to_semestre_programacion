#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, int argv[]){
    int n, i, j, aux, boole;
    printf("Ingrese un numero natural, por favor: "); scanf("%d", &n);
    printf("Las clases del modulo %d son: \n",n);
    for(i=0;i<n;i++){
        printf("%d\t",i);
    }
    printf("\nLos inversos aditivos, en orden, son:\n");
    for(i=0;i<n;i++){
        for(j=0; j<n; j++){
            if((i+j)%n==0){
                printf("%d\t",j);
            }
        }
    }
    printf("\nLos inversos multiplicativos, en orden, son:\n");
    for(i=0;i<n;i++){
        boole = 0;
        for(j=0; j<n; j++){
            if((i*j)%n==1){
                aux = j;
                boole = 1;
            }
        }
        if(boole==1){
            printf("%d\t", aux);
        }else{
            printf("X\t");
        }
    }
    printf("\nLos cuadrados, en orden, son:\n");
    for(i=0;i<n;i++){
        printf("%d\t", (i*i)%n);
    }
    printf("\nLos cubos, en orden, son:\n");
    for(i=0;i<n;i++){
        printf("%d\t", (i*i*i)%n);
    }
    system("pause");
    return 0;
}