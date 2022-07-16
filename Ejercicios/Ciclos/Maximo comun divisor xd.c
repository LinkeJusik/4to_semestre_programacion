#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,r;
	
	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	
	if(a<0) a=-a;
	if(b<0) b=-b;
	
	while((r=a%b)!=0){
		printf("%2d %2d %2d\n",a,b,r);
		a=b;
		b=r;
	}

	printf("El máximo común divisor es: %d",b);
	return 0;
}
