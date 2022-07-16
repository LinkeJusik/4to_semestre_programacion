#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples};                                                             
#define LONGMAX 128
typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

//INDICATIVO SIMPLE
char *ModoIndicativoSimple[]={"Presente", "Pret�rito", "Futuro",
                             "Copret�rito", "Postpret�rito"};  
//irregulares                           
//ADQUIRIR*                          
enBasePronombres DesidenciaSimpleAD = {"ero      ","res      ","re       ","rimos    ","ren      ","ren      ",
									   "r�       ","riste    ","ri�      ","rimos    ","rieron   ","rieron   ",
									   "rir�     ","rir�s    ","rir�     ","riremos  ","rir�n    ","rir�n    ",
									   "r�a      ","r�as     ","r�a      ","r�amos   ","r�an     ","r�an     ",                                                          
                                       "rir�a    ","rir�as   ","rir�a    ","rir�amos ","rir�an   ","r�an     "};                                      
//YACER*                                      
enBasePronombres DesidenciaSimpleYA = {"zco      ","zcas     ","zca      ","zcamos   ","zcan     ","zcan     ",
									   "c�       ","ciste    ","ci�      ","cimos    ","cieron   ","cieron   ",
									   "cer�     ","cer�s    ","cer�     ","ceremos  ","cer�n    ","cer�n    ",
									   "c�a      ","c�as     ","c�a      ","c�amos   ","c�an     ","c�an     ",                                                           
                                       "cer�a    ","cer�as   ","cer�a    ","cer�amos ","cer�an   ","cer�an   "};
//SONAR*									                                         
enBasePronombres DesidenciaSimpleSO = {"ueno     ","uenas    ","uena     ","onamos   ","uenan    ","uenan    ",
									   "on�      ","onaste   ","on�      ","onamos   ","onaron   ","onaron   ",
									   "onar�    ","onar�s   ","onar�    ","onaremos ","onar�n   ","onar�n   ",
									   "onaba    ","onabas   ","onaba    ","on�bamos ","onaban   ","onaban   ",                                                                            
                                       "onar�a   ","onar�as  ","onar�a   ","onar�amos","onar�an  ","onar�an  "};
//TRAER*                                       
enBasePronombres DesidenciaSimpleTR = {"igo     ","es      ","e       ","emos    ","en      ","en      ",    
									   "je      ","jiste   ","jo      ","jimos   ","jeron   ","jeron   ",
									   "er�     ","er�s    ","er�     ","eremos  ","er�n    ","er�n    ",
									   "�a      ","�as     ","�a      ","�amos   ","�an     ","�an     ",                                                                            
                                       "er�a    ","er�as   ","er�a    ","er�amos ","er�an   ","er�an   "};
//PLACER*                                                                          
enBasePronombres DesidenciaSimplePL = {"zco     ","ces     ","ce      ","cemos   ","cen     ","cen     ",
									   "c�      ","ciste   ","ci�     ","cimos   ","cieron  ","cieron  ",
									   "cer�    ","cer�s   ","cer�    ","ceremos ","cer�n   ","cer�n   ",
									   "c�a     ","c�as    ","c�a     ","c�amos  ","c�an    ","c�an    ",                                                                            
                                       "cer�a   ","cer�as  ","cer�a   ","cer�amos","cer�an  ","cer�an  "};
//ASIR*                                      
enBasePronombres DesidenciaSimpleAS = {"go      ","es      ","e       ","imos    ","�s      ","�s      ",
									   "�       ","iste    ","i�      ","imos    ","ieron   ","ieron   ",
									   "ir�     ","ir�s    ","ir�     ","iremos  ","ar�n    ","ar�n    ",
									   "�a      ","�as     ","�a      ","�amos   ","�an     ","a�an    ",                                                                            
                                       "ir�a    ","ir�as   ","ir�a    ","ir�amos ","ir�an   ","ir�an   "};									    									    
//MECER*                                       
enBasePronombres DesidenciaSimpleME = {"zo      ","ces     ","ce      ","cemos   ","cen     ","cen     ",
									   "c�      ","ciste   ","ci�     ","cimos   ","cieron  ","cieron  ",
									   "cer�    ","cer�s   ","cer�    ","ceremos ","cer�n   ","cer�n   ",
									   "c�a     ","c�as    ","c�a     ","c�amos  ","c�an    ","c�an    ",                                                                            
                                       "cer�a   ","cer�as  ","cer�a   ","cer�amos","cer�an  ","cer�an  "}; 
