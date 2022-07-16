#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>

typedef struct _info_{
    char cadena1[1024], cadena2[1024];
	int entero1, entero2;
	double real;
}INFO;

typedef struct _elemento_lista_{
    INFO info;
    struct _elemento_lista_ *sig;
    struct _elemento_lista_ *ant;

}ELE;


typedef ELE *LISTA;
int eliminar(INFO info, LISTA *pl);
int vaciar(LISTA *pl);
int mostrar(LISTA l);
int insertar(INFO info, LISTA *pl);
int recorrer(LISTA l);

int main(int argc, char *argv[]){
	LISTA l=NULL;
	
	int i, n, aux,k=0;
	INFO info;
	
	while(k==0){
		printf("Digite el número asociado a una de las siguientes opciones:\n");
		printf("1. Insertar elemento a la lista\n2. Eliminar elemento de la lista\n3. Ver la lista\n4. Recorrer la lista\n5. Limpiar pantalla\n6. Salir\n"); scanf("%d",&aux);

		switch (aux){
			case 1: 
				printf("Ingrese los siguientes datos:\n");
	            printf("Digite la primer cadena: "); scanf("%s", &(info.cadena1));
		        printf("Digite la segunda cadena: "); scanf("%s", &(info.cadena2));
		        printf("Digite el primer entero: "); scanf("%d", &(info.entero1));
		        printf("Digite el segundo entero: "); scanf("%d", &(info.entero2));
		        printf("Digite el real:"); scanf("%lg", &(info.real));
		        insertar(info, &l); 
	            break;
		case 2: printf("\nElemento a eliminar: \n");
		    	printf("\nDigite la primer cadena:"); scanf("%s", &(info.cadena1));
		        printf("\nDigite la segunda cadena:"); scanf("%s", &(info.cadena2));
		        printf("\nDigite el primer entero: "); scanf("%d", &(info.entero1));
		        printf("\nDigite el segundo entero: "); scanf("%d", &(info.entero2));
		        printf("\nDigite el real:"); scanf("%lg", &(info.real));
	            printf(" %s \n", eliminar(info, &l)==0?"Se encontro informacion a eliminar.":"No se encontro informacion a eliminar.");
	
		        break;
		case 3: mostrar(l);
		        break;
        case 4: recorrer(l);
                break;
		case 5: system("cls");
				break;
		case 6: k=1;
		default: printf("Opcion invalida.\n");
		        break;
		}
		printf("\n");
	}
	return 0;
}

int insertar(INFO info, LISTA *pl){
	ELE *pel;
	LISTA l;
	
	if(pl==NULL){
		printf("Error,La lista no puede ser nula. \n");
	}
	pel=(ELE*)malloc(sizeof(ELE));
	if((pel=(ELE*)malloc(sizeof(ELE)))==NULL){
		int mierr=errno;
		printf("Error de espacio en memoria: %d <<%s>>\n", mierr, strerror(mierr));
		return -1;
	}
	pel->info=info;
	pel->sig=NULL;
    pel->ant=NULL;
	

	if(*pl==NULL){
		*pl=pel; 
		return 0;
	}
	

	if(pel->info.entero1>(*pl)->info.entero1){
		pel->sig=*pl; 
        (*pl)->ant=pel;
		*pl=pel;
		return 0;
	}
	

	if(pel->info.entero1==(*pl)->info.entero1){
	    if(pel->info.entero2<(*pl)->info.entero2){
	    	pel->sig=*pl;
            (*pl)->ant=pel;
	    	*pl=pel;
	    	return 0;
	    }

	    if(pel->info.entero2==(*pl)->info.entero2){
	    	(*pl)->info.real+=pel->info.real;
			strcat((*pl)->info.cadena1, pel->info.cadena1);
			strcat((*pl)->info.cadena2, pel->info.cadena2);
			return 0;
		}
    }
	l=*pl;

	while(l->sig!=NULL){
		if(pel->info.entero1>l->sig->info.entero1){
			pel->sig=l->sig;
			l->sig=pel;
            pel->ant=l;
			return 0;
		} 
	
		if(pel->info.entero1==l->sig->info.entero1){ 
			if(pel->info.entero2==(*pl)->info.entero2){
	    	    l->sig->info.real+=pel->info.real;
			    strcat(l->sig->info.cadena1, pel->info.cadena1);
			    strcat(l->sig->info.cadena2, pel->info.cadena2);
			    return 0;
		    }
		}
		l=l->sig;
	}
	l->sig=pel;
    pel->ant=l;
	return 0;
}

