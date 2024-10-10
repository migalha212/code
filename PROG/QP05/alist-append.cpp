#include <iostream>
#include "alist.h"
using namespace std;

void append(alist* a, const alist* b){
    if(a->size == 0){
      a->size = b->size;
      a->elements = new int[a->size];
      for(int i = 0; i < b->size; i++){a->elements[i] = b->elements[i];}
      return;
    }
    if(b->size != 0){
      int* tmp = new int[a->size + b->size];
      for(int i= 0; i < a->size; i++){
        tmp[i] = a->elements[i];
      }
      for(int i = a->size; i < b->size+a->size;i++){
        tmp[i] = b->elements[i-a->size];
      }
      delete[]a->elements;
      a->elements = tmp;
      a->size += b->size;
    }


    return;
}

int main(){
{ const int nA = 2;
  int eA[nA] = { 1, 2 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 3, 4, 5 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
  return 0;
}