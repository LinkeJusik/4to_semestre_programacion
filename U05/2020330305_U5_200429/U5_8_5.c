#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>

typedef struct _info_{
    char cadena1[1024], cadena2[1024];
	int entero1, entero2;
	double real;
}INFO;

typedef struct _elemento_lista_{
    INFO info;
    struct _elemento_lista_ *sig;
}ELE;


typedef ELE *LISTA;
int eliminar(INFO info, LISTA *pl);
int vaciar(LISTA *pl);
int mostrar(LISTA l);
int insertar(INFO info, LISTA *pl);

int main(int argc, char *argv[]){
	LISTA l=NULL;
	
	int i, n, aux,k=0;
	INFO info;
	
	while(k==0){
		printf("Digite el número asociado a una de las siguientes opciones:\n");
		printf("1. Insertar elemento a la lista\n2. Eliminar elemento de la lista\n3. Ver la lista\n4. Limpiar pantalla\n5. Salir\n"); scanf("%d",&aux);

		switch (aux){
			case 1: 
				printf("Ingrese los siguientes datos:\n");
	            printf("Digite la primer cadena: "); scanf("%s", &(info.cadena1));
		        printf("Digite la segunda cadena: "); scanf("%s", &(info.cadena2));
		        printf("Digite el primer entero: "); scanf("%d", &(info.entero1));
		        printf("Digite el segundo entero: "); scanf("%d", &(info.entero2));
		        printf("Digite el real:"); scanf("%lg", &(info.real));
		        insertar(info, &l); 
	            break;
		case 2: 
		    	eliminar(info, &l);
		        break;
		case 3: mostrar(l);
		        break;
		case 4: system("cls");
				break;
		case 5: k=1;
		default: printf("Opcion invalida.\n");
		        break;
		}
		printf("\n");
	}
	return 0;
}