//regulares									    
//AR*
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an      ","an      ",
									   "�       ","aste    ","�       ","amos    ","aron    ","aron    ",
									   "ar�     ","ar�s    ","ar�     ","aremos  ","ar�n    ","ar�n    ",
									   "aba     ","abas    ","aba     ","abamos  ","aban    ","aban    ",                                                               
                                       "ar�a    ","ar�as   ","ar�a    ","ar�amos ","ar�an   ","ar�an   "};
//ER*
enBasePronombres DesidenciaSimpleER = {"o       ","es      ","e       ","emos    ","en      ","en      ", 
									   "�       ","iste    ","i�      ","imos    ","ieron   ","ieron   ",
									   "er�     ","er�s    ","er�     ","eremos  ","er�n    ","er�n    ",
									   "�a      ","�as     ","�a      ","�amos   ","�an     ","�an     ",                                                                            
                                       "er�a    ","er�as   ","er�a    ","er�amos ","er�an   ","er�an   "};
//IR*
enBasePronombres DesidenciaSimpleIR = {"o       ","es      ","e       ","imos    ","en      ","en      ",
									   "�       ","iste    ","i�      ","imos    ","ieron   ","ieron   ",
									   "ir�     ","ir�s    ","ir�     ","iremos  ","ir�n    ","ir�n    ",
									   "�a      ","�as     ","�a      ","�amos   ","�an     ","�an     ",                                                                            
                                       "ir�a    ","ir�as   ","ir�a    ","ir�amos ","ir�an   ","ir�an   "};                                    
//INDICATIVO COMPUESTO									   									                                         
char *ModoIndicativoComp[]={"Antepresente", "Antepret�rito", "Antefuturo",
                             "Antecopret�rito", "Antepospret�rito"};    
                             
enBasePronombres AuxComp= {"he       ","has      ","ha       ","hemos    ","han      ","han      ",
	                       "hube     ","hubiste  ","hubo     ","hubimos  ","hubieron ","hubieron ",
						   "habr�    ","habr�s   ","habr�    ","habremos ","habr�n   ","habr�n   ",
						   "hab�a    ","hab�as   ","hab�a    ","hab�amos ","hab�an   ","hab�an   ",                                                                            
                           "habr�a   ","habr�as  ","habr�a   ","habr�amos","habr�an  ","habr�an  "}; 
//SUBJUNTIVO SIMPLE
char *ModoSubjuntivoSimple[]={"Presente", "Pret�rito", "Futuro"};  
//irregulares
//ADQUIRIR
        enBasePronombres SubSimpleAD= {"era     ","eras    ","era     ","ramos   ","ran     ","ran     ", 
									   "riera   ","rieras  ","riera   ","ri�ramos","rieran  ","rieran  ",
									   "riere   ","rieres  ","riere   ","ri�remos","rieren  ","rieren  "};
//TRAER									   	
        enBasePronombres SubSimpleTR= {"iga     ","igas    ","iga     ","igamos  ","igan    ","igan    ",
									   "jera    ","jeras   ","jera    ","j�ramos ","jeran   ","jeran   ",
									   "jere    ","jeres   ","jere    ","j�remos ","jeren   ","jeren   "};
//YACER									   
        enBasePronombres SubSimpleYA= {"zca     ","zcas    ","zca     ","zcamos  ","zcan    ","zcan    ",
									   "ciera   ","cieras  ","ciera   ","ci�ramos","cieran  ","cieran  ",
									   "ciere   ","cieres  ","ciere   ","ci�remos","cieren  ","cieren  "};
//SONAR									   								  										 								   
        enBasePronombres SubSimpleSO= {"uene     ","uenes    ","uene     ","onemos   ","uenen    ","uenen    ",
									   "onara    ","onaras   ","onara    ","on�ramos ","onaran   ","onaran   ",
									   "onare    ","onares   ","onare    ","on�remos ","onaren   ","onaren   "};
