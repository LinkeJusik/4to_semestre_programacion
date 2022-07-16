#include <stdio.h>
#include <stdlib.h>

typedef struct _Q_{
    int num, den;
} Q;
typedef struct _Qi_{
    Q re, im;
} Qi;

/*declaraciones de funciones*/
/*uso de racionales*/
int mcd(int , int );
Q simplificaQ(Q r);
Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);

int escQ(Q r);
Q asignaQ(int num, int den);
Q leeQ(char leyenda[]);

/*uso de racionales complejos*/
int escQi(Qi r);
Qi asignaQi(Q re, Q im);
Qi leerQi(char leyenda[]);
Qi sumaQi(Qi a, Qi b);
Qi prodQi(Qi a, Qi b);


int main(int argc, char *argv[]){
    Q a,b,r;
    Qi z;
    int num, den;
    char saludo1[32];
    char saludo2[]={'H','o','l','a','\0'};
    char saludo3[]="Hola";
    //printf("saludo1 = <<%s>>\nsaludo2=<<%s>>\nsaludo3=<<%s>>\n", saludo1, saludo2, saludo3);//

    printf("Racional complejo.\n");
    leeQi(" de z ");

    ////

    a = leeQ("a");
    b = leeQ("b");

    r=sumaQ(a,b);
    escQ(a); printf(" + "); escQ(b); printf(" = "); escQ(r);
    printf("\n");
    r=prodQ(a,b);
    escQ(a); printf(" * "); escQ(b); printf(" = "); escQ(r);
    system("pause");
    return 0;
}

/*definiciones de funciones*/
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

int escQi(Qi r){
    escQ(r.re); printf(" + "); escQ(r.im); printf(" i");
    return 0;
}
Qi asignaQi(Q re, Q im){
    Qi ret;
    ret.re = re;
    ret.im = im;
    return ret;
}
Qi leerQi(char leyenda[]){
    Qi ret;
    printf("parte real. ");
    ret.re = leeQ(leyenda);
    printf("parte imaginaria. ");
    ret.im = leeQ(leyenda);
}
Qi sumaQi(Qi a, Qi b){
    Qi ret;
    ret.re = sumaQ(a.re, b.re);
    ret.im = sumaQ(a.im, b.im);
}
Qi prodQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(prodQ(a.re,b.re), prod(a.im, b.im));
    ret.im = sumaQ(prodQ(a.re, b.im), prod(a.im, b.re));
}