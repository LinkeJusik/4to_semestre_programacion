#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>

typedef struct _mi_info_{
	char cadena [1024];
	int entero;
	double real;
}INFO;

typedef struct _elm_cola_{
	INFO info;
	struct _elem_cola_ *sig;
} ElemCola;

typedef struct _cola_{
	ElemCola *ini, *fin;
}COLA;


int agregar(char cadena[], int entero, double real, COLA *pc); //apuntador a la cola
int sacar(char cadena[], int *pe, double *pr, COLA *pc); //en arreglo no se necesita apuntador. En C los parámetros se pasan por valor
int imprimirC(COLA cola);
int vaciarC(COLA *pcola);

int main(int argc, char *argv[]){
	COLA c;
	int a, i, k=0, aux, error;
	double b;
	char cad[128];
		
	c.ini=NULL; //iniciando
	printf("Programa de una cola\n");
	while(k==0){
		printf("Digite el número asociado a una de las siguientes opciones:\n");
		printf("1. Insertar elemento a la lista\n2. Eliminar elemento de la lista\n3. Ver la lista\n4. Limpiar pantalla\n5. Salir\n"); scanf("%d",&aux);
		switch(aux){
			case 1:
				printf("Digite la cadena: "); scanf("%s", &cad);
				printf("Digite el entero: "); scanf("%d", &a);
				printf("Digite el real:"); scanf("%lg", &b);
				agregar(cad, a, b, &c);
				break;
			case 2:
				error = sacar(cad, &a, &b, &c); //sacar 4 elementos
				switch(error){
					case -2: printf("Punteros de datos vaciops");
					case -1: printf("inicio cola vacia");
				}
				printf("Info obtenida: %d, %lg, <<%s>>.\n", a, b, cad);
				break;
			case 3:
				imprimirC(c);
				break;
			case 4: 
				system("cls");
				break;
			case 5: 
				k=1;
				break;
			default: printf("Opcion invalida.\n");
		        break;
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

//Funciones
//-----------------------------------------------------------------------------------------------
int agregar(char cadena[], int entero, double real, COLA *pc){
	ElemCola *pelem;
	if(pc==NULL) return -2;
	if((pelem=(ElemCola*)malloc(sizeof(ElemCola)))==NULL){
		int mierr=errno;
		printf("Error al reservar el espacio: %d, <%s>\n", mierr, strerror(mierr));
		return -1;
	
	}
	pelem->info.entero=entero;
	pelem->info.real=real;
	strncpy(pelem->info.cadena, cadena, sizeof(pelem->info.cadena)); //copia
	pelem->sig=NULL; //
		
	//ver si la cola está vacía
	if(pc->ini==NULL){
		pc->ini=pc->fin=pelem; //al inicio y al fin se le da la misma dir de mem
		return 0;
	}
	
	//el criterio es siempre el final. Sí hay algo en la lista
	pc->fin->sig=pelem; //el elemento que se acaba de crear es el que se va a poner al final 
	pc->fin=pelem; //actualizar el primero?
	
	return 0;
}
//----------------------------------------------------------------------------------------
int sacar(char cadena[], int *pe, double *pr, COLA *pc){
	ElemCola *pelem;
	
	//si el primero elemento fuera nulo
	if(pc==NULL || pe==NULL || pr==NULL) return -2;
	//si la cola está vacía
	if(pc->ini==NULL){
		return -1;
	}
	//si la cola no está vacía, eliminar al primer elemento
	pelem=pc->ini;
	pc->ini=pc->ini->sig;
	printf("Elemento eliminado\n");
	
	*pe=pelem->info.entero;
	*pr=pelem->info.real;
	strncpy(cadena, pelem->info.cadena, 128); //copia //sizeof(pelem->info.cadena)
	
	pelem->info.entero=0;
	pelem->info.real=0.0;
	memset(pelem->info.cadena, 0, sizeof(pelem->info.cadena)); //limpiar el arreglo con 0s
	pelem->sig=NULL;
	
	free(pelem);
	pelem=NULL;
	
	return 0; 
}
//----------------------------------------------------------------------------------------
int imprimirC(COLA cola){
	ElemCola *aux;
	int i; // contador
	if(cola.ini==NULL){
		printf("(vacía)\n");
		return 0;
	}
	//si no está vacía, recorrerla
	aux=cola.ini;
	// imprimir y enumerar los elementos
	for(i=1; aux!=NULL; i++, aux=aux->sig){ //actualizar también aux, hasta que eventualmente llegue a nulo
		printf("%3d) %d, %lg, <<%s>>\n", i, aux->info.entero, aux->info.real, aux->info.cadena);
	}
	printf("\n");
	return 0;
}
//------------------------------------------------------------------------------------------
int vaciarC(COLA *pcola){
	ElemCola *aux, *limpiar;
	if(pcola==NULL) return -2; //darle interpretación al error
	if(pcola->ini==NULL) return 0;
	
	aux=pcola->ini;
	while(aux!=NULL){
		limpiar=aux;
		aux=aux->sig; 
		limpiar->info.entero=0;
		limpiar->info.real=0.0;
		memset(limpiar->info.cadena, 0, sizeof(limpiar->info.cadena));
		limpiar->sig=NULL;
		free(limpiar);
	
	}
	//limpiar=NULL;
	pcola->ini=pcola->fin=NULL;
	return 0; //
}