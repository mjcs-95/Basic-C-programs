
#include <stdio.h>
#include <stdlib.h>
#include "intVector.h"
//Change sizeof(int) or int val to float or char to change the variables type
void vConstructor(iVector *v){
    v->size     = 0;
    v->capacity = INITSIZE*INITSIZE;
    v->data     = malloc(sizeof(int) * v->capacity);
}

void vDestructor(iVector *v){
    free(v->data);
}

void vExpand(iVector *v){
    v->capacity*=2;
    v->data = realloc(v->data, sizeof(int) * v->capacity);
}

void vPush(iVector *v, int val){
    if(v->size == v->capacity){
        vExpand(v);
    }
    v->data[v->size] = val;
    ++v->size;
}

int vGet(iVector *v, int idx){
    if(idx < 0 || idx > v->size){
        printf("get Index out of bound exception\n");
        exit(1);
    }
    return v->data[idx];
}

void vSet(iVector *v, int idx,int val){
    if(idx < 0 || idx > v->size){
        printf("set Index out of bound exception\n");
        exit(1);
    }
    v->data[idx]=val;
}

void testVectorsFunctions(){
    iVector v1;
    vConstructor(&v1);
    vSet(&v1,2,5);
    vExpand(&v1);
    for(int i=0;i<10;i++){
        vPush(&v1,i);
    }
    
    for(int i=0;i<10;i++){
        printf("Valor de %d: %d\n",i,vGet(&v1,i));
    }
    vDestructor(&v1);    
}

int main(){
    testVectorsFunctions();
}