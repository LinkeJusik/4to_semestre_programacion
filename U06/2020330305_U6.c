#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int imparray(int array[], int n);
int OrdIntercambio(int a[], int n);
int igualarray(int array[], int aux[], int n);
void seleccion(int arreglo[], int longitud);
void Intercambiar(int *a, int *b);
void OrdInsercion (int A[], int n);
void shell(int A[], int n);
typedef int DataType;
typedef int(*Compare)(const void *a, const void *b);
int HS_CompareAscending_order(const void *a, const void *b);
int HS_CompareDescending_order(const void *a, const void *b);
void HeapSort(DataType *array, int size, Compare cmp);
int particion(int arreglo[], int izquierda, int derecha, int n);
void quicksort(int arreglo[], int izquierda, int derecha, int n);
void merge_sort(int array[], int izquierda,int derecha, int n);
void merge(int array[], int izquierda,int medio,int derecha, int n);
int imparray2(int array[], int n);
int busquedaLineal(int lista [], int n, int clave);
int BusquedaBin(int lista[], int bajo, int alto, int clave);
void merge_sort2(int array[], int izquierda,int derecha, int n);
void merge2(int array[], int izquierda,int medio,int derecha, int n);
bool has[50][2];
bool Hash(int X);
void insert(int a[], int n);

