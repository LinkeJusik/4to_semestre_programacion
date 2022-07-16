#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Gq.h"
#include "Polinomios.h"

int ceroGq(Gq c){
     if (c.r.p==0&&c.i.p==0) return 1;

     return 0;
}

int unoGq(Gq c){
     if (c.r.p==1&&c.r.q==1&&c.i.p==0) return 1;

     return 0;
}

int menosunoGq(Gq c){
     if (c.r.p==-1&&c.r.q==1&&c.i.p==0) return 1;

     return 0;
}

Gq cero(void){
     Gq ret;
     
     ret.r.p=0;
     ret.r.q=1;
     ret.i.p=0;
     ret.i.q=1;

     return ret;
}

Px copiaPx(Px a)
{
  Px ret;
  int i;

  ret.g=a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
  }

  for(i=0;i<=ret.g;i++) ret.c[i]=a.c[i];

  return ret;
}

Px copiaMenosPx(Px a){
  Px ret;
  int i;
  
  ret.g=a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
  }
  
  ret=copiaPx(a);

  for(i=0;i<=ret.g;i++){
          ret.c[i].r.p=-a.c[i].r.p;
          ret.c[i].i.p=-a.c[i].i.p;
  }

  return ret;
}

Px leePx(FILE *f){
     Px ret;
     int i;
     
     fscanf(f,"%d",&ret.g);
     if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
          fprintf(f,"error al generar espacio.\n");
          ret.g=-1;
          return ret;
     }
     
     for (i=0;i<=ret.g;i++){
          ret.c[i]=leeGq(f);
          if (ret.c[i].r.q==0||ret.c[i].i.q==0) {ret.e=1; return ret;}
     }
     
     while(ret.g>=0&&ceroGq(ret.c[ret.g])) ret.g--;
     if (ret.g<0){
          free(ret.c);
          ret.c = NULL;
     }
     
     return ret;
}

int escPx(Px C,char buffer[]){
     char aux[1024];
     int l=0,i;
     
     if (C.g<0){
          sprintf(buffer,"0");
          return 0;
     }
     if (C.g>0){
          if (C.g>1){
               if (unoGq(C.c[C.g])||menosunoGq(C.c[C.g]))
                    if (unoGq(C.c[C.g])) sprintf(buffer,"x^%d",C.g);
                    else sprintf(buffer,"-x^%d",C.g);
               else{
                         if (C.c[C.g].r.p!=0&&C.c[C.g].i.p!=0){
                              escGq(C.c[C.g],aux);
                              sprintf(buffer,"(%s)x^%d",aux,C.g);
                         }
                         else{
                              escGq(C.c[C.g],aux);
                              sprintf(buffer,"%sx^%d",aux,C.g);
                         }
               }
               for (i=C.g-1;1<i;i--){
                    if (!ceroGq(C.c[i])){
                         l=strlen(buffer);
                         if (unoGq(C.c[i])||menosunoGq(C.c[i]))
                              if (unoGq(C.c[i])) sprintf(buffer+l,"+x^%d",i);
                              else sprintf(buffer+l,"-x^%d",i);
                         else{
                              if ((C.c[i].r.p!=0&&C.c[i].i.p!=0)||C.c[i].r.p>0||(C.c[i].r.p==0&&C.c[i].i.p>0))
                                   sprintf(buffer+l,"+");
                              l=strlen(buffer);
                              if (C.c[i].r.p!=0&&C.c[i].i.p!=0){
                                   escGq(C.c[i],aux);
                                   sprintf(buffer+l,"(%s)x^%d",aux,i);
                              }
                              else{
                                   escGq(C.c[i],aux);
                                   sprintf(buffer+l,"%sx^%d",aux,i);
                              }
                         }
                    }
               }
               if (!ceroGq(C.c[1])){
                    l=strlen(buffer);
                    if (unoGq(C.c[1])||menosunoGq(C.c[1]))
                         if (unoGq(C.c[1])) sprintf(buffer+l,"+x");
                         else sprintf(buffer+l,"-x");
                    else{
                         if (C.c[1].r.p!=0&&C.c[1].i.p!=0){
                              escGq(C.c[1],aux);
                              sprintf(buffer+l,"+(%s)x",aux);
                         }
                         else{
                              if ((C.c[1].r.p!=0&&C.c[1].i.p!=0)||C.c[1].r.p>0||(C.c[1].r.p==0&&C.c[1].i.p>0))
                                   sprintf(buffer+l,"+");
                              l=strlen(buffer);
                              escGq(C.c[1],aux);
                              sprintf(buffer+l,"%sx",aux);
                         }
                    }
               }
          }
          else{
               if (unoGq(C.c[1])||menosunoGq(C.c[1]))
                    if (unoGq(C.c[1])) sprintf(buffer,"x");
                    else sprintf(buffer,"-x");
               else{
                    if (C.c[1].r.p!=0&&C.c[1].i.p!=0){
                         escGq(C.c[1],aux);
                         sprintf(buffer,"(%s)x",aux);
                    }
                    else{
                         escGq(C.c[1],aux);
                         sprintf(buffer,"%sx",aux);
                    }
               }
          }
          if (!ceroGq(C.c[0])){
                    l=strlen(buffer);
                    if (C.c[0].r.p>0||(C.c[0].r.p==0&&C.c[0].i.p>0))
                         sprintf(buffer+l,"+");
                    l=strlen(buffer);
                    escGq(C.c[0],aux);
                    sprintf(buffer+l,aux);
          }
     }
     else{
          escGq(C.c[0],aux);
          sprintf(buffer,aux);
     }
     
     return 0;
}