int eliminar(INFO info, LISTA *pl){
	ELE *pel;
	LISTA l;
	
	if(pl==NULL) return -1;
	if(*pl==NULL) return -2;
	if((*pl)->info.entero1==info.entero1 && (*pl)->info.entero2==info.entero2 && (*pl)->info.real==info.real && strncmp((*pl)->info.cadena1, info.cadena1, 128)==0 && strncmp((*pl)->info.cadena2, info.cadena2, 128)==0){
		pel=*pl;

		printf("La siguiente informacion se borrara: \n");
		mostrar(pel); 
		
		*pl=(*pl)->sig; 

		pel->sig=NULL;
		pel->info.entero1=0;
		pel->info.entero2=0;
		pel->info.real=0.0;
		memset(pel->info.cadena1, 0, sizeof(pel->info.cadena1)); 
		memset(pel->info.cadena2, 0, sizeof(pel->info.cadena2)); 

		free(pel);
		pel=NULL;
		return 0;
	}

	l=*pl;
	while(l->sig!=NULL){
		if(l->sig->info.entero1==info.entero1 && l->sig->info.entero2==info.entero2 && l->sig->info.real==info.real && strncmp(l->sig->info.cadena1, info.cadena1, 128)==0 && strncmp(l->sig->info.cadena2, info.cadena2, 128)==0){
			pel=l->sig;
			l->sig=pel->sig; 
		    pel->sig=NULL;
		    pel->info.entero1=0;
		    pel->info.entero2=0;
		    pel->info.real=0.0;
		    memset(pel->info.cadena1, 0, sizeof(pel->info.cadena1)); 
		    memset(pel->info.cadena2, 0, sizeof(pel->info.cadena2)); 

		    free(pel);
		    pel=NULL;
		    return 0;
		}
		l=l->sig; 
	}
	
	return 0;
}
int mostrar(LISTA l){
	int i=1;
	if(l==NULL){
	printf("(vacia)\n");
	return 0;
	}
	while(l!=NULL){
		printf("%3d. [%3d, %3d, %3lg, %s, %s]\n", i, l->info.entero1, l->info.entero2, l->info.real, l->info.cadena1, l->info.cadena2);
		l=l->sig;
		i++;
	}
	return 0;
}
int vaciar(LISTA *pl){
	LISTA l;
	ELE *pel;
	
	if(pl==NULL) return -1;
	l=*pl;
	while(l!=NULL){
		pel=l;
		l=l->sig;

		pel->sig=NULL;
		pel->info.entero1=0;
		pel->info.entero2=0;
		pel->info.real=0.0;
		memset(pel->info.cadena1, 0, sizeof(pel->info.cadena1));
		memset(pel->info.cadena2, 0, sizeof(pel->info.cadena2)); 

		free(pel);
		pel=NULL;
	}
	*pl=NULL;
	return 0;	
}
int recorrer(LISTA l){
	int a, b=0, i=1;
	if(l==NULL){
	printf("(vacia)\n");
	return 0;
	}
    while(b==0){
    printf("Actualmente estás en:\n%3d. [%3d, %3d, %3lg, %s, %s]", i, l->info.entero1, l->info.entero2, l->info.real, l->info.cadena1, l->info.cadena2);
	printf("¿Hacia donde deseas moverte?\n1. Adelante\n2. Atras\n3. Dejar de recorrer\n"); scanf("%d", &a);
    switch(a){
        case 1:
        l=l->sig;
        i++;
        if(l==NULL){
            printf("Te haz salido de la lista\n");
            return 0;
        }
        break;
        case 2: 
        l=l->ant;
        i--;
        if(l==NULL){
            printf("Te haz salido de la lista\n");
            return 0;
        }
        break;
        case 3:
        b=1;
        break;

    }
    }
	return 0;
}