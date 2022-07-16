#include <stdio.h>
#include <stdlib.h>

#define MI_ID
#define MI_SALUDO printf("Hola a todos\n")
#define Varias_lineas printf("Hola "); \
		printf("Mundo otra "); \
		printf("vez.\n")
#define CUADRADO(X) X*X
#define tam(X) printf("tamaño de " #X " es: %d\n",sizeof(X))

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b=-1;
	signed int c, d=-1;
	unsigned int e, f=-1;
	
	char _3x, _2='A';
	
	printf("Hola mundo\notra cadena\totra cadena más\a fin");
	printf("\na=%d, b=%d.",a,b);
	printf("\na=%u, b=%u.",a,b);
	printf("\na=%x, b=%x.",a,b);
	printf("\na=%o, b=%o.\n",a,b);
	
	printf("c1=<<%c>>, c2=<<%c>>\n", _3x, _2);
	_3x='\'', _2='"';
	printf("c1=<<%c>>, c2=<<%c>>\n", _3x, _2);
	_3x=0x41, _2='\060';
	printf("c1=<<%c>>, c2=<<%c>>\n", _3x, _2);
	
	MI_SALUDO;
	Varias_lineas;
	a=CUADRADO(5);
	printf("a*a = %d\n",a);
	tam(char);
	tam(short);
	tam(short int);
	tam(int);
	tam(long);
	tam(long int);
	tam(float);
	tam(double);
	tam(long double);
	
	system("pause");
	return 0;
}
