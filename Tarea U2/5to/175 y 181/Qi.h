#ifndef _Qi_mi_H_
#define _Qi_mi_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "Q.h"

typedef struct _Qi_{
    Q re, im;
} Qi;

int escQi(Qi r);
int esc2Qi(Qi r);
Qi asignaQi(Q re, Q im);
Qi leerQi(char leyenda[]);
Qi sumaQi(Qi a, Qi b);
Qi restaQi(Qi a, Qi b);
Qi prodQi(Qi a, Qi b);
Qi ceroQi(Qi a);
Qi inverQi(Qi a);
Qi powQi(Qi a,int n);


#ifdef __cplusplus
}
#endif

#endif