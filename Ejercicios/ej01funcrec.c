#include <stdio.h>
#include <stdlib.h>

int funrecA(int nivel, int maxnivel);
int funrecB(int nivel, int maxnivel);
int funrecC(int nivel, int maxnivel);
int fibointerativa(int n);
int fiborec(int n);
int cambioBase(int n, int base);
int Hanoi(int n, char O, char A, char D);

int main(int argc, char *argv[]){
    int n, r, base;
/*
    printf("Un primer ejemplo de funciones rcursivas.\n");
    printf("Por llamar a funrecA.\n");
    funrecA(1,5);
    printf("Por llamar a funrecB.\n");
    funrecB(1,5);
    printf("Por llamar a funrecC.\n");
    funrecC(1,5);

    printf("Digite el valor de n: "); scanf("%d", &n);

    r=fibointerativa(n);
    printf("El valor es: %d.\n", r);

    r = fiborec(n);
    printf("El valor es: %d.\n", r);

    printf("Digite el valor de n: "); scanf("%d", &n);
    printf("Digite el valor de la base: "); scanf("%d", &base);
    cambioBase(n, base);
    printf("\n");
*/
    printf("Digite el valor de n: "); scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');

    system("pause");
    return 0;
}

int funrecA(int nivel, int maxnivel){
    if(nivel >= maxnivel){
        printf("Paso final, por regresar de la recursión.\n");
        return 0;
    }
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    funrecA(nivel+1, maxnivel);
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    return 0;
}

int funrecB(int nivel, int maxnivel){
    if(nivel >= maxnivel){
        printf("Paso final, por regresar de la recursión.\n");
        return 0;
    }
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    funrecB(nivel+1, maxnivel);
    return 0;
}

int funrecC(int nivel, int maxnivel){
    if(nivel >= maxnivel){
        printf("Paso final, por regresar de la recursión.\n");
        return 0;
    }
    funrecB(nivel+1, maxnivel);
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    printf("En el nivel %d, maxnivel %d.\n", nivel, maxnivel);
    return 0;
}

int fibointerativa(int n){
    int an, an_1=1, an_2=1;
    if(n<=2){
        return 1;
    }
    while(n-->2){
        an = an_1+an_2;
        an_2=an_1;
        an_1=an;
    }
    return an;
}

int fiborec(int n){
    if(n<=2){
        return 1;     
    }
    return fiborec(n-1)+fiborec(n-2);
}

int cambioBase(int n, int base){
    int r;
    if(n<0 || base<1) return -1;
    if(n==0) return 0;
    cambioBase(n/base, base);
    r = n%base;
    if(r<10) printf("%d", r);
    else printf("%c", 'A'+r-10);
    return 0;
}

int Hanoi(int n, char O, char A, char D){
    static int m=1;
    if(n<=1){
        printf("%3d) Mover de %c a %c. \n", m++, O, D);
        return 0;
    }
    Hanoi(n-1, O, D, A);
    printf("%3d) Mover de %c a %c. \n", m++, O, D);
    Hanoi(n-1, A, O, D);

    return 0;
}