#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include <math.h>
//#include "Qi"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_COL 20
#define MAX_REN 20

typedef struct _Q_{
    int num, den;
} Q;

typedef struct _Qi_{
    Q re, im;
} Qi;

typedef struct _MATA_{
	int m,n;
	Qi ent[MAX_REN][MAX_COL];
}MATA;

typedef struct _MATB_{
	int m,n;
	Qi *ent[MAX_REN];
}MATB;

typedef struct _MATC_{
	int m,n;
	Qi **ent;
}MATC;

MATA leeA(int m, int n);
MATB leeB(int m, int n);
MATC leeC(int m, int n);

int liberaB(MATB *pA);
int liberaC(MATC *pA);

int mcd(int , int );
Q simplificaQ(Q r);
Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);
int powaux(int a, int b);
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
Qi inverQi(Qi a);
Qi detA(MATA a);
MATA adj(MATA a,int ii,int jj);
//MATB igualB(MATB b);

int main(int argc, char *argv[]) {
	MATA a;
	MATB b, baux;
	MATC c, caux;
    int nb,mb,nc,mc, i, j, k, trueb=0, truec=0;
	Qi r, aux, deto, aux2, aux3;

    printf("Ingrese el numero de filas de la primer matriz"); scanf("%d", &mb);
	printf("Ingrese el numero de columnas de la primer matriz"); scanf("%d", &nb);
	printf("Ingrese el numero de filas de la primer matriz"); scanf("%d", &mc);
	printf("Ingrese el numero de columnas de la primer matriz"); scanf("%d", &nc);
	
	printf("por leer dos matrices. \n");
	b= leeB(mb,nb);
	c= leeC(mc,nc);

	printf("\nTu primera matriz es: \n");
	for(i=0; i<b.m;i++){
		for(j=0;j<b.n;j++){
			escQi(b.ent[i][j]);
		}
		printf("\n");
	}
	printf("\nTu segunda matriz es: \n");
	for(i=0; i<c.m;i++){
		for(j=0;j<c.n;j++){
			escQi(c.ent[i][j]);
		}
		printf("\n");
	}

/*
	baux=igualB(b);
    
	//caux=c;
	caux.n=c.n;
	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			caux[i][j]=c[i][j];
		}
	}*/
	if(mb!=mc || nb!=nc){
		printf("La suma y la resta no estan definidas cuando las filas o las columnas de ambas matrices no son iguales\n");
	}else{
	a.m=b.m;
	a.n=b.n;
 //suma//
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=sumaQi(b.ent[i][j],c.ent[i][j]);
		}
	printf("\nLa suma de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			escQi(a.ent[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=ceroQi(a.ent[i][j]);
		}
	}
//resta//
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=restaQi(b.ent[i][j],c.ent[i][j]);
		}
	printf("\nLa resta de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			escQi(a.ent[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=ceroQi(a.ent[i][j]);
		}
	}
	}
//inversos//
	printf("\nEl inverso de la primer matriz es: \n");
	for(i=0; i<b.m;i++){
		for(j=0;j<b.n;j++){
			escQi(restaQi(ceroQi(aux),b.ent[i][j]));
		}
		printf("\n");
	}
	printf("\nEl inverso de la segunda matriz es: \n");
	for(i=0; i<c.m;i++){
		for(j=0;j<c.n;j++){
			escQi(restaQi(ceroQi(aux),c.ent[i][j]));
		}
		printf("\n");
	}

	for(i=0; i<20;i++){
		for(j=0;j<20;j++){
			a.ent[i][j]=ceroQi(a.ent[i][j]);
		}
	}
	if(b.n!=c.m){
		printf("El producto de las matrices no está definido si las columnas de la primera no es la misma cantidad que las filas de la segunda\n");
	}else{
//producto//
	a.m=b.m;
	a.n=c.n;
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			for(k=0; k<b.m; k++){
                a.ent[i][j] = sumaQi(a.ent[i][j], prodQi(b.ent[i][k],c.ent[k][j]));
            }
		}
	printf("\nEl producto de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			escQi(a.ent[i][j]);
		}
		printf("\n");
	}
	}
