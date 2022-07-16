#include <stdio.h>
#include <stdlib.h>

#include "Qi.h"
#include "Q.h"

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
    return ret;
}
Qi sumaQi(Qi a, Qi b){
    Qi ret;
    ret.re = sumaQ(a.re, b.re);
    ret.im = sumaQ(a.im, b.im);
    return ret;
}
Qi prodQi(Qi a, Qi b){
    Qi ret;
    ret.re = restaQ(prodQ(a.re,b.re), prodQ(a.im, b.im));
    ret.im = sumaQ(prodQ(a.re, b.im), prodQ(a.im, b.re));
}