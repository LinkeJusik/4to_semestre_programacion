#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

//Definiendo la matriz en la que guardaremos el estado en el que nos encontramos
typedef struct _ESTADO_{
    int u;
	int ent[20][7];
}ESTADO;
//Declarando la función que lee el estado que se le indique
int LeerEstado(ESTADO estadito, int actual);
//Declarando la función que nos indica que no se repite un estado pasado
int NoRepetir(ESTADO estadito, int actual);
//Declarando la función que evalua si hay conflicto
int Conflicto(ESTADO est, int actual);
//Declarando la función que nos movera a los sujetos de un lado a otro xd
ESTADO Barco(ESTADO estadito, int actual, int error);
ESTADO est, final;
int main()
{
    int i,j;
    for(i=0;i<=7;i++){
        for(j=0;j<=20; j++){
            est.ent[i][j]=0;
        }
    }//inicializamos para evitar errores
    printf("Hola: este es el problema del hombre con el lobo, el cordero y su saco de lechugas. \nTenemos un cordero, un lobo y unas lechugas, lo suficientemente civilizados como para no matar al pobre hombre, pero no lo suficiente como para dejarlos sin vigilancia unos minutos. \nTenemos que cruzar a todos estos elementos desde la orilla a la derecha hasta la orilla a la izquierda, pero no podemos dejar al lobo con el cordero (porque se lo come equis de) y no podemos dejar al cordero con las lechugas (porque es vegano equis de). \nAquí comienza el problema:\n");
    /*Las posiciones siguientes en las columnas de la matriz determinan en donde están nuestros sujetos:
    1= cordero a la derecha, 2 lobo a la derecha, 3 lechuga a la derecha, 4 cordero a la izquierda, 5 lobo a la izquierda, 6 lechuga a la izquierda*/
    est.ent[1][1]=1;
    est.ent[1][2]=1;
    est.ent[1][3]=1;
    final=Barco(est,1,0);
    for(i=1;i<=final.u;i++){
        LeerEstado(final,i);
    }
    return 0;
}

//Definiendo la función que lee el estado que se le indique
int LeerEstado(ESTADO est, int actual){
    int i;
    printf("Estado número %d:\n",actual);
    if(est.ent[actual][1]==0 && est.ent[actual][2]==0 && est.ent[actual][3]==0){
        printf("No hay nada en el lado derecho, todos están en el lado izquierdo\n");
        return 0;
    }
    if(est.ent[actual][4]==0 && est.ent[actual][5]==0 && est.ent[actual][6]==0){
        printf("No hay nada en el lado izquierdo, todos están en el lado derecho\nMoviendo... UuU\n");
        return 0;
    }
    for(i=1; i<=6; i++){
        if(est.ent[actual][i]==1){ //Sólo deja pasar a escribir los que tienen un valor no nulo en la matriz
            switch(i){
                case 1:
                    printf("El corderito está en el lado derecho. ");
                    break;
                case 2:
                    printf("El lobo está en el lado derecho. ");
                    break;
                case 3:
                    printf("Las lechugas son verdes y están en el lado derecho. ");
                    break;
                case 4:
                    printf("El corderito está en el lado izquierdo. ");
                    break;
                case 5:
                    printf("El lobo está en el lado izquierdo. ");
                    break;
                case 6:
                    printf("Las lechugas son verdes y están en el lado izquierdo. ");
                    break;
            }
        }
    }
    printf("\nMoviendo... UuU\n");
    return 0;
}
//Definiedo la función que nos indica que no se repite un estado pasado
int NoRepetir(ESTADO est, int actual){
    int i,j, aux=0;
    for(j=1;j<actual; j++){
        for(i=1;i<=6;i++){
            if(est.ent[j][i]==est.ent[actual][i]){
                aux++;
            }
        }
        if(aux==6){
            return 0;
        }
        aux=0;
    }
    return 1;
}
//Definiendo la función si hay conflicto
int Conflicto(ESTADO est, int actual){
    if((est.ent[actual][1]==1 && est.ent[actual][2]==1)||(est.ent[actual][1]==1 && est.ent[actual][3]==1)||(est.ent[actual][4]==1 && est.ent[actual][5]==1)||(est.ent[actual][4]==1 && est.ent[actual][6]==1)){
        return 1;
    }else{
        return 0;
    }
}
//Definiendo la función que nos movera a los sujetos de un lado a otro xd
ESTADO Barco(ESTADO est, int actual, int error){
    int a,i;
    a=NoRepetir(est, actual);
    //LeerEstado(est,actual);
    if(est.ent[actual][1]==1 && est.ent[actual][2]==0 && est.ent[actual][3]==0){//caso limite, el que rompe la recursion
        for(i=0;i<=6;i++){
            est.ent[actual+1][i]=est.ent[actual][i];
        }
        est.ent[actual+1][1]=0;
        est.ent[actual+1][4]=1;
        //LeerEstado(est,actual+1);
        est.u=actual+1;
        return est;
    }
    if(a==0){
        return Barco(est, actual-1, 1);//en caso de que se repita el estado, vuelve a intentarlo moviendo primero otra cosa
    }
    if(error==1){//busca la corrección moviendo al lobo
        if(est.ent[actual][2]==1){
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][2]=0;
            est.ent[actual+1][5]=1;
            return Barco(est,actual+1,0);
        }else{
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][2]=1;
            est.ent[actual+1][5]=0;
            return Barco(est,actual+1,0);
        }
    }
    if(Conflicto(est,actual)==1){//si hay conflicto, mueve al cordero
        if(est.ent[actual][1]==1){
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][1]=0;
            est.ent[actual+1][4]=1;
            return Barco(est,actual+1,0);
        }else{
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][1]=1;
            est.ent[actual+1][4]=0;
            return Barco(est,actual+1,0);
        }
    }else{//si no hay conflicto, mueve las lechugas
        if(est.ent[actual][3]==1){
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][3]=0;
            est.ent[actual+1][6]=1;
            return Barco(est,actual+1,0);
        }else{
            for(i=0;i<=6;i++){
                est.ent[actual+1][i]=est.ent[actual][i];
            }
            est.ent[actual+1][3]=1;
            est.ent[actual+1][1]=0;
            return Barco(est,actual+1,0);
        }
    }
}
