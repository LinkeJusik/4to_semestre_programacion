#ifndef _H_POLINOMIO_
#define _H_POLINOMIO_

#ifdef __cplusplus
extern "C" {
#endif

#include "Gq.h"

typedef struct _Px_{
  int g,e;
  Gq *c;
}Px;

Px leePx(FILE *f);
int escPx(Px C,char buffer[]);

Px sumaPx(Px a,Px b);
Px restaPx(Px a,Px b);
Px multPx(Px a,Px b);

int liberaPx(Px *a);

#ifdef __cplusplus
}
#endif

#endif