int insertar(INFO info, LISTA *pl){
	ELE *pel;
	LISTA l;
    long unsigned int aux1, aux2;
    int bul1=0, bul2=0, bul3=0, bul4=0, i;
	
	if(pl==NULL){
		printf("Error,La lista no puede ser nula. \n");
	}
	pel=(ELE*)malloc(sizeof(ELE));
	if((pel=(ELE*)malloc(sizeof(ELE)))==NULL){
		int mierr=errno;
		printf("Error de espacio en memoria: %d <<%s>>\n", mierr, strerror(mierr));
		return -1;
	}
	pel->info=info;
	pel->sig=NULL;

	if(*pl==NULL){
		*pl=pel; 
		return 0;
	}

	//-----------------------------------//
    if(strlen(pel->info.cadena1)>=strlen((*pl)->info.cadena1)){
	    aux1=strlen(pel->info.cadena1);
	}else{
	    aux1=strlen((*pl)->info.cadena1);
	}
	
	for(i=0; i<aux1; i++){
	    if(pel->info.cadena1[i]!=(*pl)->info.cadena1[i]){
	        if(pel->info.cadena1[i]>(*pl)->info.cadena1[i]){
	            bul1 = 1;
	            i=10000;
	        }else{
	            bul1 = 2;
	            i=10000;
	        }
	    }
	}

    if(strlen(pel->info.cadena2)>=strlen((*pl)->info.cadena2)){
	    aux2=strlen(pel->info.cadena2);
	}else{
	    aux2=strlen((*pl)->info.cadena2);
	}
	
	for(i=0; i<aux2; i++){
	    if(pel->info.cadena2[i]!=(*pl)->info.cadena2[i]){
	        if(pel->info.cadena2[i]>(*pl)->info.cadena2[i]){
	            bul2 = 1;
	            i=10000;
	        }else{
	            bul2 = 2;
	            i=10000;
	        }
	    }
	}

	//-----------------------------------//
    if(bul1==2){
        pel->sig=*pl; 
		*pl=pel;
		return 0;
    }
    if(bul1==0 && bul2==1){
        pel->sig=*pl; 
		*pl=pel;
		return 0;
    }

    if(bul2==0){
        if(pel->info.entero1<(*pl)->info.entero1){
		pel->sig=*pl; 
		*pl=pel;
		return 0;
	    }
    }

	if(pel->info.entero1==(*pl)->info.entero1){
		if(pel->info.entero2>(*pl)->info.entero2){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
	}
    if(pel->info.entero2==(*pl)->info.entero2){
        if(pel->info.real<(*pl)->info.real){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
    }
    if(pel->info.real==(*pl)->info.real){
        printf("Este  elemento ya esta adentro\nR E C H A Z A D O\n");
        return 0;
    }
	l=*pl;
    //-----------------------------------//
    if(strlen(pel->info.cadena1)>=strlen(l->sig->info.cadena1)){
	    aux1=strlen(pel->info.cadena1);
	}else{
	    aux1=strlen(l->sig->info.cadena1);
	}
	
	for(i=0; i<aux1; i++){
	    if(pel->info.cadena1[i]!=l->sig->info.cadena1[i]){
	        if(pel->info.cadena1[i]>l->sig->info.cadena1[i]){
	            bul3 = 1;
	            i=10000;
	        }else{
	            bul3 = 2;
	            i=10000;
	        }
	    }
	}

    if(strlen(pel->info.cadena2)>=strlen(l->sig->info.cadena2)){
	    aux2=strlen(pel->info.cadena2);
	}else{
	    aux2=strlen(l->sig->info.cadena2);
	}
	
	for(i=0; i<aux2; i++){
	    if(pel->info.cadena2[i]!=l->sig->info.cadena2[i]){
	        if(pel->info.cadena2[i]>l->sig->info.cadena2[i]){
	            bul4 = 1;
	            i=10000;
	        }else{
	            bul4 = 2;
	            i=10000;
	        }
	    }
	}

	//-----------------------------------//

	while(l->sig!=NULL){
		if(bul3==2){
			pel->sig=l->sig;
			l->sig=pel;
			return 0;
		} 
	
		if(bul3==0){ 
			if(bul2==1){
        pel->sig=*pl; 
		*pl=pel;
		return 0;
    }

    if(bul2==0){
        if(pel->info.entero1<(*pl)->info.entero1){
		pel->sig=*pl; 
		*pl=pel;
		return 0;
	    }
    }

	if(pel->info.entero1==(*pl)->info.entero1){
		if(pel->info.entero2>(*pl)->info.entero2){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
	}
    if(pel->info.entero2==(*pl)->info.entero2){
        if(pel->info.real<(*pl)->info.real){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
    }
    if(pel->info.real==(*pl)->info.real){
        printf("Este  elemento ya esta adentro\nR E C H A Z A D O\n");
        return 0;
    }
		}

        if(bul4==1){
            pel->sig=l->sig;
			l->sig=pel;
			return 0;
        }

        if(bul4==0){
            if(pel->info.entero1<(*pl)->info.entero1){
		pel->sig=*pl; 
		*pl=pel;
		return 0;
	    }
    

	if(pel->info.entero1==(*pl)->info.entero1){
		if(pel->info.entero2>(*pl)->info.entero2){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
	}
    if(pel->info.entero2==(*pl)->info.entero2){
        if(pel->info.real<(*pl)->info.real){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
    }
    if(pel->info.real==(*pl)->info.real){
        printf("Este  elemento ya esta adentro\nR E C H A Z A D O\n");
        return 0;
    }
        }

        if(pel->info.entero1<l->sig->info.entero1){
            pel->sig=l->sig;
			l->sig=pel;
			return 0;
        }

        if(pel->info.entero1==l->sig->info.entero1){
            if(pel->info.entero2>(*pl)->info.entero2){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
	
    if(pel->info.entero2==(*pl)->info.entero2){
        if(pel->info.real<(*pl)->info.real){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
    }
    if(pel->info.real==(*pl)->info.real){
        printf("Este  elemento ya esta adentro\nR E C H A Z A D O\n");
        return 0;
    }
        }

        if(pel->info.entero2>l->sig->info.entero2){
            pel->sig=l->sig;
			l->sig=pel;
			return 0;
        }

        if(pel->info.entero2==l->sig->info.entero2){
            if(pel->info.real<(*pl)->info.real){
		    pel->sig=*pl; 
		    *pl=pel;
		    return 0;
	    }
    
    if(pel->info.real==(*pl)->info.real){
        printf("Este  elemento ya esta adentro\nR E C H A Z A D O\n");
        return 0;
    }
        }
		l=l->sig;
	}
	l->sig=pel;
	return 0;
}

int eliminar(INFO info, LISTA *pl){
	ELE *pel;
	LISTA l;
	
	if(pl==NULL) return -1;
	if(*pl==NULL) return -2;
	pel=*pl;

		printf("La siguiente informacion se borrara: \n");
		printf("%3d. [%s, %s, %3d, %3d, %3lg]\n", 1,pel->info.cadena1, pel->info.cadena2, pel->info.entero1, pel->info.entero2, pel->info.real);
		
		*pl=(*pl)->sig; 

		pel->sig=NULL;
		pel->info.entero1=0;
		pel->info.entero2=0;
		pel->info.real=0.0;
		memset(pel->info.cadena1, 0, sizeof(pel->info.cadena1)); 
		memset(pel->info.cadena2, 0, sizeof(pel->info.cadena2)); 

		free(pel);
		pel=NULL;
		return 0;
}
int mostrar(LISTA l){
	int i=1;
	if(l==NULL){
	printf("(vacia)\n");
	return 0;
	}
	while(l!=NULL){
		printf("%3d. [%s, %s, %3d, %3d, %3lg]\n", i,l->info.cadena1, l->info.cadena2, l->info.entero1, l->info.entero2, l->info.real);
		l=l->sig;
		i++;
	}
	return 0;
}
int vaciar(LISTA *pl){
	LISTA l;
	ELE *pel;
	
	if(pl==NULL) return -1;
	l=*pl;
	while(l!=NULL){
		pel=l;
		l=l->sig;

		pel->sig=NULL;
		pel->info.entero1=0;
		pel->info.entero2=0;
		pel->info.real=0.0;
		memset(pel->info.cadena1, 0, sizeof(pel->info.cadena1));
		memset(pel->info.cadena2, 0, sizeof(pel->info.cadena2)); 

		free(pel);
		pel=NULL;
	}
	*pl=NULL;
	return 0;	
}