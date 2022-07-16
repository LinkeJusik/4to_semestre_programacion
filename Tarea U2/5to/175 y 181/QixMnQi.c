#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include "Qi.h"
#include "Q.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define TAM_MAX 25

typedef struct _MAT_{
	int m,n;
	Qi **ent;
}MAT;

typedef struct _Vec_{
	int n;
	MAT ent[TAM_MAX];
}Vec;

Vec leeVec(Vec ret, int n);
int imprimirVec(Vec a);
int imprimirDerVec(Vec a);
int imprimirIntVec(Vec a);
Vec sumavec(Vec a, Vec b);
Vec restavec(Vec a, Vec b);
Vec prodvec(Vec a, Vec b);
int imprimir2Vec(Vec a);

MAT leemat(MAT a, int m, int n);
MAT inicializa(MAT a);
MAT sumamat(MAT b, MAT c);
MAT restamat(MAT b, MAT c);
MAT producmat(MAT b, MAT c);
int escmat(MAT a);
MAT producporesc(MAT b, Qi c);

int main(int argc, char *argv[]) {
	Vec a, b;
    int i, j, k, n;
    Qi complex;
    MAT aux;

    printf("Ingrese el grado de los polinomios"); scanf("%d", &n);
	printf("Por leer los coeficientes del primer polinomio \n");
	a = leeVec(a, n);
    printf("El primer polinomio es:\n");
    imprimirVec(a);
	b = leeVec(b, n);
    printf("El segundo polinomio es:\n");
    imprimirVec(b);
	
    printf("\nIngrese el número complejo en el que quisiera evaluar los polinomios: \n");
    complex=leerQi(" ");
    aux=inicializa(aux);

 //suma//
    printf("La suma de los dos polinomios es: \n");
    imprimirVec(sumavec(a,b));
//resta//
	printf("La resta de los dos polinomios es: \n");
    imprimirVec(restavec(a,b));
//producto//
	printf("\nEl producto de los polinomios son: \n");
	imprimirVec(prodvec(a,b));

//Derivada//
    printf("\nLa derivada del primero es: \n");
    imprimirDerVec(a);
    printf("\nLa derivada del segundo es: \n");
    imprimirDerVec(b);
//Integral//
    printf("\nLa integral del primero es: \n");
    imprimirIntVec(a);
    printf("\nLa integral del segundo es: \n");
    imprimirIntVec(b);

//Evaluación//
    for(i=n; i>=0; i--){
        aux=sumamat(producporesc(a.ent[i],powQi(complex,i)),aux);
    }
    printf("\nLa evaluación del primer polinomio es: \n");
    escmat(aux);

    aux=inicializa(aux);
    for(i=n; i>=0; i--){
        aux=sumamat(producporesc(b.ent[i],powQi(complex,i)),aux);
    }
    printf("\nLa evaluación del segundo polinomio es: \n");
    escmat(aux);
    printf("\n");
	system("pause");
	return 0;
}

Vec leeVec(Vec ret, int n){
	ret.n=n;
	int i;
	printf("Digite las entradas del vector: \n");
	for(i=ret.n; i>=0; i--){
		printf("x^%d: \n",i);
		ret.ent[i]=leemat(ret.ent[i], ret.n,ret.n);
    }
	return ret;
}

MAT leemat(MAT a, int m, int n){
	MAT ret;
	int i,j;
	
	ret.m=m;
	ret.n=n;
	
	if(ret.n<=0 || ret.m<=0){
		ret.m = ret.n = -1;
		return ret;
	}
	
	ret.ent = (Qi **)malloc(ret.m*sizeof(Qi*));
	if(ret.ent == NULL){
		ret.m=ret.n=-1;
		return ret;
		
	}
	for (i=0;i<ret.m;i++){
		ret.ent[i] = (Qi *)malloc(ret.n*sizeof(Qi));
		if(ret.ent[i] == NULL){
			while(i>0){
				free(ret.ent[--i]);
				ret.ent[i]=NULL;
			}
			free(ret.ent);
			ret.ent = NULL;
			ret.m=ret.n=-1;
			return ret;
		}
	}

	printf("digite las entradas de la matriz: \n");
	for (i=0;i<ret.m;i++)
		for(j=0;j<ret.n;j++){
			printf("entra[%d,%d]: \n",i,j);
			ret.ent[i][j]=leerQi(" ");
		}
	return ret;
}

