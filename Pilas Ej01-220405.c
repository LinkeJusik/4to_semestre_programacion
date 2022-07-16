#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>

typedef struct _elem_pila_{
	int info;
	struct _elem_pila_ *sig;
}ELPILA;

typedef ELPILA *PILA; //pila es un apuntador

int push(int info, PILA *ppila);
int pop(PILA *ppila); //sacar info
int pilavacia(PILA pila); /*INFO peep (PILA pila);*/
int imprimeP (PILA pila);
int eval(char *expresion, int x, int modulo, int valores[]);
int miexpo(int base, int exponente, int modulo);

//main-----------------------------------------------------------------------------------
int main(int argc, char *argv[]){
	PILA unaPila=NULL;//una pila vacía
	int i, ent;
	int valores[26]={1, 2, 3, 4, 5, 6};
	
	for(i=0; i<10; i++){
		push(4*i+3, &unaPila);
		imprimeP(unaPila);
	}
	ent=pop(&unaPila);
	printf("Elemento extraíado: %d.\n", ent);
	if(!pilavacia(unaPila)){
		ent=pop(&unaPila);
		printf("Elemento extraído: %d.\n", ent);
	}
	imprimeP(unaPila);
	for(i=0; i<10; i++){
		imprimeP(unaPila);
		if(!pilavacia(unaPila)) ent=pop(&unaPila);
		else break;
	}
	
	ent=eval("ab+c-d^x+", 2, 10, valores);
	printf("La evaluación fue: %d\n", ent);
	
	return 0;
}
//Cuerpo de funciones--------------------------------------------------------------------
int push(int info, PILA *ppila){
	ELPILA *pelp;
	if(ppila==NULL) return -2;
	
	if((pelp=(ELPILA*)malloc(sizeof(ELPILA)))==NULL){
		int mierr=errno;
		printf("Error al generar espacio: %d, <<%s>>\n", mierr, strerror(mierr));
		//si es null, no hubo espacio
		return -3; //escribir mensaje
	
	}
	//sí hay espacio
	pelp->info=info;
	//asingar el siguiente
	//pelp->sig=NULL; (innecesario)
	
	//insertar (al inicio)
	pelp->sig=*ppila; //al primer elemento de la pila, que es el contenido de la pila
	
	/*if(*ppila==NULL){
		*ppila=pelp;
		return 0;
	}*/ //se puede obviar
		
	*ppila=pelp;
	
	return 0;
}
//----------------------------------------------------------------------------------------
int pop(PILA *ppila){
	ELPILA *pelp;
	int miinfo;
	/*en caso de que el valor a regresar fuera en uno de los parámetros 
	if(ppila==NULL) return -2;
	if(*ppila==NULL) return -1;
	*/
	pelp=*ppila; //un apuntador a un elemento de la pila
	(*ppila)=(*ppila)->sig; //apunta al siguiente
	miinfo=pelp->info;
	//limpiar ese espacio de memoria
	pelp->info=0;
	pelp->sig=NULL;
	free(pelp);
	pelp=NULL;
	
	return miinfo;
}
//----------------------------------------------------------------------------------------
int pilavacia(PILA pila){
	return pila==NULL; //si es verdadero, va a regresar algo distinto de 0 y si es falso, regresará 0 //cambie 1 por null
}
//-------------------------------------------------------------------------------------
int imprimeP (PILA pila){
	//ver si está vacía
	if(pila==NULL){
		printf("(vacía)\n");
		return 0;
	}
	//si no
	while(pila!=NULL){
		printf("[%3d]->", pila->info);
		pila=pila->sig;
	}
	printf("nulo\n");
	return 0;
}
//------------------------------------------------------------------------------
int eval(char *expresion, int x, int modulo, int valores[]){ //x va a ser la variable
	/*a, b, c, d, e, ..., z, salvo x e y como ctes
	valores[car-'a'] //si car fuera a, 
	*/
	char *pc;
	int segundo, ret;
	PILA mipila=NULL;
	
	//ver que no esté nula
	
	for(pc=expresion; *pc!='\0'; pc++){ //moviéndose al siguiente caracter de la cadena, mientras no sea nulo 
		if(*pc=='x'){ //si el caracter corresponde a una variable, meter la var
			push(x, &mipila);
			continue;
		}
		//no fue x
		if('a'<=*pc &&*pc<='z'){ //el caracter está entre a y z
			push(valores[(*pc)-'a'], &mipila); //meter a la pila el valor que corresponde a esta cte
			continue;
		}
		switch(*pc){
			case '+': if(pilavacia(mipila)){
				         printf("Error, pila no debería estar vacía");
				         return -1;
			          }
			          segundo=pop(&mipila);
			          if(pilavacia(mipila)){
			          	printf("Error, pila no debería estar vacía.\n");
			          	return -1;
					  }
					  push((pop(&mipila)+segundo)%modulo, &mipila);
				break;
			case '-': if(pilavacia(mipila)){
				         printf("Error, pila no debería estar vacía.\n");
				         return -1;
			          }
			          segundo=pop(&mipila);
			          if(pilavacia(mipila)){
			          	printf("Error, pila no debería estar vacía.\n");
			          	return -1;
					  }
					  push((pop(&mipila)-segundo)%modulo, &mipila);
				break;
			case '*': if(pilavacia(mipila)){
				         printf("Error, pila no debería estar vacía.\n");
				         return -1;
			          }
			          segundo=pop(&mipila);
			          if(pilavacia(mipila)){
			          	printf("Error, pila no debería estar vacía.\n");
			          	return -1;
					  }
					  push((pop(&mipila)*segundo)%modulo, &mipila);
				break;
			case '^': if(pilavacia(mipila)){
				         printf("Error, pila no debería estar vacía.\n");
				         return -1;
			          }
			          segundo=pop(&mipila);
			          if(pilavacia(mipila)){
			          	printf("Error, pila no debería estar vacía.\n");
			          	return -1;
					  }
					  push(miexpo(pop(&mipila), segundo, modulo), &mipila);
				break;
		}
	}
	ret=pop(&mipila);
	if(!pilavacia(mipila)){
		printf("Error, pila debería quedar vacía.\n");
		return -1;
	}
	return ret;
}
//---------------------------------------------------------------
int miexpo(int base, int exponente, int modulo){
	int cuad, r;
	
	/*Si exponente es negativo, hay que ver si la base tiene inverso mod n
	(n==modulo), es decir, si mcd(base, modulo)=1, ent base tiene inverso.
	Sabemos que existen s, t tales que 
	base*s+modulo*t=mcd(base, modulo)=1, así
	
	s es el inverso de base en z/moduloZ
	
	Así, uso el exponente cambiándole del signo y aplicando 
	
	
	*/
	for(r=1, cuad=base; exponente>0; exponente>>=1){ //recorriendo el exponente uno a la derecha, recorre un bit a la derecha
		if(exponente &1!=0){
			r=(r+base)%modulo; //*->+
		}
		cuad=(cuad*cuad)%modulo;
	}
	return r;
}
