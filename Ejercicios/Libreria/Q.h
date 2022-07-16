#ifndef _Q_mi_H_
#define _Q_mi_H_

#ifdef __cplusplus
extern "C"{
#endif

typedef struct _Q_{
    int num, den;
} Q;

Q simplificaQ(Q r);
Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);

int escQ(Q r);
Q asignaQ(int num, int den);
Q leeQ(char leyenda[]);

#ifdef __cplusplus
}
#endif

#endif