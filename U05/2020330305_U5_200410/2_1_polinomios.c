#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>
typedef struct _info_{
    int exponente;
    int coeficiente;
}INFO;

typedef struct _monomio_{
    INFO info;
    struct _monomio_ *sig;
}MONOMIO;

typedef struct _polinomio_{
    MONOMIO *ini, *fin;
}POLINOMIO;

int agregar(int exponente, int coeficiente, POLINOMIO *pp);
int sacar(int *pe, int *pc, POLINOMIO *pp);
int imprimir(POLINOMIO pol, int gradomax);
int vaciar(POLINOMIO *ppol);
int suma(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo);
int producto(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo);
int cociente(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo, int g1, int g2);
int mcd(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo);
int eval(POLINOMIO pol, int grado, int x);
int miexpo(int base, int exponente);

int main(int argc, char *argv[]){
    POLINOMIO px1, px2;
    int a, b=0, c, i, g1, g2, gg, p;

    px1.ini=NULL;
    px2.ini=NULL;
    
    printf("Ingrese el grado de su primer polinomio: "); scanf("%d", &g1);
    printf("Ingrese el grado de su segundo polinomio: "); scanf("%d", &g2);
    printf("Ingrese un numero primo: "); scanf("%d", &p);

    if(g1>=g2){gg=g1;}else{gg=g2;}
    printf("Por obtener los coeficientes del primer polinomio: ...\n");
    for(i=gg; i>=0; i--){
        if(i<=g1){
            printf("Ingrese el coeficiente asociado al grado %d: ", i); scanf("%d", &a);
            agregar(i, a%p, &px1);
        }else{
            agregar(i, 0, &px1);
        }
    }
    printf("El primer polinomio es:\n");
    imprimir(px1, gg);
    
    printf("Por obtener los coeficientes del segundo polinomio: ...\n");
    for(i=gg; i>=0; i--){
        if(i<=g2){
            printf("Ingrese el coeficiente asociado al grado %d: ", i); scanf("%d", &a);
            agregar(i, a%p, &px2);
        }else{
            agregar(i, 0, &px2);
        }
    }
    printf("El segundo polinomio es:\n");
    imprimir(px2, gg);
    printf("Ingrese un número entero relacionado a la función que desee realizar:\n");
    while(b==0){
        printf("1. Suma\n2. Producto\n3. Cociente\n4. Residuo\n5. MCD\n6. Limpiar la pantalla\n7. Salir\n"); scanf("%d", &c);
        switch(c){
        case 1:
        suma(px1, px2, gg, p);
        break;
        case 2:
        producto(px1, px2, gg, p);
        break;
        case 3:
        cociente(px1, px2, gg, p, g1, g2);
        break;
        case 4:
        printf("El residuo es %d", cociente(px1, px2, gg, p, g1, g2));
        break;
        case 5:
        mcd(px1, px2, gg, p);
        break;
        case 6:
        system("cls");
        break;
        case 7:
        b=1;
        break;
        default:
        printf("No haz introducido ninguna opcion valida :(\n");
        break;
        }
    }
    
    system("pause");
    return 0;
}

int agregar(int exponente, int coeficiente, POLINOMIO *pp){
    MONOMIO *pelem;
    if(pp==NULL) return -2;
    if((pelem = (MONOMIO*)malloc(sizeof(MONOMIO))) == NULL){
        int mierr = errno;
        printf("Error al reservar espacio: %d, <<%s>>\n", mierr, strerror(mierr));
        return -1;
    }
    pelem->info.exponente = exponente;
    pelem->info.coeficiente = coeficiente;
    pelem->sig == NULL;

    if(pp->ini == NULL){
        pp->ini = pp->fin = pelem;
        return 0;
    }
    pp->fin->sig=pelem;
    pp->fin=pelem;
    
    return 0;
}

int sacar(int *pe, int *pc, POLINOMIO *pp){
    MONOMIO *pelem;
    if(pp==NULL || pe==NULL || pc==NULL) return -2;
    if(pp->ini==NULL) return -1;
    
    pelem = pp->ini;
    pp->ini = pp->ini->sig;

    *pe = pelem->info.exponente;
    *pc = pelem->info.coeficiente;

    pelem->info.exponente=0;
    pelem->info.coeficiente=0;
    pelem->sig = NULL;

    free(pelem);
    pelem=NULL;

    return 0;
}