//PLACER									   
        enBasePronombres SubSimplePL= {"zco     ","zcas    ","zca     ","zcamos  ","zcan    ","zcan    ",
									   "ciera   ","cieras  ","ciera   ","ci�ramos","cieran  ","cieran  ",
									   "ciere   ","cieres  ","ciere   ","ci�remos","cieren  ","cieren  "};
//ASIR									
        enBasePronombres SubSimpleAS= {"ga      ","gas     ","ga      ","gamos   ","gan     ","gan     ",
									   "iera    ","ieras   ","iera    ","i�ramos ","ieran   ","ieran   ",
									   "iere    ","ieres   ","iere    ","i�remos ","ieren   ","ieren   "};
//MECER									   									   									    
		enBasePronombres SubSimpleME= {"za      ","zas     ","za      ","zamos   ","zan     ","zan     ",
									   "ciera   ","cieras  ","ciera   ","ci�ramos","cieran  ","cieran  ",
									   "ciere   ","cieres  ","ciere   ","ci�remos","cieren  ","cieren  "};
//regulares									   	
//AR
enBasePronombres SubSimpleAR= {"e       ","es      ","e       ","emos    ","en      ","en      ",
									   "ara     ","aras    ","ara     ","�ramos  ","aran    ","aran    ",
									   "are     ","ares    ","are     ","�remos  ","aren    ","aren    "};
//ER
enBasePronombres SubSimpleER= {"a       ","as      ","a       ","amos    ","an      ","an      ",
									   "iera    ","ieras   ","iera    ","i�ramos ","ieran   ","ieran   ",
									   "iere    ","ieres   ","iere    ","i�remos ","ieren   ","ieren   "};
//IR 									 						   
enBasePronombres SubSimpleIR= {"a       ","as      ","a       ","amos    ","an      ","an      ",
									   "iera    ","ieras   ","iera    ","i�ramos ","ieran   ","ieran   ",
									   "iere    ","ieres   ","iere    ","i�remos ","ieren   ","ieren   "};
//SUBJUNTIVO COMPUESTO									   									   							                                 
char *ModoSubjuntivoComp[]={"Antepresente", "Antepret�rito", "Antefuturo"};  

        enBasePronombres AuxSubComp=  {"haya      ","hayas     ","haya      ","hayamos   ","hayan     ","hayan     ",
									   "hubiera   ","hubieras  ","hubiera   ","hubi�ramos","hubieran  ","hubieran  ",
									   "hubiere   ","hubieres  ","hubiere   ","hubi�remos","hubieren  ","hubieren  "};
                                      
char *ModoParticipio[]={"Participio"};  
char *ModoGerundio[]={"Gerundio"};  
char *ModoImperativo[]={"Imperativo"}; 
//IMPERATIVO
enBasePronombres SubImAD=  {"era "};
enBasePronombres SubImYA=  {"zca"};
enBasePronombres SubImTR=  {"e"};
enBasePronombres SubImSO=  {"uena"};
enBasePronombres SubImPL=  {"zca"};
enBasePronombres SubImAS=  {"e"};
enBasePronombres SubImME=  {"za"};	
enBasePronombres SubImAR=  {"a "};	
enBasePronombres SubImER=  {"e"};
enBasePronombres SubImIR=  {"e"};	                                     
enBasePronombres Pronombres = {"yo", "t�", "�l", "nosotros", "ustedes", "ellos"};     
//funciones                                                                      
int conjugacionRegularAR(FILE *archivo, char raizVerboAR[]); 
int conjugacionRegularER(FILE *archivo, char raizVerboER[]);
int conjugacionRegularIR(FILE *archivo, char raizVerboIR[]);
int conjugacionRegularAD(FILE *archivo, char raizVerboAD[]); 
int conjugacionRegularSO(FILE *archivo, char raizVerboSO[]);  
int conjugacionRegularME(FILE *archivo, char raizVerboME[]); 
int conjugacionRegularYA(FILE *archivo, char raizVerboYA[]);   
int conjugacionRegularTR(FILE *archivo, char raizVerboTR[]);
int conjugacionRegularPL(FILE *archivo, char raizVerboPL[]);
int conjugacionRegularAS(FILE *archivo, char raizVerboAS[]);                                                             
int conjugacionRegularDEF(FILE *archivo);

