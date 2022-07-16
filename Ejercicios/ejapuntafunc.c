#include <stdio.h>
#include <stdlib.h>

typedef int (*FuncBin)(int, int);
int sumaM7(int a, int b);
int sumaM11(int a, int b);
int sumaE(int a, int b);

int esctabla(int a, int b, FuncBin f);

int main(int argc, char *argv[]){
    int x, y;
    printf("Digite dos enteros: ");
    scanf("%d%d", &x, &y);
    printf("\nPor mandar llamas a esctabla para sumaM7\n");
    esctabla(x, y, sumaM7);
    printf("\nPor mandar llamas a esctabla para sumaM11\n");
    esctabla(x, y, sumaM11);
    printf("\nPor mandar llamas a esctabla para sumaE\n");
    esctabla(x, y, sumaE);

    printf("\nFin del programa\n");
    system("pause");
    return 0;
}

int sumaM7(int a, int b){
    return (((a+b)%7)+7)%7;
}

int sumaM11(int a, int b){
    int ret=(a+b)%11;
    return ret<0?ret+11:ret;
}

int sumaE(int a, int b){
    return a+b;
}

int esctabla(int a, int b, FuncBin f){
    int ini, fin, i, j;
    if(a<=b){
        ini = a; fin = b;
    }else{
        ini = b; fin = a;
    }
    printf("Tabla aditiva, desde\n");
    printf("    ");
    for(j=ini; j<=fin; j++){printf("%3d ", j);}
    printf("\n");
    for(i=-10; i<=10; i++){
        printf("%3d ", i);
        for(j=ini; j<=fin; j++){
            printf("%3d ", f(i,j));
        }
        printf("\n");
    }
}