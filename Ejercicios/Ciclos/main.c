#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, n, k, ren, colultren;
	
	printf("Digite n: "); scanf("%d",&n);
	
	ren = ((n-1)/10)+1;
	colultren = ((n-1)%10)+1;
	
	for(i=1, k=5;i<ren;i++){
		for(i=1;i<=n;i++,k+=5)
			printf("\t%3d", k);
		printf("\n");
	}
	for(j=1; j<=colultren; j++, k+=5)
		printf("\t%3d ",k);
	
	printf("\nFin del programa.\n");
	
	return 0;
}
