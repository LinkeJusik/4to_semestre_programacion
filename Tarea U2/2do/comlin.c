#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  int a, b,b2, a2, q, r, d, cont=1, auxs1, auxs2, s, auxt1, auxt2, t;
  printf("Programa que calcula la combinación lineal de dos enteros hacia su maximo comun divisor\n");
  printf("Ingresa el numero a: \n"); scanf("%d", &a);
  printf("Ingresa el numero b: \n"); scanf("%d", &b);
  b2=b;
  a2=a;
  
if((a!=0)||(b!=0)){
  q=a/b; r=a%b;
    }
while(r>0){
  a=b; 
  b=r;
  if(cont==1){
    s=1; 
    auxs2=s;
    t=(-1)*q; 
    auxt1=t;
  } 
  if(cont==2){
    s=-auxs2*q; 
    auxs1=s;
    t=-auxt1*q+1; 
    auxt2=t;
  }
  if(cont>2&&(cont%2)==1){
    s=-auxs1*q+auxs2; 
    auxs2=s;
    t=-auxt2*q+auxt1; 
    auxt1=t;
  }
  if(cont>2&&(cont%2)==0){
    s=-auxs2*q+auxs1; 
    auxs1=s;
    t=-auxt1*q+auxt2; 
    auxt2=t;
  }
  q=a/b; r=a%b;
  cont++;
  } 
  d=abs(b);
  printf("El maximo comun divisor de %d y %d es: %d\n", a2, b2, d);
  printf("Asi mismo, su combinacion lineal es:\n%d(%d) + %d(%d) = %d\n", a2, s, b2, t, d);
  system("pause");
  return 0;
}
//Respuesta a la pregunta del pdf://
//Si b es primo y a es tal que b no lo divide, as mod b = mcd(a,b)=1//
//La ultima igual recae en el hecho de que a y b no tienen factores en común//