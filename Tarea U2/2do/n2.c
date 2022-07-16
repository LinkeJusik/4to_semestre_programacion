#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    int i, j, cont, xd, col=0, aux, n, t;

    printf("Programa que imprime 4 tipos de cuadrados\n\n");
    printf("Ingrese la longitud del lado del cuadrado: "); scanf("%d", &n);
    printf("Elija el tipo de cuadrado que quiere: "); scanf("%d", &t);

    switch(t){
        case (1):
            cont = 1;
            for(i=0;i<n;i++){
                for(j=0; j<n; j++){
                    printf("%d\t", cont);
                    cont++;
                }
            printf("\n");
            }
            break;
        case(2):
            for(i=0;i<n;i++){
                cont = i+1-n;
                for(j=0; j<n; j++){
                    cont += n;
                    printf("%d\t", cont);
                }
            printf("\n");
            }
            break;
        case(3):
            col = 0;
            for(i=0;i<n;i++){
                col += (i+1);
                cont = col;
                for(j=0; j<n; j++){
                    aux = i+j+1;
                    if(aux<n+1){
                        
                        printf("%d\t", cont);
                        cont+=aux;
                        xd = aux;
                    }else{
                        xd--;
                        cont+=xd;
                        printf("%d\t", cont-n);
                        //cont+=aux;
                        //
                    }
                }
            printf("\n");
            }
            break;
        case(4):
            col = 0;
            for(i=0;i<n;i++){
                if(i==0){
                    col=1;
                }else{
                    col = col+(2*(i-1)+1);
                }
                cont = col;
                for(j=0; j<n; j++){
                    if(j<i){
                        printf("%d\t", cont);
                        cont++;
                    }else{if(j==i){
                        printf("%d\t", cont);
                    }else{
                        cont += 1 + (2*j);
                        printf("%d\t", cont);
                    }    
                    }
                }
            printf("\n");
            }
            break;
        default:
            printf("No has ingresado una opción valida, lo siento :(");
            break;
    }

    system("pause");
    return 0;
}