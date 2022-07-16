#include<stdio.h>
#include<stdlib.h>

#include<errno.h>
#include<string.h>

#include "Gq.h"
#include "Polinomios.h"

//Matrices
typedef struct _MatPx_{
     int m,n,e;
     Px **ent;
}MatPx;

//Funciones Matrices
MatPx iniMatPx(int m,int n);
MatPx sumaMatPx(MatPx A,MatPx B);
MatPx restaMatPx(MatPx A,MatPx B);
MatPx multMatPx(MatPx A,MatPx B);
MatPx leeMatPx(FILE *f);
int escMatPx(FILE *f,MatPx A);

int main(int argc,char argv[]){
     FILE *ent,*sal;
     char *noment="Matcoef.txt",*nomsal="resultado.txt";
     MatPx A={e:0},B={e:0},C;
     char buffer[1024];
     
     printf("Por leer el archivo %s.\n",noment);
     
     ent=fopen(noment,"rt");
     
     if(ent==NULL){
          int mi_error=errno;
          printf("Hubo un error en la lectura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n",mi_error,strerror(mi_error));
          return -1;
     }
     
     sal=fopen(nomsal,"wt");

     if (sal==NULL){
          int mi_error=errno;
          printf("Hubo un error en la escritura del archivo: %d <<%s>>\nPor finalizar la ejecucion del programa.\n",mi_error,strerror(mi_error));
          fclose(ent);
          system("pause");
          return -1;
     }
     
     printf("Por leer matriz A.\n");
     A=leeMatPx(ent);
     if (A.e==1){
          printf("\nEntrada no valida en la matriz A.\n");
          fprintf(sal,"Entrada no válida en la matriz A.\n");
          fclose(ent);
          fclose(sal);
          system("pause");
          return -3;
     }
     fprintf(sal,"La matriz A es:\n");
     escMatPx(sal,A);
     
     printf("Por leer matriz B.\n");
     B=leeMatPx(ent);
     if (B.e==1){
          printf("\nEntrada no valida en la matriz B.\n");
          fprintf(sal,"\nEntrada no válida en la matriz B.\n");
          fclose(ent);
          fclose(sal);
          system("pause");
          return -3;
     }
     fprintf(sal,"\nLa matriz B es:\n");
     escMatPx(sal,B);
     
     if (A.n!=B.n||A.m!=B.m){
          printf("No se puede efectuar ni la suma ni la resta de matrices, ya que no tienen la misma dimension.\n");
     }
     else{
          printf("Por calcular A+B.\n");
          C=sumaMatPx(A,B);
          printf("Por escribir la suma en el archivo %s\n",nomsal);
          fprintf(sal,"\nLa suma A+B es:\n");
          escMatPx(sal,C);
          
          printf("Por calcular A-B.\n");
          C=restaMatPx(A,B);
          printf("Por escribir la resta en el archivo %s\n",nomsal);
          fprintf(sal,"\nLa resta A-B es:\n");
          escMatPx(sal,C);
     }
     
     if (A.n!=B.m){
          printf("No se puede efectuar la multiplicacion de matrices (%d!=%d)\n",A.n,B.m);
     }
     else{
          printf("Por calcular AB.\n");
          C=multMatPx(A,B);
          printf("Por escribir la multiplicacion en el archivo %s\n",nomsal);
          fprintf(sal,"\nEl producto AB es\n");
          escMatPx(sal,C);
     }
     
     fclose(ent);
     fclose(sal);
     
     system("Pause");
     return 0;
}

//Funciones Matrices
MatPx iniMatPx(int m,int n){
  MatPx ret={m:m,n:n,ent:NULL};
  Px ceroPx;
  ceroPx.g=-1;
  ceroPx.c=NULL;
  int i,j;

  ret.ent=(Px **)malloc(m*sizeof(Px*));
  if(ret.ent==NULL) return ret;
  for(i=0;i<m;i++){
    ret.ent[i]=(Px*)malloc(n*sizeof(Px));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
    }
    for (j=0;j<n;j++) ret.ent[i][j]=ceroPx;
  }

  return ret;
}

MatPx sumaMatPx(MatPx A,MatPx B){
     MatPx ret={m:0,n:0,ent:NULL};
     int i,j,p;
     
     if (A.n!=B.m) return ret;
     p=A.n;
     ret=iniMatPx(A.m, B.n);
     for(i=0; i<ret.m; i++)
          for(j=0; j<ret.n; j++)
               ret.ent[i][j]=sumaPx(A.ent[i][j],B.ent[i][j]);
               
     return ret;
}

MatPx restaMatPx(MatPx A,MatPx B){
     MatPx ret={m:0,n:0,ent:NULL};
     int i,j,p;
     
     if (A.n!=B.m) return ret;
     p=A.n;
     ret=iniMatPx(A.m, B.n);
     for(i=0; i<ret.m; i++)
          for(j=0; j<ret.n; j++)
               ret.ent[i][j]=restaPx(A.ent[i][j],B.ent[i][j]);
     
     return ret;
}

MatPx multMatPx(MatPx A, MatPx B){
     MatPx ret={m:0,n:0,ent:NULL};
     int i,j,k,p;
     
     if (A.n!=B.m) return ret;
     p=A.n;
     ret=iniMatPx(A.m,B.n);
     for(i=0; i<ret.m; i++)
          for(j=0; j<ret.n; j++)
               for(k=0; k<p; k++)
                    ret.ent[i][j]=sumaPx(ret.ent[i][j],multPx(A.ent[i][k],B.ent[k][j]));
                    
     return ret;
}

MatPx leeMatPx(FILE *f){
     int m,n,i,j;
     MatPx B;
     
     fscanf(f,"%d%d",&m,&n);
     B=iniMatPx(m,n);
     for(i=0;i<m;i++)
          for(j=0;j<n;j++){
               B.ent[i][j]=leePx(f);
               if (B.ent[i][j].e==1){
                    B.e=1;
                    return B;
               }
          }
               
     return B;
}

int escMatPx(FILE *f,MatPx A){
     char buffer[1024],formato[1024];
     int i,j,lmax[A.n],aux;
     for (j=0;j<A.n;j++)
          lmax[j]=1;
     
     for(i=0;i<A.m;i++)
          for(j=0;j<A.n;j++){
               escPx(A.ent[i][j],buffer);
               aux=strlen(buffer);
               if (lmax[j]<aux) lmax[j]=aux;
          }
     
     fprintf(f,"%d %d\n\n",A.m,A.n);
     for(i=0;i<A.m;i++){
          for(j=0;j<A.n;j++){
               escPx(A.ent[i][j],buffer);
               sprintf(formato,"%%%ds  ",lmax[j]);
               fprintf(f,formato,buffer);
          }
          fprintf(f,"\n");
     }
     
     return 0;
}
