#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_COL 20
#define MAX_REN 20

#define tam(X) printf("el tamanio de %10s es: %d\n", #X, sizeof(X))

typedef struct _MATA_{
	int m,n;
	double ent[MAX_REN][MAX_COL];
}MATA;

typedef struct _MATB_{
	int m,n;
	double *ent[MAX_REN];
}MATB;

typedef struct _MATC_{
	int m,n;
	double **ent;
}MATC;

MATA leeA(int m, int n);
MATB leeB(int m, int n);
MATC leeC(int m, int n);

int liberaB(MATB *pA);
int liberaC(MATC *pA);

int main(int argc, char *argv[]) {
	MATA a;
	MATB b;
	MATC c;
	
	tam(char);
	tam(int);
	tam(unsigned short);
	tam(signed short);
	tam(short);
	tam(double);
	tam(MATC);
	tam(MATB);
	tam(MATA);
	
	printf("por leer dos matrices. \n");
	b= leeB(2,2);
	c= leeC(2,2);
	
	int i,j,k, n, r;
	double det=1, x=1;
	
	a.m=b.m;
	a.n=b.n;
	n=a.n;
	for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			a.ent[i][j]=b.ent[i][j]+c.ent[i][j];
		}
	printf("la suma de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			printf(" %lg",a.ent[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			a.ent[i][j]=0;
		}
	}

	/*for(i=0;i<a.m;i++)
		for(j=0;j<a.n;j++){
			for(k=0; k<a.n; k++){
                a.ent[i][j] += b.ent[i][k]*c.ent[k][j];
            }
		}
	printf("\nEl producto de las dos matrices es: \n");
	
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			printf(" %lg",a.ent[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<a.m;i++){
		for(j=0;j<a.n;j++){
			if(i==j){
				a.ent[i][j]=1;
			}else{
				a.ent[i][j]=0;
			}
		}
	}*/
//Gauss//
	 for(j=1; j<=n; j++){
        for(i=1; i<=n; i++){
            if(i!=j){
                r=b.ent[i][j]/b.ent[j][j];
                for(k=1; k<=n; k++){
                    b.ent[i][k]=b.ent[i][k]-r*b.ent[j][k];
                }
            }
        }
    }

    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++){
        x = b.ent[i][n+1]/b.ent[i][i];
        printf("\n x%d=%lg\n",i,x);
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
			printf("entra[%d,%d]: ",i,j);
			scanf("%lg",&(ret.ent[i][j]));
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
		ret.ent[i] = (double *)malloc(ret.n*sizeof(double));
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
			printf("entra[%d,%d]: ",i,j);
			scanf("%lg",&(ret.ent[i][j]));
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
	
	ret.ent = (double **)malloc(ret.m*sizeof(double*));
	if(ret.ent == NULL){
		ret.m=ret.n=-1;
		return ret;
		
	}
	for (i=0;i<ret.m;i++){
		ret.ent[i] = (double *)malloc(ret.n*sizeof(double));
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
			printf("entra[%d,%d]: ",i,j);
			scanf("%lg",&(ret.ent[i][j]));
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