Px sumaPx(Px a,Px b){
  Px ret;
  int i,min;

  if (a.g<0){
    return copiaPx(b);
  }
  if (b.g<0){
    return copiaPx(a);
  }
  if (a.g<b.g){
    min=a.g;
    ret.g=b.g;
  }else{
    min=b.g;
    ret.g=a.g;
  }
  if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
  }
  for (i=0;i<=min;i++) ret.c[i]=sumaGq(a.c[i],b.c[i]);
  if (a.g==min){
    for (;i<=ret.g;i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (;i<=ret.g;i++) ret.c[i]=a.c[i];
  }
  while(ret.g>=0&&ceroGq(ret.c[ret.g])) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c=NULL;
  }
  
  return ret;
}

Px restaPx(Px a,Px b){
  Px ret;
  int i,min;

  if (a.g<0){
    return copiaMenosPx(b);
  }
  if (b.g<0){
    return copiaPx(a);
  }
  if (a.g<b.g){
    min=a.g;
    ret.g=b.g;
  } else{
    min=b.g;
    ret.g=a.g;
  }
  if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
  }
  for (i=0;i<=min;i++) ret.c[i]=restaGq(a.c[i],b.c[i]);
  if (a.g==min){
    for (;i<=ret.g;i++) ret.c[i]=restaGq(cero(),b.c[i]);
  }
  if (b.g==min){
    for (;i<=ret.g;i++) ret.c[i]=a.c[i];
  }
  
  while(ret.g>=0&&ceroGq(ret.c[ret.g])) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c=NULL;
  }
  
  return ret;
}

Px multPx(Px a,Px b){
  int i,j;
  Px ret;

  ret.g=a.g+b.g;
  if((ret.c=(Gq*)malloc((ret.g+1)*sizeof(Gq)))==NULL){
    printf("error al generar espacio.\n");
    ret.g=-1;
    return ret;
  }
  for (i=0;i<=ret.g;i++) ret.c[i]=cero();
  for (i=0;i<=a.g;i++)
          for(j=0;j<=b.g;j++)
               ret.c[i+j]=sumaGq(ret.c[i+j],multGq(a.c[i],b.c[j]));
      
  while(ret.g>=0&&ceroGq(ret.c[ret.g])) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c=NULL;
  }

  return ret;
}

int  liberaPx(Px *a){
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
  return 0;
}
