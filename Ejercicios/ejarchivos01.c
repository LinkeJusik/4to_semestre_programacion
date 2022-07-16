#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE * fin, *fout;
    char linea[4096], *paux;

    printf("Por leer un archivo\n");
    fin = fopen("info.txt", "rt");
    if(fin == NULL){
        int mierror=errno;
        printf("Error al abrir el archvio: %d, <<%s>>\n", mierror,  strerror(mierror));
        return 0;
    }

    if((fout = fopen("info.sal", "wt")) == NULL){
        int mierror=errno;
        fclose(fin);
        printf("Error al abrir el archvio: %d, <<%s>>\n", mierror,  strerror(mierror));
        return 0;
    }

    while(!feof(fin)){
        if(fscanf(fin, "%[^\n]%*c", linea)<1){break;}
        if(strncmp(linea, "hola", 4)==0){
            fprintf(fout, "mundo%s\n", linea+4);
        }else{
            fprintf(fout, "%s\n", linea);
        }
    }

    printf("Se termino de recorrer el archvivo de entrada\n");
    fclose(fin);
    fclose(fout);

    printf("\nFin del programa\n");
    system("pause");
    return 0;
}