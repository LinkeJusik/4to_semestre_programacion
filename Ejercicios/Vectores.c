#include <stdio.h>
#include <stdlib.h>
#define DIM 3

int main(int argc, char *argv[]){
	double v1[DIM], v2[DIM], vr[DIM];
	int i;

	printf("Programa para R^3\n");
	printf("Por leer el primer vector: \n");
	for(i=0; i<DIM; i++){
		printf("Digite x%d: ",i); scanf("%lg", &v1[i]);
	}
	printf("Por leer el segundo vector: \n");
	for(i=0; i<DIM; i++){
		printf("Digite x%d: ",i); scanf("%lg", &v2[i]);
	}

	for(i=0; i<DIM;i++){
		vr[i] = v1[i]+v2[i];
	}
	printf("El vector suma es: \n");
	for(i=0; i<DIM; i++){
		printf("%lg\t", vr[i]);
	}

	system("pause");
	return 0;
}