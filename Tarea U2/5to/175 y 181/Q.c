#include <stdio.h>
#include <stdlib.h>

#include "Q.h"

int mcd(int , int );
int mcd(int a, int b){
    int r;
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(b==0 && a!=0) return a;
    if(a==0 && b!=0) return b;
    if(a==0 && b==0) return 1;
    
    while((r=a%b) != 0){
        a=b;
        b=r;
    }
    return b;
}
Q simplificaQ(Q r){
    int d;
    d=mcd(r.den, r.num);
    r.den/=d;
    r.num/=d;
    if(r.den<0){
        r.num=-r.num;
        r.den=-r.den;
    }
    return r;
}
Q sumaQ(Q a, Q b){
    Q r = {num:a.num*b.den+a.den*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q restaQ(Q a, Q b){
    Q r = {num:a.num*b.den-a.den*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q prodQ(Q a, Q b){
    Q r = {num:a.num*b.num, den:a.den*b.den};
    return simplificaQ(r);
}
Q divQ(Q a, Q b){
    Q r = {num:a.num*b.den, den:a.den*b.num};
    return simplificaQ(r);
}

int escQ(Q r){
    printf("%d", r.num);
    if(r.den>1) printf("/%d", r.den);
    printf(" ");
    return 0;
}

Q asignaQ(int num, int den){
    Q r ={num, den};
    return simplificaQ(r);
}

Q leeQ(char leyenda[]){
    int num, den;
    printf("Digita num de %s: ", leyenda); scanf("%d", &(num));
    printf("Digita den de %s: ", leyenda); scanf("%d", &(den));
    return asignaQ(num, den);
}
