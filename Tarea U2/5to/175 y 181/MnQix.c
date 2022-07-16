#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define TAM_MAX 20
#include "Qi.h"
#include "Q.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_COL 20
#define MAX_REN 20

typedef struct _Vec_{
	int n;
	Qi ent[TAM_MAX];
}Vec;

typedef struct _MATA_{
	int m,n;
	Vec ent[MAX_REN][MAX_COL];
}MATA;

typedef struct _MATB_{
	int m,n;
	Vec *ent[MAX_REN];
}MATB;

typedef struct _MATC_{
	int m,n;
	Vec **ent;
}MATC;

Vec leeVec(Vec ret, int n);
int imprimirVec(Vec a);
int imprimirDerVec(Vec a);
int imprimirIntVec(Vec a);

MATA leeA(int m, int n);
MATB leeB(int m, int n);
MATC leeC(int m, int n);

int liberaB(MATB *pA);
int liberaC(MATC *pA);

Vec sumavec(Vec a, Vec b);
Vec restavec(Vec a, Vec b);
Vec prodvec(Vec a, Vec b);
int imprimir2Vec(Vec a);

int main(int argc, char *argv[]) {
	MATA a;
	MATB b, baux;
	MATC c, caux;
    int n, i, j, k;
	Qi r, aux, deto, aux2;

    printf("Ingrese el numero de renglones de la matriz"); scanf("%d", &n);
	
	printf("Por leer dos matrices. \n");
	b= leeB(n,n);
	c= leeC(n,n);

	a.m=b.m;
	a.n=b.n;

	printf("\nTu primera matriz es: \n");
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimirVec(b.ent[i][j]);
		}
		printf("\n");
	}
	
	printf("\nTu segunda matriz es: \n");
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimirVec(c.ent[i][j]);
		}
		printf("\n");
	}

 //suma//
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=sumavec(b.ent[i][j],c.ent[i][j]);
		}
	printf("\nLa suma de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimirVec(sumavec(b.ent[i][j],c.ent[i][j]));
		}
		printf("\n");
	}

//resta//
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=restavec(b.ent[i][j],c.ent[i][j]);
		}
	printf("\nLa resta de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimirVec(a.ent[i][j]);
		}
		printf("\n");
	}

//producto//
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			for(k=0; k<a.n; k++){
                a.ent[i][j] = sumavec(a.ent[i][j], prodvec(b.ent[i][k],c.ent[k][j]));
            }
		}
	printf("\nEl producto de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimirVec(a.ent[i][j]);
		}
		printf("\n");
	}

