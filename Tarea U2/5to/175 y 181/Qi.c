#include <stdio.h>
#include <stdlib.h>

#include "Qi.h"
#include "Q.h"

Qi ceroQi(Qi a){
	a.im.num=0;
    a.im.den=1;
	a.re.num=0;
    a.re.den=1;
	return a;
}
int escQi(Qi r){
    escQ(r.re); printf(" + "); escQ(r.im); printf(" i");
    return 0;
}
int esc2Qi(Qi r){
    escQ(r.re); printf(" - "); escQ(r.im); printf(" i");
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
    return ret;
}
Qi sumaQi(Qi a, Qi b){
    Qi ret;
    ret.re = sumaQ(a.re, b.re);
    ret.im = sumaQ(a.im, b.im);
    return ret;
}
Qi restaQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(a.re, b.re);
    ret.im = restaQ(a.im, b.im);
    return ret;
}
Qi prodQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(prodQ(a.re,b.re), prodQ(a.im, b.im));
    ret.im = sumaQ(prodQ(a.re, b.im), prodQ(a.im, b.re));
	return ret;
}
Qi inverQi(Qi a){
	Qi ret;
	Q norma, inver, aux;
	norma = sumaQ(prodQ(a.re,a.re),prodQ(a.im,a.im));
	aux.num=0;
	aux.den=1;
	inver = restaQ(aux,a.im);
	ret.re = divQ(a.re,norma);
	ret.im = divQ(inver, norma);
	return ret;
}
Qi powQi(Qi a,int n){
    int i;
    Qi aux;
    aux.re.den=1;
    aux.re.num=1;
    aux.im.num=0;
    aux.im.den=1;
    for(i=0; i<n; i++){
        aux=prodQi(aux,a);
    }
    return aux;
}