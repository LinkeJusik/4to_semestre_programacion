#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a, b=-1, k=-1, n, i;
    printf("Ingrese el numero a analizar: "); scanf("%d", &a);
    printf("Ingrese el valor del modulo a considerar: "); scanf("%d", &n);

    for(i=0; i<n; i++){
        if((a*i)%n==1){
            k=i;
        }
    }
    if(k!=-1){
        printf("El inverso multiplicativo de (%d)mod%d es %d\n",a, n, k);
    }else{
        printf("%d no posee inverso multiplicativo mod%d\n",a,n);
    }
    
    for(i=1; i<n; i++){
        if((a*i)%n==0){
            b=i;
            break;
        }
    }
    if(b!=-1){
        printf("El divisor de cero de (%d)mod%d es %d\n",a,n, b);
    }else{
        printf("%d no posee divisor de cero mod%d\n",a,n);
    }
    system("pause");
    return 0;
}