int imprimir(POLINOMIO pol, int gradomax){
    MONOMIO *aux;
    int i, true=0;

    if(pol.ini == NULL){
        printf("0\n");
        return 0;
    }
    aux = pol.ini;
    for(i=0; i<=gradomax; i++, aux=aux->sig){
        if(aux->info.coeficiente!=0){
            if(aux->info.exponente==0){
                printf("%d\n", aux->info.coeficiente);
            }else{
                printf("%d*x^{%d} + ", aux->info.coeficiente, aux->info.exponente);
            }
            true=1;
        }
    }
    if(true!=1){printf("0");}
    printf("\n");
    return 0;
}

int vaciar(POLINOMIO *ppol){
    MONOMIO *aux, *limpiar;

    if(ppol==NULL) return -2;
    if(ppol->ini == NULL) return 0;

    aux = ppol->ini;
    while(aux!=NULL){
        limpiar = aux;
        aux = aux->sig;
        limpiar->info.coeficiente=0;
        limpiar->info.exponente=0;
        limpiar->sig = NULL;
        free(limpiar);
    }
    ppol->ini = ppol->fin = NULL;
    return 0;
}

int suma(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo){
    POLINOMIO res;
    MONOMIO *aux1, *aux2;
    aux1 = pol1.ini;
    aux2 = pol2.ini;
    res.ini=NULL;
    int i;
    for(i=gradomax; i>=0; i--, aux1=aux1->sig, aux2=aux2->sig){
        agregar(i, (aux1->info.coeficiente + aux2->info.coeficiente)%primo, &res);
    }
    printf("La suma de los polinomios es:\n");
    imprimir(res, gradomax);
    return 0;
}
int producto(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo){
    POLINOMIO res;
    MONOMIO *aux1, *aux2;
    aux1 = pol1.ini;
    aux2 = pol2.ini;
    res.ini=NULL;
    int i, j, aux[gradomax+gradomax];
    for(i=0; i<=gradomax+gradomax; i++){
        aux[i]=0;
    }
    for(i=gradomax; i>=0; i--, aux1=aux1->sig){
        for(j=gradomax, aux2 = pol2.ini; j>=0; j--, aux2=aux2->sig){
            aux[i+j]+=(aux1->info.coeficiente * aux2->info.coeficiente);
        }
    }
    for(i=gradomax+gradomax; i>=0; i--){
        agregar(i, aux[i]%primo, &res);
    }
    printf("El producto de los polinomios es:\n");
    imprimir(res, gradomax+gradomax);
    return 0;
}
int cociente(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo, int g1, int g2){
    POLINOMIO res;
    MONOMIO *aux1, *aux2;
    int raices[gradomax], i, cont=0, q[gradomax], j;
    aux1 = pol1.ini;
    aux2 = pol2.ini;
    res.ini=NULL;
    if(g1<g2){
        printf("El cociente entre los polinomios es\n0\n");
        return 0;
    }
    for(i=0; i<primo; i++){
        if(eval(pol2, g2, i)==0){
            raices[cont]=i;
            cont++;
        }
    }
    q[0] = aux1->info.coeficiente;
            for(j=0; j<=cont;j++){
                if(j==1){
                    for(i=1, aux1=pol1.ini;i<=gradomax;i++, aux1=aux1->sig){
                                    q[i] = (q[i-1]*raices[j])+aux1->info.coeficiente;
                    }
                }else{
                    for(i=1, aux1=res.ini;i<=gradomax;i++, aux1=aux1->sig){
                                    q[i] = (q[i-1]*raices[j])+aux1->info.coeficiente;
                    }
                }
                for(i=0;i<=g1-g2;i++){
                    agregar(g1-g2-i, (q[i])%primo, &res);
                    imprimir(res, gradomax);
                }
                //printf("\n Remainder is: %d", q[gradomax]);
            }
    return q[gradomax];
}
int mcd(POLINOMIO pol1, POLINOMIO pol2, int gradomax, int primo){
    return 0;
}
int eval(POLINOMIO pol, int grado, int x){
    int cont=0, i;
    MONOMIO *aux;
    
    if(pol.ini == NULL){
        return cont;
    }
    aux = pol.ini;
    for(i=0; i<=grado; i++, aux=aux->sig){
        cont += aux->info.coeficiente*miexpo(x, aux->info.exponente);
    }
    return cont;
}
int miexpo(int base, int exponente){
    int cuad, r;
    for(r=1, cuad==base; exponente>0; exponente>>=1){
        if(exponente & 1!=0){
            r=(r*base);
        }
        cuad = (cuad*cuad);
    }
    return r;
}