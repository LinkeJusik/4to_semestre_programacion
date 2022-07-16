#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <string.h>

typedef struct _elm_lista_{
	int info;
	struct _elem_lista_ *sig;
} EL; //estructura que tiene dos campos: un entero y un identificador al sig elem

typedef EL *LISTA; //una lista es una refrerencia a un elemento de la lista

int insertar(int info, LISTA *pl); //parametros: información y referencia a la lisa //en C los valores se pasan por valor y no por referencia
int buscar (int info, LISTA l); //no se necesita apuntador porque no se va a alterar la lista; l es apuntador a un elemento de la lista?
int eliminar (int info, LISTA *pl);
int vaciar (LISTA *pl);
int imprimir (LISTA l);


int main(int argc, char *argv[]){
	LISTA l=NULL;
	int n, info, i;
	
	printf("Ejemplo de lista.\nDigite un entero: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		imprimir(l);
		printf("%2d) Digite un entero; ", i);
		scanf("%d", &info);
		insertar(info, &l);
	}
	
	printf("Info a eliminar: ");
	scanf("%d", &info);
	printf("Se encontró información a eliminar; %s.\n", eliminar(info, &l)==1?"sí": "no");
	imprimir(l);
	vaciar(&l);
	imprimir(l);
    
    printf("Fin del programa.\n");
	//en eliminar es 0 si no se había encontrado, y 1 si sí se había encontrado
	
	return 0;
}
//--------------------------------------------------------------------------------------------------------------
int insertar(int info, LISTA *pl){
	EL *pel;
	LISTA l;
	//si me dan como referencial nulo
	if(pl==NULL){
		printf("Error, la referencia a la lista no puede ser nula.\n");
		return -2; //?
	}
	if((pel=(EL*)malloc(sizeof(EL)))==NULL){
		int mierr= errno;
		printf("Error de espacio en memoria: %d <<%s>>\n", mierr, strerror(mierr));
		return -1;
	}
	//si la lista
	pel->info=info;
	pel->sig=NULL;
	if(*pl==NULL){
		*pl=pel;
		return 0;
	}
	//debemos contar con un criterio para insertar información: al inicio, al final...
	//criterio: de mayor a menor
	//ver si el elemento wue se quirere insertar debe ir antes del primier elemento de la lista
	if(pel->info>=(*pl)->info){//si el contenido de pl es mayor o igual que el primie elemento
		pel->sig=pl; //pel->sig=*pl;
		*pl=pel;
		return 0;
	}
	//si no, hay que recorrer la lista para ver dónde debería ir
	l=*pl;
	while(l->sig!=NULL){
		if(pel->info>=l->sig->info){ //de acuerdo a nuestro criterio de inserción
			pel->sig=l->sig;
			l->sig=pel;
			return 0;
		} //si no se cumple ese criterio para insertar hay que continuar
		l=l->sig;
	}
	//si no se pudo insertar allá, se inserta al final?
	l->si=pel;
	return 0;
	
} 

//-------------------------------------------------------------------------------------------------------
int buscar (int info, LISTA l){
	int ret=0;
	
	while(l!=NULL){ //criterio de mayor a menor, así lo tenemos?
	   if(info>l->info) return ret;
	   if(info==l->info) ret++; //buscamos repeticiones
	   l=l->sig;
	}
	return ret;
} 
//--------------------------------------------------------------------------------------------------------
int eliminar (int info, LISTA *pl){
	//si el que hay que eliminar es el primir, apartarlo: pomer una referencia
	//si no, identificar cual debería ser
	//debe haber manera de tomar la refrencia del que se quiere elliminar y el anterior debe apuntar al siguiente de ese, para luego eliminar
	//si se repite un elemento, no se van a eliminar todos...
	EL *pel;
	LISTA l;
	if(pl==NULL) return -1;
	if((*pl)>info==info){ //si la inf que quiero borrar esta al inicio, reservarlo
		pel=*pl;
		*pl=(*pl)->sig;
		//liberar memoria reservada y limpieza de información
		pel->sig=NULL;
		pel->info=0;
		//pudiera suceder que se tiene imformación muy compleja. Hay que recuperar toda esa información
		free(pel);
		pel=NULL;
		return 1;
	}
	l=*pl;
	//si no es el caso, me voy con el siguiente
	while(l->sig!=NULL){
		if(l->sig->info==info){
			pel=l->sig; 
			l->sig=pel->sig; //l->sig=l->sig->sig (es equivalente) al siguiente del siguiente
			//liberar memoria reservada y limpiar información
				pel->sig=NULL;
	        	pel->info=0;
		        free(pel);
		        pel=NULL;
		        return 1;
		 }
		 l=l->sig;
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------------
int vaciar (LISTA *pl){
	//liberar espacio, desde lo más "profundo" a lo más externo. en este caso solo tenemos un entero
	//hay que liberar los elementos de lista que se generaron
	LISTA l=*pl;
	EL *pel;
	if(pl==NULL) return -1;
	l=*pl;
	while(l!=NULL){
		pel=l; //pel=*l;
		//copiar esa referencia
		l=l->sig; //lista apunta al siguiente
		//liberar espacio reservado
		//si info tuviera apuntadores dentro, habría que liberar cada uno
		//posiblemente eliminar información previa
		pel->sig=NULL; //todos 
		pel->info=0;
		free(pel);
		pel=NULL; //pel es una variable apuntador que tiene esa inf de memoria. Arriba se liberó ese espacio pero aquí ya se está poniendo a null
	}
	*pl=NULL;
	return 0;
}
//---------------------------------------------------------------------------------------------------------
int imprimir (LISTA l){
	//ver si la lista está vacía
	if(l==NULL){
		printf("Vacía.\n");
		return 0;
	}
	//si no está vacía, va a tener información y referencia a un sig elem
	while(l!=NULL){
		printf("[%3d]->", l->info);
		l=l->sig;
	}
	printf("[nulo]\n");
	return 0;
}