#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <conio.h>

typedef struct _elem_pila_{
    float info;
    struct _elem_pila_ *sig;
}ELPILA;
struct LIFO {
	int t;
	char a[30];
};

typedef ELPILA *PILA;
/*typedef struct _pila_{
    ELPILA *ini, *fin;
}PILA;*/

int push(float info, PILA *ppila);
float pop(PILA *ppila);
int pilavacia(PILA pila); /*INFO peep(PILA pila);*/
int imprimeP(PILA pila);
float eval(char *expresion, float x, float valores[]);
int miexpo(int base, int exponente, int modulo);
void in_a_pos (char *infijo,char *posfijo);
int operando (char c);
int prioridad (char op1,char op2);
char tope (struct LIFO p);
void init_pila (struct LIFO *p);
int pila_vacia (struct LIFO *p);
void ins_pila (struct LIFO *p,char s);
void retira_pila (struct LIFO *p,char *s);

int main(int argc, char *argv[]){
    PILA unaPila=NULL;
    int i, st;
    float valores[26];
    char infijo[50], *pc, posfijo[100];

    printf("Ingrese la función que desea evaluar (puede usar parentesis): "); scanf("%s",&(*infijo));

    st = strlen(infijo);
    in_a_pos(infijo,posfijo);

    for(pc=posfijo; *pc!='\0'; pc++){
        if('a'<=*pc && *pc <= 'z' && *pc!='x'){
            if(valores[(*pc)-'a']){
                printf("Ingrese el valor de %c: ",*pc); scanf("%f",&valores[(*pc)-'a']);
            }
        }
    }
    
    printf("La evaluación fue:\n");

    for(i=-5; i<=5; i++){
        printf("%.2f\t", eval(posfijo,i,valores));
    }

    printf("\n");
    system("pause");
    return 0;
}

int push(float info, PILA *ppila){
    ELPILA *pelp;
    if(ppila==NULL) return -2;

    if((pelp=(ELPILA*)malloc(sizeof(ELPILA)))==NULL){
        int mierr = errno;
        printf("Error al crear espacio: %d, <<%s>>\n", mierr, strerror(mierr));
        return -3;
    }

    pelp->info = info;
    pelp->sig=*ppila;

    if(*(ppila)==NULL){
        *ppila = pelp;
        return 0;
    }

    *ppila = pelp;
    return 0;
}
float pop(PILA *ppila){
    ELPILA *pelp;
    float miinfo;
    /*en caso de que el valor a regresar fuera en un de los dos parametros:
    if(ppila==NULL) return -2;
    if(*ppila==NULL) return -1;*/
    pelp = *ppila;
    (*ppila) = (*ppila)->sig;
    miinfo = pelp->info;
    pelp->info=0;
    pelp->sig=NULL;
    free(pelp);
    pelp = NULL;
    return miinfo;
}

int pilavacia(PILA pila){ /*INFO peep(PILA pila);*/
    return pila == NULL;

}
int imprimeP(PILA pila){
    if(pila==NULL){
        printf("(V A C I A)\n");
        return 0;
    }
    while(pila!=NULL){
        printf("[%f]->", pila->info);
        pila = pila->sig;
    }
    printf("nulo\n");

    return 0;
}
float eval(char *expresion, float x, float valores[]){
    /*a, b, c, d, ..., z; salvo x y y como constantes
    valores[car-'a']*/
    char *pc;
    float segundo, ret;
    PILA mipila=NULL;

    for(pc=expresion; *pc!='\0'; pc++){
        if(*pc=='x'){
            push(x, &mipila);
            continue;
        }
        if(*pc=='P'){
            push(3.141592654, &mipila);
            continue;
        }
        if(*pc=='E'){
            push(2.7182818284, &mipila);
            continue;
        }
        if('a'<=*pc && *pc <= 'z'){
            push(valores[(*pc)-'a'], &mipila);
            continue;
        }
        switch(*pc){
            case '+':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            push((pop(&mipila)+segundo), &mipila);
            break;
            case '-':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            push((pop(&mipila)-segundo), &mipila);
            break;
            case '*':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            push((pop(&mipila)*segundo), &mipila);
            break;
            case '/':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            push((pop(&mipila)/segundo), &mipila);
            break;
            case '^':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            push(pow(pop(&mipila),segundo), &mipila);
            break;
            case 'S':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            push(sin(segundo), &mipila);
            break;
            case 'C':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            push(cos(segundo), &mipila);
            break;
            case 'L':
            if(pilavacia(mipila)){
                printf("E R R O R\nPila no debería estar vacia\n");
                return -1;
            }
            segundo = pop(&mipila);
            push(log(segundo), &mipila);
            break;
        }
    }
    if(pilavacia(mipila)){
        printf("Error pila no debería estar vacia\n");
        return -1;
    }
    ret = pop(&mipila);
    if(!pilavacia(mipila)){
        printf("Error, pila SI debería quedar vacia\n");
        return -1;
    }
    return ret;
}
/**/
void in_a_pos(char *infijo,char *posfijo)
{
	struct LIFO pila;
	int i,j;
	char elemento;
	i=0;
	j=-1;
	init_pila (&pila);
	while (infijo [i] != '\0') {
	   if (operando (infijo [i]) )
		   posfijo [++j] = infijo [i++];
	   else {
		     while (!pila_vacia (&pila)  &&
			 prioridad (tope (pila),infijo [i] ) )  {
			     retira_pila (&pila,&elemento);
			     posfijo [++j] = elemento;
		      }
		      if (infijo [i] == ')')
			   retira_pila (&pila,&elemento);
		      else ins_pila (&pila,infijo [i]);
		      i++;
		}
	}
	while (!pila_vacia (&pila) ) {
		retira_pila (&pila,&elemento);
		posfijo [++j] = elemento;
	}
	posfijo [++j] = '\0';
}


int operando (char c)
{
	return ( c != '+' &&
		 c != '-' &&
		 c != '*' &&
		 c != '/' &&
		 c != '^' &&
		 c != ')' &&
		 c != '(' &&
		 c != 'S' &&
		 c != 'L' &&
		 c != 'C');
}

static int m[6][7] = {
	{ 1,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,0,0,1 },
	{ 1,1,1,1,1,0,1 },
	{ 0,0,0,0,0,0,0 }
};

int prioridad (char op1,char op2)
{
	int i,j;
	
	switch (op1) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '/' :  i = 3; break;
		case '^' :  i = 4; break;
		case '(' :  i = 5; break;
		case 'S' :  i = 6; break;
		case 'C' :  i = 7; break;
		case 'L' :  i = 8; break;
	}
	switch (op2) {
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '/' :  j = 3; break;
		case '^' :  j = 4; break;
		case '(' :  j = 5; break;
		case ')' :  j = 6; break;
		case 'S' :  j = 7; break;
		case 'C' :  i = 8; break;
		case 'L' :  i = 9; break;
	}	
	return (m [i][j]);
}

char tope (struct LIFO p)
{
	return ( p.a [p.t -1] );
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,char s)
{
	if (p->t == 30)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,char *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '\0';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}