//main
int main(int argc, char *argv[])
{                            
  FILE *miArchivo;              
  char buffer[128];             
  int lbuffer;
  char a;                 
  int i,n;
  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("*****CONJUGACI�N DE VERBOS****\n\n");
  printf("Modelos de verbos irregulares:\n");
  printf("1.yacer, subyacer, adyacer, entreyacer\n\n");	
  printf("2.traer,extraer,contraer,desatraer,retraer,substraer,atraer,bistraer,retrotraer,\n" "maltraer,detraer,distraer,subtraer,sustraer,dentrotraer,abstraer\n\n");
  printf("3.placer,complacer,aplacer,desplacer,displacer\n\n");	
  printf("4.asir,desasir\n\n");	
  printf("5.adquirir, readquirir, coadquirir, perquirir, pesquirir, inquirir\n\n");
  printf("6.sonar,resonar,retronar,asonar,tronar,consonar,atronar,grandisonar,disonar\n\n");
  printf("7.mecer,vencer,ejercer,ercer,remecercer,revencer,contremecer,convencer,coercer\n\n");
  printf("\nIntroduzca el verbo:");
  scanf("%s", buffer);
  printf("\n");
  lbuffer = strlen(buffer);	
  fprintf(miArchivo,"\t\t\t\t\t*****CONJUGACI�N DE VERBOS****\nConjugaci�n del verbo %s\n\n",buffer);
  
  //YACER
  if(strncmp(buffer+lbuffer-5,"yacer",5)==0){   
  if(strncmp(buffer,"yacer",5)==0)fprintf(miArchivo,"Yacer:estar echada o tendida horizontalmente [una persona].\n");		
  else if(strncmp(buffer,"subyacer",8)==0)fprintf(miArchivo,"Subyacer:estar [una cosa] por debajo de otra o supeditada a ella ocultamente.\n");
  else if(strncmp(buffer,"adyacer",5)==0)fprintf(miArchivo,"Adyacer:situar junto, poner al justo al lado.\n");		
  else if(strncmp(buffer,"entreyacer",8)==0)fprintf(miArchivo,"Entreyacer:mediar, intervenir, interceder o moderar, en estar ubicado la cosa o elemento en la mitad o tambi�n estar en medio, n�cleo o la parte central o llamado tambi�n el centro.\n");	 
  
  buffer[lbuffer-3]= '\0';                    
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularYA(miArchivo,buffer);
  printf("Verbo Conjugado\n\n"); 
  }
  
  //TRAER          
  else if(strncmp(buffer+lbuffer-5,"traer",5)==0){
  if(strncmp(buffer,"traer",5)==0)fprintf(miArchivo,"Traer:llevar a una persona o una cosa hasta el lugar en que est� quien habla.\n");
  if(strncmp(buffer,"extraer",7)==0)fprintf(miArchivo,"Extraer:sacar una cosa que est� incrustada, hundida, contenida o sepultada en otra, generalmente venciendo una dificultad.\n");		
  if(strncmp(buffer,"contraer",8)==0)fprintf(miArchivo,"Contraer:hacer que algo tenga menor volumen u ocupe menos extensi�n sin variar su masa.\n");
  if(strncmp(buffer,"desatraer",9)==0)fprintf(miArchivo,"Desatraer:apartar, separar algo de otra cosa.\n");
  if(strncmp(buffer,"retraer",7)==0)fprintf(miArchivo,"Retraer:disuadir a una persona de hacer algo.\n");
  if(strncmp(buffer,"substraer",9)==0)fprintf(miArchivo,"Substraer:alejar, sacar, apartar, extraer, dividir o apartar alguna cosa.\n");
  if(strncmp(buffer,"atraer",6)==0)fprintf(miArchivo,"Atraer:acercar y retener [un cuerpo] a otro debido a sus propiedades f�sicas.\n");
  if(strncmp(buffer,"bistraer",8)==0)fprintf(miArchivo,"Bistraer:dar dinero de antemano o tomarlo.\n");
  if(strncmp(buffer,"retrotraer",10)==0)fprintf(miArchivo,"Retrotraer:hacer que una persona retroceda mentalmente a un tiempo o �poca pasada.\n");
  if(strncmp(buffer,"maltraer",8)==0)fprintf(miArchivo,"Maltraer:maltratar, injuriar [a alguien].\n");
  if(strncmp(buffer,"detraer",7)==0)fprintf(miArchivo,"Detraer:restar o sustraer una parte de algo, especialmente una cantidad de dinero.\n");
  if(strncmp(buffer,"distraer",8)==0)fprintf(miArchivo,"Distraer:atraer la atenci�n de alguien haciendo que la aparte de lo que estaba haciendo o de lo que ten�a que hacer.\n");
  if(strncmp(buffer,"subtraer",8)==0)fprintf(miArchivo,"Subtraer: verbo anticuado variante de �substraer� y, m�s actualmente, de �sustraer� que significa: separar, extraer.\n");
  if(strncmp(buffer,"sustraer",8)==0)fprintf(miArchivo,"Sustraer:apartar o separar a alguien o algo de lo que forma parte.\n");
  if(strncmp(buffer,"dentrotraer",11)==0)fprintf(miArchivo,"Dentrotraer:Meter, introducir.\n");
  if(strncmp(buffer,"abstraer",8)==0)fprintf(miArchivo,"Abstraer:separar por medio de una operaci�n intelectual una cualidad de la cosa en la que existe y considerarla aisladamente de esta cosa.\n");

  buffer[lbuffer-2]= '\0';                    
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularTR(miArchivo,buffer);
  printf("Verbo Conjugado\n\n"); 
  } 
  
  //PLACER*
  else if(strncmp(buffer+lbuffer-6,"placer",6)==0){   
  if(strncmp(buffer,"placer",6)==0)fprintf(miArchivo,"Placer:1.Causar [una cosa] satisfacci�n o una sensaci�n agradable a alguien; 2.Banco de arena o piedra en el fondo del mar, llano y de bastante extensi�n.\n");	
  if(strncmp(buffer,"complacer",9)==0)fprintf(miArchivo,"Complacer:producir placer o satisfacci�n a una persona.\n");
  if(strncmp(buffer,"aplacer",7)==0)fprintf(miArchivo,"Aplacer:agradar, contentar.\n");
  if(strncmp(buffer,"desplacer",9)==0)fprintf(miArchivo,"Desplacer:causar [lo que se expresa] disgusto en alguien.\n");
  if(strncmp(buffer,"displacer",9)==0)fprintf(miArchivo,"Displacer:disgustar, desagradar.\n");

  buffer[lbuffer-3]= '\0';                    
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularPL(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  }  
  
  //ASIR*
  else if(strncmp(buffer+lbuffer-4,"asir",4)==0){
  if(strncmp(buffer,"asir",4)==0)fprintf(miArchivo,"Asir:1.Tomar o agarrar a alguien o algo, especialmente con las manos; 2.Agarrarse a alguien o algo.\n");  		
  if(strncmp(buffer,"desasir",7)==0)fprintf(miArchivo,"Desasir:1.Soltar o desprender una cosa del lugar al que est� asida o sujeta; 2.Soltarse o desprenderse [una persona o una cosa] del lugar al que est� asido o sujeto.\n");
 
  buffer[lbuffer-2]= '\0';                    
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularAS(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  }        
  
  //ADQUIRIR   
  else if(strncmp(buffer+lbuffer-6,"quirir",6)==0){ //ND
  if(strncmp(buffer,"adquirir",8)==0)fprintf(miArchivo,"Adquirir:1.Llegar a tener o conseguir una cualidad, un conocimiento, un h�bito o una habilidad, de forma natural o tras un proceso; 2.Comprar una cosa, especialmente algo a lo que se atribuye un cierto valor.\n");          
  if(strncmp(buffer,"readquirir",10)==0)fprintf(miArchivo,"Readquirir:voltar a adquirir; recobrar.\n"); 	
  if(strncmp(buffer,"coadquirir",10)==0)fprintf(miArchivo,"Coadquirir:adquirir juntamente con otro o con otros.\n"); 	
  if(strncmp(buffer,"perquirir",9)==0)fprintf(miArchivo,"Perquirir:buscar o investigar una cosa con gran inter�s y cuidado.\n"); 	
  if(strncmp(buffer,"pesquirir",9)==0)fprintf(miArchivo,"Pesquirir:Investigar, buscar una cosa con cuidado y diligencia.\n"); 	
  if(strncmp(buffer,"inquirir",8)==0)fprintf(miArchivo,"Inquirir:Tratar de llegar al conocimiento de una cosa, especialmente a trav�s de preguntas.\n"); 	

  buffer[lbuffer-3]= '\0'; 
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularAD(miArchivo, buffer);  
  printf("Verbo Conjugado\n\n");	
  }

  //SONAR
  else if(strncmp(buffer+lbuffer-4,"onar",4)==0){ //ND
  if(strncmp(buffer,"sonar",5)==0)fprintf(miArchivo,"Sonar:emitir [una cosa] alg�n sonido o ruido.\n");          
  if(strncmp(buffer,"resonar",7)==0)fprintf(miArchivo,"Resonar:prolongarse o amplificarse [un sonido] por repercusiones repetidas.\n"); 	
  if(strncmp(buffer,"retronar",8)==0)fprintf(miArchivo,"Retronar:volver [alguien o algo] al lugar, situaci�n o estado anterior.\n"); 	
  if(strncmp(buffer,"asonar",6)==0)fprintf(miArchivo,"Asonar:hacer asonancia dos o m�s sonidos entre s�.\n"); 	
  if(strncmp(buffer,"tronar",6)==0)fprintf(miArchivo,"Tronar:producirse o sonar truenos.\n"); 	
  if(strncmp(buffer,"consonar",8)==0)fprintf(miArchivo,"Consonar:1.Dicho de una palabra: Ser consonante de otra; 2.Dicho de algunas cosas: Tener igualdad, conformidad o relaci�n entre s�.\n"); 	
  if(strncmp(buffer,"atronar",7)==0)fprintf(miArchivo,"Atronar:producir [algo] un ruido semejante al trueno.\n"); 	
  if(strncmp(buffer,"grandisonar",11)==0)fprintf(miArchivo,"Grandisonar:que resuena con fuerza.\n"); 	
  if(strncmp(buffer,"disonar",7)==0)fprintf(miArchivo,"Disonar:ser disonante [un sonido o una m�sica].\n"); 	

  buffer[lbuffer-4]= '\0';                  
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularSO(miArchivo, buffer);
  printf("Verbo Conjugado\n\n");
  }

  //MECER 
  else if(strncmp(buffer+lbuffer-3,"cer",3)==0){  //ND
  if(strncmp(buffer,"mecer",5)==0)fprintf(miArchivo,"Mecer:mover de un lado a otro una cosa que est� suspendida de un punto fijo o est� apoyada sobre una superficie basculante.\n");          
  if(strncmp(buffer,"vencer",6)==0)fprintf(miArchivo,"Vencer:1.Resultar ganador en una competici�n o una lucha; 2.Superar con �xito un obst�culo, problema o dificultad.\n"); 	
  if(strncmp(buffer,"ejercer",7)==0)fprintf(miArchivo,"Ejercer:1.Realizar las funciones propias de una profesi�n, facultad, virtud, etc; 2.Hacer que una fuerza, una acci�n o un poder act�e sobre alguien o algo.\n"); 	
  if(strncmp(buffer,"ercer",5)==0)fprintf(miArchivo,"Ercer:levantar.\n"); 	
  if(strncmp(buffer,"remecercer",10)==0)fprintf(miArchivo,"Remecer:mover reiteradamente una cosa de un lado a otro.\n"); 	
  if(strncmp(buffer,"revencer",8)==0)fprintf(miArchivo,"Revencer:vencer plenamente.\n"); 	
  if(strncmp(buffer,"contremecer",11)==0)fprintf(miArchivo,"Contremecer:temblar.\n"); 	
  if(strncmp(buffer,"convencer",9)==0)fprintf(miArchivo,"Convencer:1.Conseguir con razones y argumentos que una persona act�e o piense de un modo determinado; 2.Ser del agrado de una persona.\n"); 	
  if(strncmp(buffer,"coercer",7)==0)fprintf(miArchivo,"Coercer:impedir a una persona que haga cierta cosa.\n"); 		

  buffer[lbuffer-3]= '\0';                  
  printf("Por conjugar verbo irregular...\n\n");
  conjugacionRegularME(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  }

  //AR
  else if(strncmp(buffer+lbuffer-2,"ar",2)==0){
  buffer[lbuffer-2]= '\0';                  
  printf("Por conjugar verbo regular...\n\n");
  conjugacionRegularAR(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  } 
  //ER
  else if(strncmp(buffer+lbuffer-2,"er",2)==0){
  buffer[lbuffer-2]= '\0';                  
  printf("Por conjugar verbo regular...\n\n");
  conjugacionRegularER(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  } 
  //IR 
  else if(strncmp(buffer+lbuffer-2,"ir",2)==0){
  buffer[lbuffer-2]= '\0';                  
  printf("Por conjugar verbo regular...\n\n");
  conjugacionRegularIR(miArchivo,buffer);
  printf("Verbo Conjugado\n\n");
  } 
  
  fclose(miArchivo);
  printf("*****Programa finalizado*****\n\n");
  system("pause");
  return 0;
}

//FUNCIONES

//regulares
//AR
  int conjugacionRegularAR(FILE *archivo, char raizVerboAR[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboAR)+2;
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], 
    		        raizVerboAR, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboAR, SubSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sado", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sado",raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
 
  //gerundio  
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");  
   }	  
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sando",raizVerboAR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
  //imperativo 
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboAR, SubImAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                     
  return 0;  
}  
//ER
int conjugacionRegularER(FILE *archivo, char raizVerboER[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboER)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+3);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], 
    		        raizVerboER, DesidenciaSimpleER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona],AuxComp[tiempo],raizVerboER); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple 
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona],raizVerboER, SubSimpleER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona], AuxSubComp[tiempo],raizVerboER); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio 
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sido",raizVerboER); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
 
   //gerundio
   
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%siendo",raizVerboER); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ", 
    		        raizVerboER, SubImER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                    
  return 0;  
  }
  