int imprimirVec(Vec a){
    Vec ret = a;
    int i;
	for(i=ret.n; i>=0; i--){
        if(i==ret.n){
            printf("\t");
		escmat(ret.ent[i]);
        printf("x^%d\t",i);
        }else{
            printf("+\t");
		escmat(ret.ent[i]);
        printf("x^%d\t",i);
        }
	}
    return 0;
}
int imprimirDerVec(Vec a){
    Vec ret = a;
    Qi com;
    int i;
    com.re.den=1;
    com.im.num=0;
    com.im.den=1;
    if(a.n == 0){
        printf("0");
    }else{
        for(i=ret.n; i>=1; i--){
            if(i==ret.n){
            com.re.num=i;
            printf("\t");
		    escmat(producporesc(ret.ent[i], com));
            printf("x^%d\t",i-1);
            }else{
            com.re.num=i;
            printf("+\t");
		    escmat(producporesc(ret.ent[i], com));
            printf("x^%d\t",i-1);
            }
	    }
    }
    return 0;
}
int imprimirIntVec(Vec a){
    Vec ret = a;
    Qi com;
    int i;
    com.re.num=1;
    com.im.num=0;
    com.im.den=1;
    for(i=ret.n; i>=0; i--){
        if(i==ret.n){
        com.re.den=i+1;
        printf("\t");
	    escmat(producporesc(ret.ent[i], com));
        printf("tx^%d\t",i+1);
        }else{
        com.re.den=i+1;
        printf("+\t");
	    escmat(producporesc(ret.ent[i], com));
        printf("x^%d\t",i+1);
        }
    }
    printf("+\tC");
    return 0;
}

Vec sumavec(Vec a, Vec b){
    int i;
    Vec res;
    res.n=b.n;
    for(i=0;i<=res.n;i++){
		res.ent[i] = sumamat(a.ent[i], b.ent[i]);
    }
    return res;
}
Vec restavec(Vec a, Vec b){
    int i;
    Vec res;
    res.n = b.n;
    for(i=0;i<=res.n;i++){
		res.ent[i] = restamat(a.ent[i], b.ent[i]);
    }
    return res;
}
Vec prodvec(Vec a, Vec b){
    int i, j;
    Vec prod;
    for(i=0;i<TAM_MAX;i++){
        prod.ent[i]=inicializa(prod.ent[i]);
    }
    prod.n = a.n+b.n;
    for(i=0;i<=b.n;i++){
		for(j=0;j<=a.n;j++){
            prod.ent[i+j] = sumamat(producmat(a.ent[j], b.ent[i]), prod.ent[i+j]);
		}
    }
    return prod;
}

MAT inicializa(MAT a){
    int i, j;
    for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=ceroQi(a.ent[i][j]);
		}
	}
    return a;
}

MAT sumamat(MAT b, MAT c){
    MAT a;
    a=inicializa(a);
    int i, j;
    a.m = b.m;
    a.n = b.n;
    for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=sumaQi(b.ent[i][j],c.ent[i][j]);
		}
    return a;
}
MAT restamat(MAT b, MAT c){
    MAT a;
    a=inicializa(a);
    int i, j;
    a.m = b.m;
    a.n = b.n;
    for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=restaQi(b.ent[i][j],c.ent[i][j]);
		}
    return a;
}
MAT producmat(MAT b, MAT c){
    MAT a;
    int i, j,k;
    a.m = b.m;
    a.n = b.n;
    a=inicializa(a);
    for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			for(k=0; k<a.n; k++){
                a.ent[i][j] = sumaQi(a.ent[i][j], prodQi(b.ent[i][k],c.ent[k][j]));
            }
		}
    return a;
}
int escmat(MAT a){
    int i,j;
    for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			escQi(a.ent[i][j]);
		}
		printf("\n");
	}
    return 0;
}
MAT producporesc(MAT b, Qi c){
    MAT a;
    int i, j;
    a.m = b.m;
    a.n = b.n;
    for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=prodQi(b.ent[i][j], c);
		}
    return a;
}