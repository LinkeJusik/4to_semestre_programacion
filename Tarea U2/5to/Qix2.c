#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
//#include "Qi"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define TAM_MAX 20

typedef struct _Q_{
    int num, den;
} Q;

typedef struct _Qi_{
    Q re, im;
} Qi;

typedef struct _Vec_{
	int n;
	Qi ent[TAM_MAX];
}Vec;

Vec leeVec(Vec ret, int n);
int imprimirVec(Vec a);
int imprimirDerVec(Vec a);
int imprimirIntVec(Vec a);

int liberaVec(Vec *pA);

int mcd(int , int );
Q simplificaQ(Q r);
Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);

int escQ(Q r);
Q asignaQ(int num, int den);
Q leeQ(char leyenda[]);

int escQi(Qi r);
int esc2Qi(Qi r);
Qi asignaQi(Q re, Q im);
Qi leerQi(char leyenda[]);
Qi sumaQi(Qi a, Qi b);
Qi restaQi(Qi a, Qi b);
Qi prodQi(Qi a, Qi b);
Qi ceroQi(Qi a);
Qi powQi(Qi a, int n);

int main(int argc, char *argv[]) {
	Vec a, b, res, prod;
    int i, j, k, n1, n2;
    Qi complex, aux;
    for(i=0;i<TAM_MAX;i++){
        a.ent[i]=ceroQi(a.ent[i]);
        b.ent[i]=ceroQi(b.ent[i]);
        res.ent[i]=ceroQi(res.ent[i]);
        prod.ent[i]=ceroQi(res.ent[i]);
    }
    printf("Ingrese el grado del primer polinomio"); scanf("%d", &n1);
	printf("Por leer los coeficientes del primer polinomio \n");
	a = leeVec(a, n1);
    printf("El primer polinomio es:\n");
    imprimirVec(a);
	printf("\nIngrese el grado del segundo polinomio"); scanf("%d", &n2);
	printf("Por leer los coeficientes del segundo polinomio \n");
	b = leeVec(b, n2);
    printf("El segundo polinomio es:\n");
    imprimirVec(b);
	
    printf("\nIngrese el número complejo en el que quisiera evaluar los polinomios: \n");
    complex=leerQi(" ");
    aux=ceroQi(aux);

    if(n1>=n2){
        res.n = n1;
    }else{
        res.n = n2;
    }
    prod.n = n1+n2;

 //suma//
    if(n1>=n2){
        res.n = n1;
    }else{
        res.n = n2;
    }
    for(i=0;i<=res.n;i++){
		res.ent[i] = sumaQi(a.ent[i], b.ent[i]);
    }
	printf("\nLa suma de los dos polinomios es: \n");
    imprimirVec(res);

    for(i=0;i<TAM_MAX;i++){
        res.ent[i]=ceroQi(res.ent[i]);
    }
//resta//
	for(i=0;i<=res.n;i++){
		res.ent[i] = restaQi(a.ent[i], b.ent[i]);
    }
	printf("\nLa resta de los dos polinomios es: \n");
    imprimirVec(res);

    for(i=0;i<TAM_MAX;i++){
        prod.ent[i]=ceroQi(prod.ent[i]);
    }
//producto//
	for(i=0;i<=b.n;i++){
		for(j=0;j<=a.n;j++){
            prod.ent[i+j] = sumaQi(prodQi(a.ent[j], b.ent[i]), prod.ent[i+j]);
		}
    }
	printf("\nEl producto de los polinomios son: \n");
	imprimirVec(prod);

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

//Inversos//

    printf("\nEl inverso aditivo del primero es: \n");
    for(i=0;i<=a.n;i++){
		res.ent[i] = restaQi(ceroQi(aux), a.ent[i]);
    }
    imprimirVec(res);
    printf("\nEl inverso aditivo del segundo es: \n");
    for(i=0;i<=b.n;i++){
		res.ent[i] = restaQi(ceroQi(aux), b.ent[i]);
    }
    imprimirVec(res);

//Evaluación//
    for(i=n1; i>=0; i--){
        aux=sumaQi(prodQi(powQi(complex,i),a.ent[i]),aux);
    }
    printf("\nLa evaluación del primer polinomio es: \n");
    escQi(aux);
    aux=ceroQi(aux);
    for(i=n2; i>=0; i--){
        aux=sumaQi(prodQi(powQi(complex,i),b.ent[i]),aux);
    }
    printf("\nLa evaluación del segundo polinomio es: \n");  
    escQi(aux);
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
            printf("\t(");
		    escQi(prodQi(ret.ent[i], com));
            printf(")\tx^%d\t",i-1);
            }else{
            com.re.num=i;
            printf("+\t(");
		    escQi(prodQi(ret.ent[i], com));
            printf(")\tx^%d\t",i-1);
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
        printf("\t(");
	    escQi(prodQi(ret.ent[i], com));
        printf(")\tx^%d\t",i+1);
        }else{
        com.re.den=i+1;
        printf("+\t(");
	    escQi(prodQi(ret.ent[i], com));
        printf(")\tx^%d\t",i+1);
        }
    }
    printf("+\tC");
    return 0;
}
int mcd(int a, int b){
    int r;
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(b==0 && a!=0) return a;
    if(a==0 && b!=0) return b;
    if(a==0 && b==0) return 1;
    
    while((r=a%b) != 0){
        a=b;
        b=r;
    }
    return b;
}
Q simplificaQ(Q r){
    int d;
    d=mcd(r.den, r.num);
    r.den/=d;
    r.num/=d;
    if(r.den<0){
        r.num=-r.num;
        r.den=-r.den;
    }
    return r;
}
Q sumaQ(Q a, Q b){
    Q r = {num:a.num*b.den+a.den*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q restaQ(Q a, Q b){
    Q r = {num:a.num*b.den-a.den*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q prodQ(Q a, Q b){
    Q r = {num:a.num*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q divQ(Q a, Q b){
    Q r = {num:a.num*b.den, den:a.den*b.num};
    return simplificaQ(r);
}

int escQ(Q r){
    printf("%d", r.num);
    if(r.den>1) printf("/%d", r.den);
    printf(" ");
    return 0;
}

Q asignaQ(int num, int den){
    Q r ={num, den};
    return simplificaQ(r);
}

Q leeQ(char leyenda[]){
    int num, den;
    printf("\nDigita num de %s: ", leyenda); scanf("%d", &(num));
    printf("\nDigita den de %s: ", leyenda); scanf("%d", &(den));
    return asignaQ(num, den);
}

Qi ceroQi(Qi a){
	a.im.num=0;
    a.im.den=1;
	a.re.num=0;
    a.re.den=1;
	return a;
}

int escQi(Qi r){
    escQ(r.re); printf(" + "); escQ(r.im); printf(" i");
    return 0;
}
int esc2Qi(Qi r){
    escQ(r.re); printf(" - "); escQ(r.im); printf(" i");
    return 0;
}
Qi asignaQi(Q re, Q im){
    Qi ret;
    ret.re = re;
    ret.im = im;
    return ret;
}
Qi leerQi(char leyenda[]){
    Qi ret;
    printf("parte real. ");
    ret.re = leeQ(leyenda);
    printf("parte imaginaria. ");
    ret.im = leeQ(leyenda);
    return ret;
}
Qi sumaQi(Qi a, Qi b){
    Qi ret;
    ret.re = sumaQ(a.re, b.re);
    ret.im = sumaQ(a.im, b.im);
    return ret;
}
Qi restaQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(a.re, b.re);
    ret.im = restaQ(a.im, b.im);
    return ret;
}
Qi prodQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(prodQ(a.re,b.re), prodQ(a.im, b.im));
    ret.im = sumaQ(prodQ(a.re, b.im), prodQ(a.im, b.re));
	return ret;
}
Qi powQi(Qi a,int n){
    int i;
    Qi aux;
    aux.re.den=1;
    aux.re.num=1;
    aux.im.num=0;
    aux.im.den=1;
    for(i=0; i<n; i++){
        aux=prodQi(aux,a);
    }
    return aux;
}