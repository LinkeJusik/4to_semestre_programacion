#ifndef _H_GAUSSIANORACIONAL_
#define _H_GAUSSIANORACIONAL_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Q_{
  int p,q;
}Q;

typedef struct _Gq_{
  Q r,i;
}Gq;

Gq sumaGq(Gq a,Gq b);
Gq restaGq(Gq a,Gq b);
Gq multGq(Gq a,Gq b);
Gq divGq(Gq a,Gq b);

Gq leeGq(FILE *f);
int escGq(Gq a,char buffer[]);

#ifdef __cplusplus
}
#endif

#endif