//transpuesta//
	printf("\nLa transpuesta de las dos matrices son: \nPara la primera: \n");

	for(i=0; i<b.m;i++){
		for(j=0;j<b.n;j++){
			esc2Qi(b.ent[j][i]);
		}
		printf("\n");
	}

	printf("\nPara la segunda: \n");

	for(i=0; i<c.m;i++){
		for(j=0;j<c.n;j++){
			esc2Qi(c.ent[j][i]);
		}
		printf("\n");
	}
	//determinantes//
	if(b.m!=b.n){
		printf("La función determinante sólo está definida para matrices cuadradas\nEl determinante de la primer matriz no se pudo calcular\n");
	}else{
	a.m=b.m;
	a.n=b.n;
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=b.ent[i][j];
		}
	printf("\nEl determinante de la primera es: \n");
	escQi(detA(a));
	}
	if(c.m!=c.n){
		printf("La función determinante sólo está definida para matrices cuadradas\nEl determinante de la segunda matriz no se pudo calcular\n");
	}else{
	a.m=c.m;
	a.n=c.n;
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=c.ent[i][j];
		}
	printf("\nEl determinante de la segunda es: \n");
	escQi(detA(a));
	}


	//inversa (por matriz adjunta) //
    
	printf("\n");
	aux.im.num=0;
	aux.im.den=1;
	aux.re.den=1;
	a.m=b.m;
	a.n=b.n;
	for(i=0;i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=b.ent[i][j];
		}}
	if(detA(a).re.num==0 && detA(a).im.num==0){
		printf("\nLa inversa de la primera matriz no existe\n");
	}else{
		aux3=detA(a);
		printf("\nLa inversa de la primera es:\n");
		for(i=0; i<b.n; i++){
			for(j=0; j<b.n; j++){
				a.m=b.m;
				a.n=b.n;
				for(i=0;i<a.m;i++){
					for(j=0;j<a.n;j++){
						a.ent[i][j]=b.ent[i][j];
					}}
				aux.re.num=powaux(-1,i+j);
				escQi(prodQi(prodQi(aux, detA(adj(a,i,j))), inverQi(aux3)));
			}
		printf("\n");
		}
	}
	a.m=c.m;
	a.n=c.n;
	for(i=0;i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=c.ent[i][j];
		}}
	if(detA(a).re.num==0 && detA(a).im.num==0){
		printf("\nLa inversa de la segunda matriz no existe\n");
	}else{
		aux3=detA(a);
		printf("\nLa inversa de la segunda es:\n");
		for(i=0; i<c.n; i++){
			for(j=0; j<c.n; j++){
				a.m=c.m;
				a.n=c.n;
				for(i=0;i<a.m;i++){
					for(j=0;j<a.n;j++){
						a.ent[i][j]=c.ent[i][j];
					}}
				aux.re.num=powaux(-1,i+j);
				escQi(prodQi(prodQi(aux, detA(adj(a,i,j))), inverQi(aux3)));
			}
		printf("\n");
		}
	}
	
	system("pause");
	return 0;
}

MATA leeA(int m, int n){
	MATA ret;
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
			ret.ent[i][j]=leerQi(" ");
		}
	return ret;
		
}

MATB leeB(int m, int n){
	MATB ret;
	int i,j;
	
	ret.m=m;
	ret.n=n;
	
	if(ret.n<=0 || ret.m<=0){
		ret.m = ret.n = -1;
		return ret;
	}
	for (i=0;i<ret.m;i++){
		ret.ent[i] = (Qi *)malloc(ret.n*sizeof(Qi));
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
	for (i=0;i<ret.m;i++)
		for(j=0;j<ret.n;j++){
			printf("entra[%d,%d]: \n",i,j);
			ret.ent[i][j]=leerQi(" ");
		}
	return ret;
		
}

MATC leeC(int m, int n){
	MATC ret;
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
    printf("Digita num de %s: ", leyenda); scanf("%d", &(num));
    printf("Digita den de %s: ", leyenda); scanf("%d", &(den));
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
    escQ(r.re); printf(" + "); escQ(r.im); printf(" i\t");
    return 0;
}
int esc2Qi(Qi r){
    escQ(r.re); printf(" - "); escQ(r.im); printf(" i\t");
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
Qi inverQi(Qi a){
	Qi ret;
	Q norma, inver, aux;
	norma = sumaQ(prodQ(a.re,a.re),prodQ(a.im,a.im));
	aux.num=0;
	aux.den=1;
	inver = restaQ(aux,a.im);
	ret.re = divQ(a.re,norma);
	ret.im = divQ(inver, norma);
	return ret;
}
int powaux(int a, int b){
	int i, cont=1;
	for(i=0; i<b; i++){
		cont*=a;
	}
	return cont;
}
Qi detA(MATA a){
	MATA aux=a;
	Qi det, r;
	int i, j, k, n;
	n=a.n;
	det.re.num=1;
	det.re.den=1;
	det.im.num=0;
	det.im.den=1;
	for(j=0; j<n; j++){
        for(i=j+1; i<n; i++){
            r = prodQi(aux.ent[i][j], inverQi(aux.ent[j][j]));
            for(k=j;k<n;k++){
				aux.ent[i][k] = restaQi(aux.ent[i][k],prodQi(r, aux.ent[j][k]));
			}
        } 
    }
	for(i=0;i<n;i++){
		det=prodQi(aux.ent[i][i], det);
	}
return det;
}
MATA adj(MATA a,int ii,int jj){
	MATA aux=a;
	int i, j, n=a.n;
	aux.n=n-1;
	for(i=0; i<n-1;i++){
		for(j=0; j<n-1; j++){
			if(j>=jj){
				aux.ent[i][j]=a.ent[i][j+1];
			}
		}
	}
	for(i=0; i<n-1;i++){
		for(j=0; j<n-1; j++){
			if(i>=ii){
				aux.ent[i][j]=a.ent[i+1][j];
			}
		}
	}
	return aux;
}