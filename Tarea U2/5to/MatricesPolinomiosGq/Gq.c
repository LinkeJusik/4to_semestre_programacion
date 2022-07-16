#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "Gq.h" 

int mcd(int a,int b){
  int r;

  if (a<0) a=-a;
  if (b<0) b=-b;
  if (b==0) return a;

  while ((r=a%b)!=0){
    a=b;
    b=r;
  }

  return b;
}          

Q simplificaQ(Q a){                     
  int d;              
  Q regreso;          

  regreso=a;
  d=mcd(a.p,a.q);
  if (d==0) return a;
  if (d>1){
    regreso.p/=d;
    regreso.q/=d;
  }
  if (regreso.q<0){
    regreso.p*=-1;
    regreso.q*=-1;
  }

  return regreso;
}

Q sumaQ(Q a,Q b){
  Q r;

  r.p=a.p*b.q+a.q*b.p;
  r.q=a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q restaQ(Q a,Q b){
  Q r;

  r.p=a.p*b.q-a.q*b.p;
  r.q=a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q multQ(Q a,Q b){
  Q r;

  r.p=a.p*b.p;
  r.q=a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q leeQ(FILE *f){
     Q ret;
     
     fscanf(f,"%d%d",&ret.p,&ret.q);
     
     return simplificaQ(ret);
}

int escQ(Q a,char buffer[]){
  int l;
  
  if (a.p!=0){
          sprintf(buffer,"%d",a.p);
          l=strlen(buffer);
          if (a.q!= 1) sprintf(buffer+l,"/%d",a.q);
  }
  
  return 0;
}

Gq sumaGq(Gq a,Gq b){
  Gq r;

  r.r=sumaQ(a.r,b.r);
  r.i=sumaQ(a.i,b.i);

  return r;
}

Gq restaGq(Gq a,Gq b){
  Gq r;

  r.r=restaQ(a.r,b.r);
  r.i=restaQ(a.i,b.i);
  
  return r;
}

Gq multGq(Gq a,Gq b){
  Gq r;

  r.r=restaQ(multQ(a.r,b.r),multQ(a.i,b.i));
  r.i=sumaQ(multQ(a.r,b.i),multQ(a.i,b.r));
  
  return r;
}

Gq leeGq(FILE *f){
     Gq ret;
     
     ret.r=leeQ(f);
     ret.i=leeQ(f);
     
     return ret;
}

int escGq(Gq a,char buffer[]){
     int l;
     char aux[128];
     
     if (a.r.p!=0){
          escQ(a.r,aux);
          sprintf(buffer,aux);
          l=strlen(buffer);
     }
     if (a.i.p!=0)
          if (a.r.p!=0)
               if ((a.i.p==1||a.i.p==-1)&&a.i.q==1)
                    sprintf(buffer+l,"%s",a.i.p>0?"+i":"-i");
               else{
                    escQ(a.i,aux);
                    if (a.i.p>0) sprintf(buffer+l,"+%si",aux);
                    else sprintf(buffer+l,"%si",aux);
               }
          else
               if ((a.i.p==1||a.i.p==-1)&&a.i.q==1)
                    sprintf(buffer,"%s",a.i.p>0?"i":"-i");
               else{
                    escQ(a.i,aux);
                    sprintf(buffer,"%si",aux);
               }
     if (a.r.p!=0&&a.i.p!=0) sprintf(buffer,"%s",buffer);
     if (a.r.p==0&&a.i.p==0) sprintf(buffer,"0");
     
     return 0;
}
