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
Qi asignaQi(Q re, Q im);
Qi leerQi(char leyenda[]);
Qi sumaQi(Qi a, Qi b);
Qi prodQi(Qi a, Qi b);


#ifdef __cplusplus
}
#endif

#endif