//IR
  int conjugacionRegularIR(FILE *archivo, char raizVerboIR[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboIR)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+3);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], raizVerboIR, DesidenciaSimpleIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona], 
    		        AuxComp[tiempo],raizVerboIR); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboIR, SubSimpleIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboIR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sido",raizVerboIR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //gerundio 
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%siendo",raizVerboIR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ", 
    		        raizVerboIR, SubImIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                       
  return 0;  
}

//irregulares
//ADQUIRIR              
int conjugacionRegularAD(FILE *archivo, char raizVerboAD[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboAD)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  	fprintf(archivo, "%8s %s%s ", Pronombres[persona], raizVerboAD, DesidenciaSimpleAD[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
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
	  		fprintf(archivo, "%9s %9s %srido", Pronombres[persona], AuxComp[tiempo],raizVerboAD); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboAD, SubSimpleAD[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoSubjuntivoComp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %srido", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboAD); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%srido",raizVerboAD); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
   
  //gerundio  
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sriendo",raizVerboAD); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo 
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboAD, SubImAD[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                   
  return 0;  
} 

//SONAR           
  int conjugacionRegularSO(FILE *archivo, char raizVerboSO[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboSO)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+3);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], raizVerboSO, DesidenciaSimpleSO[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %sonado", Pronombres[persona], 
    		        AuxComp[tiempo],raizVerboSO); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], raizVerboSO, SubSimpleSO[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto 
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sonado", Pronombres[persona], AuxSubComp[tiempo],raizVerboSO); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sonado",raizVerboSO); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
   
  //gerundio 
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sonando",raizVerboSO); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo  
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ", raizVerboSO, SubImSO[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                        
  return 0;  
} 

