#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>
#define LONGMAX 128

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples};                                                             
typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

char *ModoIndicativoSimple[]={"Presente", "Preterito", "Futuro", "Copreterito", "Postpreterito"};  
              
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an      ","an      ",
									   "e       ","aste    ","o       ","amos    ","aron    ","aron    ",
									   "are     ","aras    ","ara     ","aremos  ","aran    ","aran    ",
									   "aba     ","abas    ","aba     ","abamos  ","aban    ","aban    ",                                                              
                                       "aria    ","arias   ","aria    ","ariamos ","arian   ","arian   "};
                           									   									                                         
char *ModoIndicativoComp[]={"Antepresente", "Antepreterito", "Antefuturo", "Antecopreterito", "Antepospreterito"};   

enBasePronombres AuxComp= {"he       ","has      ","ha       ","hemos    ","han      ","han      ",
	                       "hube     ","hubiste  ","hubo     ","hubimos  ","hubieron ","hubieron ",
						   "habre    ","habras   ","habra    ","habremos ","habran   ","habran   ",
						   "habia    ","habias   ","habia    ","habiamos ","habian   ","habian   ",                                                                            
                           "habria   ","habrias  ","habria   ","habriamos","habrian  ","habrian  "}; 

char *ModoSubjuntivoSimple[]={"Presente", "preterito", "Futuro"}; 

        enBasePronombres SubSimpleAR= {"e       ","es      ","e       ","emos    ","en      ","en      ",
									   "ara     ","aras    ","ara     ","aramos  ","aran    ","aran    ",
									   "are     ","ares    ","are     ","aremos  ","aren    ","aren    "};
									   
char *ModoSubjuntivoComp[]={"Antepresente", "Antepreterito", "Antefuturo"};  

        enBasePronombres AuxSubComp=  {"haya      ","hayas     ","haya      ","hayamos   ","hayan     ","hayan     ",
									   "hubiera   ","hubieras  ","hubiera   ","hubieramos","hubieran  ","hubieran  ",
									   "hubiere   ","hubieres  ","hubiere   ","hubieremos","hubieren  ","hubieren  "};
                                    
char *ModoParticipio[]={"Participio"}; 

char *ModoGerundio[]={"Gerundio"};  

char *ModoImperativo[]={"Imperativo"}; 
enBasePronombres SubImAR=  {"a "};
		                                     
enBasePronombres Pronombres = {"yo", "tu", "el", "nosotros", "ustedes", "ellos"};                                                                            
int conjugacionRegularAR(FILE *archivo, char raizVerboAR[]);                                                                   
int conjugacionRegularDEF(FILE *archivo);

int main(int argc, char *argv[]){                            
  FILE *miArchivo;              
  char palabra[128],norc[128];             
  int aux;
  char a; 
  int i,n;
                                       
  printf("Conjugacion de verbos regulares en terminacion 'ar'\n\n");
  printf("\nIntroduzca el verbo: ");
  scanf("%s", palabra);
  aux = strlen(palabra);
  sprintf(norc,"%s.txt",palabra);	
  miArchivo = fopen(norc, "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se puede abrir el archivo \"verbo.txt\"\n");
    return 0;                                                          
  }                               
  printf("\n");
  fprintf(miArchivo,"Conjugacion de verbos en terminacion 'ar'\nEl verbo es: %s\n\n",palabra);
  if(palabra[aux-2]=='a'){
  
palabra[aux-2]= '\0'; 
printf("Conjugando\t.\t.\t.\n");	
conjugacionRegularAR(miArchivo, palabra);  
printf("Proceso terminado :)\n");
	
}
else printf("Ingrese un verbo con terminacion regular 'ar'");
fclose(miArchivo);
  printf("\n\n");
system("pause");
  return 0;
} 

int conjugacionRegularAR(FILE *archivo, char raizVerboAR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboAR)+2;
  
fprintf(archivo,"\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], 
    		        raizVerboAR, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
  
fprintf(archivo,"\tIndicativo Compuesto\n");
for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sado", Pronombres[persona], 
    		        AuxComp[tiempo],raizVerboAR); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
  
 fprintf(archivo,"\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   { 
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboAR, SubSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
  
 fprintf(archivo,"\tSubjuntivo Compuesto\n");
for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubjuntivoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoSubjuntivoComp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sado", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++)
   {
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sado",raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
 
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
	    
   }
	  
  for (persona=0; persona<TotalPronombres-5; persona++)
   {
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sando",raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++)
   {
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboAR, SubImAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
                                              
  return 0;  
}            