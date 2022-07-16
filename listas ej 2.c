#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>

#define TAMMAX 100

typedef struct _LISTA_{ //la lista será un arreglo
   int m; //los elementos que llevamos en la lista
   int el[TAMMAX];
}LISTA;

int insertar(int info, LISTA *pl);
int buscar(int info, LISTA l);
int eliminar (int info, LISTA *pl); 
int vaciar(LISTA *pl);
int imprimir(LISTA l);


int main(int argc, char *argv[]){
	LISTA l={m:0};
	int n, info, i;
	
	printf("Ejemplo de lista.\n Digite un entero: ");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		
		printf("%2d) Digite un entero: ", i);
		scanf("%d", &info);
		insertar(info, &l);
		imprimir(l);
	}
	printf("Info a eliminar: ");
	scanf("%d", &info);
	printf("Se encontró información a eliminar: %s \n", eliminar(info, &l)==0?"si":"no");
	imprimir(l);
	vaciar(&l);
	imprimir(l);
	
	printf("\n Fin del programa \n");
	
	system("pause");
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------
int insertar(int info, LISTA *pl){
	int i, j;
	//la lista está vacía?
	if(pl->m==0){
		pl->el[(pl->m)++]=info; //indice en este caso vale 0. Primero se usa y luego se incrementa
		return 0;
	}
	/*debemos contar con un criterio para insertar informacion*/
	/*mi criterio: de menor a mayor en el orden de los numeros*/
	
	//ver si todavía hay espacio para poner información
	if(pl->m>=TAMMAX){
		return -1; //puede ponerse también un mensaje de error
	}
	for(i=0; i<pl->m; i++){
		if(info<=pl->el[i]){ //vamos a permitir repeticiones? sí, por eso igual el <=
		    for(j=pl->m; j>i; j--){
		    	pl->el[j]= pl->el[j-1]; //poner el anterior
			} //j ya acanzó el valor de i, ya recorrimos la información un lugar a la derecha
			pl->el[i]=info;	//el el indice i ponemos la información de interés		
			(pl->m)++;
			return 0;
	    }
	} //si nunca hubiera entrado es porque el valor es mas grande que los que ya etsaban
	pl->el[(pl->m)++]=info;
	
	return 0;
	
}
//-----------------------------------------------------------------------------------------------------------------------------
int buscar(int info, LISTA l){
	int ret=0;
	
	for(int i=0; i<l.m; i++){
	 if(info<l.el[i]) return ret; //la inf a buscar la queremos comparar con la inf de la i-esima casilla
	 if(info==l.el[i]) ret++; //cuando la haya encontrado, contar el numero de veces que se tope con ela, hasta que no haya más repeticiones
	 
	}
	return ret;
}
//------------------------------------------------------------------------------------------------------------------------------
int eliminar (int info, LISTA *pl){
	int i, j;
	
	if(pl->m==0) return -1; //ver si está vacía
	for(i=0; i<pl->m; i++){
		if(info<pl->el[i]) return -1; //no se pudo borrar porque no existe
		if(info==pl->el[i]){//si sí es, copiar los elementos anteriores
			for(j=i+1; j<pl->m; j++){
				pl->el[j-1]=pl->el[j];
			} //ya se hizo la copia
			pl->el[j]=0;
			(pl->m)--;
			return 0;
		}
	}
	//si nunca se encontró
	return -1;
		
	return 0;
}
//-------------------------------------------------------------------------------------
int vaciar(LISTA *pl){
	int i;
	pl->m=0;
	for(i=0; i<TAMMAX; i++) pl->el[i]=0;
	return 0;
	
}

//----------------------------------------------------------------------------------
int imprimir(LISTA l){
	int i;
	if(l.m==0){
		printf("(vacía)\n");
		return 0;
	}
	for(i=0; i<l.m; i++){
		printf("\t[%3d]->%d\n", i, l.el[i]);
	}
	printf("\nFin de la lista.\n");
	return 0;
	
}
