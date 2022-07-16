#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

#define MAX_COL 20
#define MAX_REN 20

typedef struct _MATA_{
	int n,m;
	int ent[MAX_REN][MAX_COL];
}MATA;

typedef struct _MATB_{
	int n,m;
	int *ent[MAX_REN];
}MATB;

typedef struct _MATC_{
	int n,m;
	int **ent;
}MATC;

int liberaB(MATB *pA);
int liberaC(MATC *pA);

MATA casoBase(MATA A);
MATB caballito(MATB b, int x, int y, int cont, MATA a);

int main(int argc, char *argv[]){
    MATA a;
	MATB b;
	MATC c;
    int x, y, cont, i, j, k, true=0;

    while(true==0){
        printf("Ingrese las coordenadas de la casilla en la que desea colocar el caballo:\n"); 
        scanf("%d%d", &x, &y);
        if((x>0 && x<9)&&(y>0 && y<9)){
            true=1;
        }else{
            printf("\nHaz ingresado una coordenada invalida.\nVuelve a intentarlo:\n");
        }
    }

    a.n = 8; a.m = 8;
    b.n = 8; b.m = 8;
    c.n = 8; c.m = 8;
    a=casoBase(a);
    b=caballito(b, x, y, 1, a);

	printf("\nEl recorrido del caballo es: \n");
	for(i=0; i<8;i++){
		for(j=0;j<8;j++){
			printf("%d\t", b.ent[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
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
MATA casoBase(MATA A){
    MATA a=A;
    a.ent[0][0]=1;a.ent[0][1]=38;a.ent[0][2]=59;a.ent[0][3]=36;a.ent[0][4]=43;a.ent[0][5]=48;a.ent[0][6]=57;a.ent[0][7]=52;
    a.ent[1][0]=60;a.ent[1][1]=35;a.ent[1][2]=2;a.ent[1][3]=49;a.ent[1][4]=58;a.ent[1][5]=51;a.ent[1][6]=44;a.ent[1][7]=47;
    a.ent[2][0]=39;a.ent[2][1]=32;a.ent[2][2]=37;a.ent[2][3]=42;a.ent[2][4]=3;a.ent[2][5]=46;a.ent[2][6]=53;a.ent[2][7]=56;
    a.ent[3][0]=34;a.ent[3][1]=61;a.ent[3][2]=40;a.ent[3][3]=27;a.ent[3][4]=50;a.ent[3][5]=55;a.ent[3][6]=4;a.ent[3][7]=45;
    a.ent[4][0]=31;a.ent[4][1]=10;a.ent[4][2]=33;a.ent[4][3]=62;a.ent[4][4]=41;a.ent[4][5]=26;a.ent[4][6]=23;a.ent[4][7]=54;
    a.ent[5][0]=18;a.ent[5][1]=63;a.ent[5][2]=28;a.ent[5][3]=11;a.ent[5][4]=24;a.ent[5][5]=21;a.ent[5][6]=14;a.ent[5][7]=5;
    a.ent[6][0]=9;a.ent[6][1]=30;a.ent[6][2]=19;a.ent[6][3]=16;a.ent[6][4]=7;a.ent[6][5]=12;a.ent[6][6]=25;a.ent[6][7]=22;
    a.ent[7][0]=64;a.ent[7][1]=17;a.ent[7][2]=8;a.ent[7][3]=29;a.ent[7][4]=20;a.ent[7][5]=15;a.ent[7][6]=6;a.ent[7][7]=13;
    return a;
}
MATB caballito(MATB b, int x, int y, int cont, MATA a){
    int aux, i, j, ax=x-1, ay=y-1, t=cont;
    aux=a.ent[ax][ay];

    if(t==64){
        b.ent[ax][ay]=64;
        return b;
    }
    if(aux==64){
        b.ent[ax][ay]=t;
        return caballito(b, 1, 1, t++, a);
    }
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(a.ent[i][j]==aux+1){
                b.ent[ax][ay]=t;
                 return caballito(b, i+1, j+1, t++, a);
            }
        }
    }
    return b;
}