//transpuesta//
	printf("\nLa transpuesta de las dos matrices son: \nPara la primera: \n");

	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimir2Vec(b.ent[j][i]);
		}
		printf("\n");
	}

	printf("\nPara la segunda: \n");

	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			imprimir2Vec(c.ent[j][i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

MATA leeA(int m, int n){
	MATA ret;
    Vec a;
	ret.m=m;
	ret.n=n;
	
	int i,j;
	
	if(ret.n<=0 || ret.m<=0){
		ret.m = ret.n = -1;
		return ret;
	}
	printf("digite las entradas de la matriz: \n");
	for (i=0;i<ret.m;i++)
		for(j=0;j<ret.n;j++){
			printf("entra[%d,%d]: \n",i,j);
			ret.ent[i][j]=leeVec(a, n);
		}
	return ret;
		
}

MATB leeB(int m, int n){
	MATB ret;
    Vec a;
	int i,j;
	
	ret.m=m;
	ret.n=n;
	
	if(ret.n<=0 || ret.m<=0){
		ret.m = ret.n = -1;
		return ret;
	}
	for (i=0;i<ret.m;i++){
		ret.ent[i] = (Vec *)malloc(ret.n*sizeof(Vec));
		if(ret.ent[i] == NULL){
			while(i>0){
				free(ret.ent[--i]);
				ret.ent[i]=NULL;
			}
			ret.m=ret.n=-1;
			return ret;
		}
	}
	printf("digite las entradas de la matriz: \n");
	for (i=0;i<ret.m;i++){
		for(j=0;j<ret.n;j++){
			printf("entra[%d,%d]: \n",i,j);
	        printf("Por leer los coeficientes del primer polinomio el primer polinomio. \n");
			ret.ent[i][j]=leeVec(a, ret.n);
		}
    }
	return ret;
}

MATC leeC(int m, int n){
	MATC ret;
    Vec a;
	int i,j, n1;
	
	ret.m=m;
	ret.n=n;
	
	if(ret.n<=0 || ret.m<=0){
		ret.m = ret.n = -1;
		return ret;
	}
	
	ret.ent = (Vec **)malloc(ret.m*sizeof(Vec*));
	if(ret.ent == NULL){
		ret.m=ret.n=-1;
		return ret;
		
	}
	for (i=0;i<ret.m;i++){
		ret.ent[i] = (Vec *)malloc(ret.n*sizeof(Vec));
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
	for (i=0;i<ret.m;i++){
		for(j=0;j<ret.n;j++){
			printf("entra[%d,%d]: \n",i,j);
	        printf("Por leer los coeficientes del polinomio \n");
			ret.ent[i][j]=leeVec(a, ret.n);
		}
    }
	return ret;
}

int liberaB(MATB *pA){
	int i;
	
	if((*pA).m<=0||pA->n<=0) return-1;
	for(i=0;i<pA->m;i++){
		free(pA->ent[i]);
		pA->ent[i]=NULL;
	}
	(*pA).m=pA->n=-1;
	return 0;
}
int liberaC(MATC *pA){
	int i;
	
	if((*pA).m<=0||pA->n<=0) return-1;
	for(i=0;i<pA->m;i++){
		free(pA->ent[i]);
		pA->ent[i]=NULL;
	}
	(*pA).m=pA->n=-1;
	return 0;
}
Vec leeVec(Vec ret, int n){
	ret.n=n;
	int i;
    for(i=0;i<TAM_MAX;i++){
        ret.ent[i]=ceroQi(ret.ent[i]);
    }
	printf("Digite las entradas del vector: \n");
	for(i=ret.n; i>=0; i--){
		printf("x^%d: \n",i);
		ret.ent[i]=leerQi(" ");
    }
	return ret;
}
int imprimirVec(Vec a){
    Vec ret = a;
    int i;
	for(i=ret.n; i>=0; i--){
        if(i==ret.n){
            printf("\t(");
		escQi(ret.ent[i]);
        printf(")\tx^%d\t",i);
        }else{
            printf("+\t(");
		escQi(ret.ent[i]);
        printf(")\tx^%d\t",i);
        }
	}
    return 0;
}
int imprimir2Vec(Vec a){
    Vec ret = a;
    int i;
	for(i=ret.n; i>=0; i--){
        if(i==ret.n){
            printf("\t(");
		esc2Qi(ret.ent[i]);
        printf(")\tx^%d\t",i);
        }else{
            printf("+\t(");
		esc2Qi(ret.ent[i]);
        printf(")\tx^%d\t",i);
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
            com.re.num=i;
            printf("+\t(");
		    escQi(prodQi(ret.ent[i], com));
            printf(")\tx^%d\t",i-1);
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
        com.re.den=i+1;
        printf("+\t(");
	    escQi(prodQi(ret.ent[i], com));
        printf(")\tx^%d\t",i+1);
    }
    printf("+\tC");
    return 0;
}

Vec sumavec(Vec a, Vec b){
    int i;
    Vec res;
    for(i=0;i<TAM_MAX;i++){
        res.ent[i]=ceroQi(res.ent[i]);
    }
    if(a.n>=b.n){
        res.n = a.n;
    }else{
        res.n = b.n;
    }
    for(i=0;i<=res.n;i++){
		res.ent[i] = sumaQi(a.ent[i], b.ent[i]);
    }
    return res;
}
Vec restavec(Vec a, Vec b){
    int i;
    Vec res;
    for(i=0;i<TAM_MAX;i++){
        res.ent[i]=ceroQi(res.ent[i]);
    }
    if(a.n>=b.n){
        res.n = a.n;
    }else{
        res.n = b.n;
    }
    for(i=0;i<=res.n;i++){
		res.ent[i] = restaQi(a.ent[i], b.ent[i]);
    }
    return res;
}
Vec prodvec(Vec a, Vec b){
    int i, j;
    Vec prod;
    for(i=0;i<TAM_MAX;i++){
        prod.ent[i]=ceroQi(prod.ent[i]);
    }
    prod.n = a.n+b.n;
    for(i=0;i<=b.n;i++){
		for(j=0;j<=a.n;j++){
            prod.ent[i+j] = sumaQi(prodQi(a.ent[j], b.ent[i]), prod.ent[i+j]);
		}
    }
    return prod;
}