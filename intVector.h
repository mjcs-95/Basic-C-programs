
//Change int val and the struct attributes types to float or char to make new type vectors
#define INITSIZE 3

typedef struct{
    unsigned size;
    unsigned capacity;
    int *data;    
} iVector;

void    vConstructor(iVector *v);
void    vDestructor (iVector *v);
void    vExpand     (iVector *v);
void    vPush       (iVector *v, int val);
void    vSet        (iVector *v, int val, int idx);
int     vGet        (iVector *v, int idx);