//MECER           
  int conjugacionRegularME(FILE *archivo, char raizVerboME[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboME)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+3);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ", Pronombres[persona], raizVerboME, DesidenciaSimpleME[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n"); 
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona],AuxComp[tiempo],raizVerboME); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona],raizVerboME, SubSimpleME[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona],AuxSubComp[tiempo],raizVerboME); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%scido",raizVerboME); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
 
  //gerundio
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sciendo",raizVerboME); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ", raizVerboME, SubImME[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                       
  return 0;  
}   

//YACER
  int conjugacionRegularYA(FILE *archivo, char raizVerboYA[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboYA)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato," ", ModoIndicativoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo,"%8s %s%s ", Pronombres[persona],raizVerboYA, DesidenciaSimpleYA[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona],AuxComp[tiempo],raizVerboYA); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboYA, SubSimpleYA[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboYA); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%scido",raizVerboYA); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
 
  //gerundio  
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sciendo",raizVerboYA); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo  
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboYA, SubImYA[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                      
  return 0;  
} 

//TRAER
  int conjugacionRegularTR(FILE *archivo, char raizVerboTR[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboTR)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato," ", ModoIndicativoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo,"%8s %s%s ", Pronombres[persona],raizVerboTR, DesidenciaSimpleTR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %s�do", Pronombres[persona], 
    		        AuxComp[tiempo],raizVerboTR); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6)
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona], 
    		        raizVerboTR, SubSimpleTR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %s�do", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboTR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s�do",raizVerboTR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
   
  //gerundio  
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
	  		fprintf(archivo, ".-%syendo",raizVerboTR); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo 
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboTR, SubImTR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                              
  return 0;  
  }                   
  