int main(){
    int val[50], aux[50], n, i, xd, r=0, clave, l, j;

    printf("Ingrese el número de elementos: "); scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Ingrese el elemento número %d: ", i+1); scanf("%d", &val[i]);
    }
    igualarray(val, aux, n);

    while(r==0){
    	printf("Tu arrelgo es:\n");
    	imparray(aux, n);
        printf("\n\n�Qué deseas hacer?\n-Busqueda\n\t1. Lineal\n\t2. Binaria\n\t3. Hash\n-Ordenamiento\n\t4. Intercambio directo\n\t5. Selección directa\n\t6. Inserción directa\n\t7. Shellsort\n\t8. Heapsort\n\t9. Quicksort\n\t10. Mergesort\n-0 para salir\nIngresa opción: ");
        scanf("%d", &xd);
        igualarray(aux, val, n);
        switch(xd){
            case 1:
            	system("cls");
                printf("\n\n--> Busqueda lineal <--\n");
				printf("Ingrese el valor a buscar: "); scanf("%d", &clave);
				l = busquedaLineal(val, n, clave);
				if(l>=0){
					printf("El indice del elemento es %d.\nUbicado:\n", l);
					imparray(val, n);
					j=0;
					while(j<l){
						printf("\t");
						j++;
					}
					printf("^-----\n\n");
				}else{
					printf("El valor buscando no est� dentro del arreglo\n\n");
				}
                break;
            case 2:
            	system("cls");
                printf("\n\n--> Busqueda binaria <--\n");
                merge_sort2(val, 0,n-1, n);
                printf("\nO R D E N A N D O . . .\n");
                sleep(2);
                printf("Ingrese el valor a buscar: "); scanf("%d", &clave);
				l = BusquedaBin(val, 0, n, clave);
				if(l>=0){
					printf("El indice del elemento (en el arreglo ordenado) es %d.\nUbicado:\n", l);
					imparray(val, n);
					j=0;
					while(j<l){
						printf("\t");
						j++;
					}
					printf("^-----\n\n");
				}else{
					printf("El valor buscando no est� dentro del arreglo\n\n");
				}
                break;
            case 3:
            	system("cls");
            	insert(val, n);
                printf("--> Busqueda Hash <--\n\n\n");
                printf("Ingrese el valor a buscar: "); scanf("%d", &clave);
                if (Hash(clave) == true)
					printf("El elemento s� est� dentro del arreglo\n\n");
				else
					printf("El elemento no est� dentro del arreglo\n\n");
                break;
            case 4:
            	system("cls");
                printf("\n\n--> Ordenamiento por intercambio directo <--\n");
                sleep(2);
                imparray2(val, n);
                OrdIntercambio(val, n);
                break;
            case 5:
            	system("cls");
                printf("\n\n--> Ordenamiento por selección directa <--\n");
                sleep(2);
                imparray2(val, n);
                seleccion(val, n);
                break;
            case 6:
            	system("cls");
                printf("\n\n--> Ordenamiento por inserción directa <--\n");
                sleep(2);
                imparray2(val, n);
                OrdInsercion(val, n);
                break;
            case 7:
            	system("cls");
                printf("\n\n--> Ordenamiento shellsort <--\n");
                sleep(2);
                imparray2(val, n);
                shell(val, n);
                break;
            case 8:
            	system("cls");
                printf("\n\n--> Ordenamiento heapsort <--\n");
                sleep(2);
                imparray2(val, n);
                HeapSort(val, n, HS_CompareDescending_order);
                break;
            case 9:
            	system("cls");
                printf("\n\n--> Ordenamiento quicksort <--\n");
                sleep(2);
                imparray2(val, n);
                quicksort(val, 0, n-1, n);
                break;
            case 10:
            	system("cls");
                printf("\n\n--> Ordenamiento mergesort <--\n");
                sleep(2);
                imparray2(val, n);
                merge_sort(val, 0,n-1, n);
                break;
            case 0:
                printf("Bye");
                r=1;
                break;
            default:
                printf("Opción invalida");
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

int igualarray(int array[], int aux[], int n){
    int i;
    for(i=0; i<n; i++){
        aux[i]=array[i];
    }
    return 0;
}

int imparray(int array[], int n){
    int i;
    for(i=0; i<n; i++){
        if(i==0){
            printf("[%d,\t ", array[i]);
        }else{
        if(i==n-1){
            printf("%d]", array[i]);
        }else{
            printf("%d,\t", array[i]);
        }}
    }
    printf("\n");
    return 0;
}
int imparray2(int array[], int n){
    int i, j;
    system("cls");
    for(i=0; i<n; i++){
        for(j=0; j<array[i]; j++){
        	printf("*");
		}
		printf("\n");
    }
    sleep(1);
    return 0;
}
void intercambiar(int *a, int *b){
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

int OrdIntercambio (int a[], int n){
    int i, j;
    for (i = 0 ; i < n-1 ; i++){
        for (j = i+1 ; j < n ; j++){
            if (a[i] > a[j]){
                intercambiar(&a[i], &a[j]);
                imparray2(a, n);
            }
        }
    }
    return 0;
}

void seleccion(int arreglo[], int longitud){
	int i, j;
  for(i = 0; i < longitud - 1; i++){
    for (j = i + 1; j < longitud; j++) {
     
      if (arreglo[i] > arreglo[j]) {
        intercambiar(&arreglo[i], &arreglo[j]);
        imparray2(arreglo, longitud);
      }
    }
  }
}
void OrdInsercion (int A[], int n){
    int i, j, aux;
    for (i = 1; i < n; i++){
        j = i;
        aux = A[i];
        while (j > 0 && aux < A[j-1]){
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
        imparray2(A, n);
    }
}

void shell(int A[], int n){
    int i, j, k, salto = n/2;
    while (salto > 0){               // ordenaci\'on de salto listas   
        for (i = salto; i < n; i++){ //ordenaci\'on parcial de lista i, los elementos de cada lista est\'an a distancia salto
            j = i - salto;
            while(j >= 0){
                k = j + salto;
                if (A[j] <= A[k]) // elementos contiguos de la lista
                    j = -1; // fin bucle par ordenado
                else{
                    intercambiar(&A[j], &A[k]);
                    j = j - salto;
                    imparray2(A, n);
                }
            }
        }   
        salto = salto / 2;
    }
}
//heapsort//
void HS_swap(DataType *a, DataType *b)
{
    DataType temp = *a;
    *a = *b;
    *b = temp;
}

 // Descendiendo - pequeño montón
int HS_CompareAscending_order(const void *a, const void *b)
{
    return *(DataType*)a - *(DataType*)b;
}

 // Ascendente - gran pila
int HS_CompareDescending_order(const void *a, const void *b)
{
    return *(DataType*)b - *(DataType*)a;
}

void HS_Adjust(DataType *array, int size, int parent, Compare cmp)
{
    int child = parent * 2 + 1;
    assert(array);

    while (child < size)
    {
        if ((child + 1) < size && cmp(&array[child], &array[child + 1]) > 0)
        {
            child += 1;
        }
        if (array[parent] < array[child])
        {
            HS_swap(&array[parent], &array[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            return;
        }
    }
}


void HeapSort(DataType *array, int size, Compare cmp){
    int end = size - 1;
    // 1. construir montón
    int root = ((size - 1) - 1) >> 1;
    for (; root >= 0; --root)
    {
        HS_Adjust(array, size, root, cmp);
    }
    // 2. Ordenar
    while (end)
    {
        HS_swap(&array[0], &array[end]);
        HS_Adjust(array, end, 0, cmp);
        --end;
        imparray2(array, size);
    }
}
//HeapSort^//

int particion(int arreglo[], int izquierda, int derecha, int n) {
  int pivote = arreglo[izquierda];
  while (1) {
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    if (izquierda >= derecha) {
      return derecha;
    } else {
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      izquierda++;
      derecha--;
      imparray2(arreglo, n);
    }
  }
}
void quicksort(int arreglo[], int izquierda, int derecha, int n){
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha, n);
    quicksort(arreglo, izquierda, indiceParticion, n);
    quicksort(arreglo, indiceParticion + 1, derecha, n);
  }
}

void merge_sort(int array[], int izquierda,int derecha, int n){
    int medio;
    if(izquierda<derecha){
        medio=(izquierda+derecha)/2;
        merge_sort(array, izquierda,medio, n);
        merge_sort(array, medio+1,derecha, n);
        merge(array, izquierda,medio,derecha, n);
    }
}
void merge(int array[], int izquierda,int medio,int derecha, int n){
    int h,i,j,b[50],k;
    h=izquierda;
    i=izquierda;
    j=medio+1;
    
    while((h<=medio)&&(j<=derecha)){
        if(array[h]<=array[j]){
            b[i]=array[h];
            h++;
        }
        else
            {
                b[i]=array[j];
                j++;
            }
        i++;
    }
    if(h>medio){
        for(k=j;k<=derecha;k++){
            b[i]=array[k];
            i++;
        }
    }
    else
        {
            for(k=h;k<=medio;k++){
                b[i]=array[k];
                i++;
            }
        }
    for(k=izquierda;k<=derecha;k++){
        array[k]=b[k];
        }
    imparray2(array, n);
}

//---------BUSQUEDAS-----------//
int busquedaLineal(int lista [], int n, int clave){
	int i;
	for(i = 0; i < n; i++)
		if(lista[i] == clave)
		return i;
	return -1;
}
int BusquedaBin(int lista[], int bajo, int alto, int clave){
	int central, valorCentral;
	while(bajo <= alto){
		central = (bajo + alto)/2; // �ndice de elemento central
		valorCentral = lista[central]; // valor del �ndice central
		if (clave == valorCentral)
			return central; // encontrado valor;
		// devuelve posici�n
		else if (clave < valorCentral)
			alto = central -1; // ir a sublista inferior
		else
			bajo = central + 1; // ir a sublista superior
	} // elemento no encontrado
	return -1;
}
void merge_sort2(int array[], int izquierda,int derecha, int n){
    int medio;
    if(izquierda<derecha){
        medio=(izquierda+derecha)/2;
        merge_sort2(array, izquierda,medio, n);
        merge_sort2(array, medio+1,derecha, n);
        merge2(array, izquierda,medio,derecha, n);
    }
}
void merge2(int array[], int izquierda,int medio,int derecha, int n){
    int h,i,j,b[50],k;
    h=izquierda;
    i=izquierda;
    j=medio+1;
    
    while((h<=medio)&&(j<=derecha)){
        if(array[h]<=array[j]){
            b[i]=array[h];
            h++;
        }
        else
            {
                b[i]=array[j];
                j++;
            }
        i++;
    }
    if(h>medio){
        for(k=j;k<=derecha;k++){
            b[i]=array[k];
            i++;
        }
    }
    else
        {
            for(k=h;k<=medio;k++){
                b[i]=array[k];
                i++;
            }
        }
    for(k=izquierda;k<=derecha;k++){
        array[k]=b[k];
        }
}
bool Hash(int X)
{
	if (X >= 0) {
		if (has[X][0] == 1)
			return true;
		else
			return false;
	}
	X = abs(X);
	if (has[X][1] == 1)
		return true;

	return false;
}
void insert(int a[], int n)
{
	int i=0;
	for (i = 0; i < n; i++) {
		if (a[i] >= 0)
			has[a[i]][0] = 1;
	else
			has[abs(a[i])][1] = 1;
	}
}
