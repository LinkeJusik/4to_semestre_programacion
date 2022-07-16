#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>

#define  MAX 128

typedef struct _info_ {
  char cad_1[MAX], cad_2[MAX];
  int ent_1, ent_2;
  double real;
}INFO;
//Árbol binario
typedef struct _nodo_{
  INFO info;
  struct _nodo_ *izq, *der;
}NODO;

typedef NODO *ARBOL;
//Funcionalidad.
int insertaInfo(INFO info, ARBOL *pa);
int busca(INFO info, ARBOL a);
int printA(ARBOL a, int tab);
//Recorridos con recursividad.
int preorden(ARBOL a);
int inorden(ARBOL a);
int posorden(ARBOL a);
//Auxiliares
INFO LectI(char leyenda[],INFO info);
void Menu();

int main(int argc, char *argv[]){
	Menu();
	printf("\nFIN DEL PROGRMA.\n");
	system("\npause");

  return 0;
}

int insertaI(INFO info, ARBOL *pa){
	ARBOL aux;
	NODO *pnodo;

	if(pa==NULL) return -3;
	if((pnodo=(NODO*)malloc(sizeof(NODO)))==NULL){
		int mierr = errno;
		printf("ERROR AL CREAR ESPACIO: %d,<<%s>>\n",mierr,strerror(mierr));
		return -2;
	}
	pnodo->der = pnodo->izq = NULL;
	pnodo->info = info;

	if((*pa)==NULL){
		*pa = pnodo;
		return 0;
	}
  aux = *pa;

	do {
		if(((pnodo->info.ent_1 + pnodo->info.ent_2) > (aux->info.ent_1 + aux->info.ent_2)) //suma enteros descendente y primer entero descendente
        ||(((pnodo->info.ent_1 + pnodo->info.ent_2)==(aux->info.ent_1 + aux->info.ent_2))
        &&(pnodo->info.ent_2 > aux->info.ent_2))){
			if(aux->izq == NULL){
				aux->izq = pnodo;
				break;
			}
			aux = aux->izq;
    }else if(((pnodo->info.ent_1 + pnodo->info.ent_2)==(aux->info.ent_1 + aux->info.ent_2)) //concatenar cadenas y sumar float
              &&(pnodo->info.ent_2 == aux->info.ent_2)){
      aux->info.real += pnodo->info.real;
      strcat(aux->info.cad_1,pnodo->info.cad_1);
      strcat(aux->info.cad_2,pnodo->info.cad_2);
      break;

		}else{
			if(aux->der == NULL){
				aux->der = pnodo;
				break;
			}
			aux = aux->der;
		}

	} while(aux!=NULL);

	return 0;
}
int buscaI(INFO info, ARBOL a){
	if(a==NULL) return 0;
	while(a!=NULL){
		if((a->info.ent_1 == info.ent_1)&&(a->info.ent_2 == info.ent_2)&&(a->info.real == info.real)
      &&(strcmp(a->info.cad_1,info.cad_1)==0)&&(strcmp(a->info.cad_2,info.cad_2)==0)){
        printf("\nLa INFORMACION\n\t[<<%s>> , <<%s>> , %d, %d, %lg]\nSE ENCUENTRA EN EL ARBOL.",
              a->info.cad_1, a->info.cad_2, a->info.ent_1, a->info.ent_2, a->info.real);
      return 1;
    }
		if(((info.ent_1 + info.ent_2) > (a->info.ent_1 + a->info.ent_2))
        ||(((info.ent_1 + info.ent_2)==(a->info.ent_1 + a->info.ent_2))&&(info.ent_2 > a->info.ent_2))
        ||((info.ent_1 + info.ent_2)==(a->info.ent_1 + a->info.ent_2))&&(info.ent_2 == a->info.ent_2))
      a = a->izq;
		else a = a->der;
	}
	return 0;
}
int printA(ARBOL a, int tab){
  ARBOL aux;
  int i;
  if (a==NULL) return -1;
  if (a!=NULL){
   printA(a->der,tab+2);
   for(i=0;i<tab;i++) printf("\t");
   printf("[<<%4s>> , <<%4s>> , %4d, %4d, %4lg] <\n\n",
         a->info.cad_1, a->info.cad_2, a->info.ent_1, a->info.ent_2, a->info.real);
 	printA(a->izq,tab+2);
  }
 return 0;
}
int preorden(ARBOL a){
	if(a==NULL) return 0;

	printf("[<<%s>> , <<%s>> , %d, %d, %lg] ->",
        a->info.cad_1, a->info.cad_2, a->info.ent_1, a->info.ent_2, a->info.real);
	if(a->izq!=NULL) preorden(a->izq);
	if(a->der!=NULL) preorden(a->der);

	return 0;
}
int inorden(ARBOL a){
	if(a==NULL) return 0;

	if(a->izq!=NULL) inorden(a->izq);
  printf("[<<%s>> , <<%s>> , %d, %d, %lg] ->",
        a->info.cad_1, a->info.cad_2, a->info.ent_1, a->info.ent_2, a->info.real);
	if(a->der!=NULL) inorden(a->der);

	return 0;
}
int posorden(ARBOL a){
	if(a==NULL) return 0;

	if(a->izq!=NULL) posorden(a->izq);
	if(a->der!=NULL) posorden(a->der);
  printf("[<<%s>> , <<%s>> , %d, %d, %lg] ->",
        a->info.cad_1, a->info.cad_2, a->info.ent_1, a->info.ent_2, a->info.real);

	return 0;
}
INFO LectI(char leyenda[],INFO info){
  int rspt=2;
  char aux[MAX];

  while(rspt==2){
    printf("\n\tINGRESE LA INFORMACION A %s\n\n"
      "\tIngrese una cadena de caracteres (primer cadena):  ", leyenda); gets(aux); gets(info.cad_1);
    printf("\tIngrese otra cadena de caracteres (segunda cadena): "); gets(info.cad_2);
    printf("\n\tIngrese un numero entero (primer entero):  "); scanf("%d",&info.ent_1);
    printf("\tIngrese otro numero entero (segundo entero): "); scanf("%d",&info.ent_2);
    printf("\n\tIngrese un real: "); scanf("%lg",&info.real);
    printf("\n\tLa informacion ingresada es: [<<%3s>>, <<%3s>>, %3d, %3d, %3lg]"
     "\n\tLa informacion es correcta: ",info.cad_1,info.cad_2,info.ent_1,info.ent_2,info.real);
    scanf("%d",&rspt);
    if(rspt!=1 && rspt!=2) exit(0);
  }
  return info;
}
void Menu(){
  int opcion=0;
  INFO info;
  ARBOL arbol=NULL;

  do{
    printf("OPCIONES AFIRMATIVAS Y NEGATIVAS\n1.-Si\n2.-No\n"
            "\n\n1.-Insertar informacion.\n2.-Buscar infomracion."
            "\n3.-Mostrar recorrido preorden.\n4.-Mostrar recorrido inorden."
            "\n5.-Mostrar recorrido posorden.\n6.-Imprimir Arbol.\n7.-Salir"
            "\n\nIngrese la opcion a realizar: "); scanf("%d",&opcion);


    switch (opcion){
      case 1:info=LectI("INSERTAR", info);
              insertaI(info, &arbol);
              printf("\n");
              system("\npause");
              break;
      case 2: info=LectI("BUSCAR", info);
              buscaI(info, arbol);
              printf("\n");
              system("\npause");
              break;
      case 3: printf("\nRECORRIDO PREORDEN\n\n");
              preorden(arbol);
              printf("\n");
              system("\npause");
              break;
      case 4: printf("\nRECORRIDO INORDEN\n\n");
              inorden(arbol);
              printf("\n");
              system("\npause");
              break;
      case 5: printf("\nRECORRIDO POSORDEN\n\n");
              posorden(arbol);
              printf("\n");
              system("\npause");
              break;
      case 6: printA(arbol,0);
              printf("\n");
              system("\npause");
              break;
      case 7: break;
      default: printf("ESA OPCION NO EXISTE MI LOKO");
               exit(0);
               break;
    }
    system("\ncls");
  }while(opcion!=7);
  return;
}