//PLACER
  int conjugacionRegularPL(FILE *archivo, char raizVerboPL[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboPL)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato," ", ModoIndicativoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo,"%8s %s%s ", Pronombres[persona],raizVerboPL, DesidenciaSimplePL[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona],AuxComp[tiempo],raizVerboPL); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona],raizVerboPL, SubSimplePL[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
 fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %scido", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboPL); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%scido",raizVerboPL); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //gerundio  
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");
   }	  
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sciendo",raizVerboPL); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo  
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboPL, SubImPL[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                    
  return 0;  
}    

//ASIR
  int conjugacionRegularAS(FILE *archivo, char raizVerboAS[]){                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  lverbo = strlen(raizVerboAS)+2;
  
  //indicativo simple
  fprintf(archivo,"\t\t\t\t\t\tIndicativo simple\n");
  for(tiempo=0;tiempo<=4;tiempo++){
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+4);
	    fprintf(archivo, formato," ", ModoIndicativoSimple[tiempo]," ");   
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo,"%8s %s%s ", Pronombres[persona], 
    		        raizVerboAS, DesidenciaSimpleAS[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //indicativo compuesto
  fprintf(archivo,"\t\t\t\t\t\tIndicativo Compuesto\n");
  for(tiempo=0;tiempo<=4;tiempo++)
   {
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
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona], 
    		        AuxComp[tiempo],raizVerboAS); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo simple
  fprintf(archivo,"\t\t\t\tSubjuntivo simple\n");
  for(tiempo=0;tiempo<=2;tiempo++){
  		titulo = strlen(ModoSubjuntivoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoSubjuntivoSimple[tiempo]," ");	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6)
	  		fprintf(archivo, "%8s %s%s ",Pronombres[persona],raizVerboAS, SubSimpleAS[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");
  
  //subjuntivo compuesto
  fprintf(archivo,"\t\t\t\tSubjuntivo Compuesto\n");
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
  for (persona=0; persona<TotalPronombres; persona++){
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%9s %9s %sido", Pronombres[persona], 
    		        AuxSubComp[tiempo],raizVerboAS); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //participio
    for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoParticipio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoParticipio[tiempo]," ");
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%sido",raizVerboAS); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //gerundio  
   for(tiempo=0;tiempo<=0;tiempo++)
   {
  		titulo = strlen(ModoGerundio[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+10);
	    fprintf(archivo, formato, " ", ModoGerundio[tiempo]," ");	    
   }	  
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%siendo",raizVerboAS); 
        fprintf(archivo, "\n");
   } 
     fprintf(archivo, "\n");
     
  //imperativo   
  for(tiempo=0;tiempo<=0;tiempo++){
  		titulo = strlen(ModoImperativo[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%d", centrado, centrado+5);
	    fprintf(archivo, formato, " ", ModoImperativo[tiempo]," ");	    
   }
  for (persona=0; persona<TotalPronombres-5; persona++){
		for(tiempo=persona;tiempo<1*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, ".-%s%s ",raizVerboAS, SubImAS[tiempo]); 
        fprintf(archivo, "\n");
   }                                                                                                     
  return 0;  
}                              
