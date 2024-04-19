#include <iostream>
#include "print_array.h"
using namespace std;

/*void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
    int a1 = 0;
    int b1 = 0;
    for(int c1 = 0; c1 < na + nb; c1++){
        if(a1 == na){c[c1] = b[b1++]; continue;}
        else if(b1 == nb){c[c1] = a[a1++]; continue;}
        if(a[a1] <= b[b1] && a1 < na) c[c1] = a[a1++];
        else if(b[b1] <= a[a1] && b1 < nb) c[c1] = b[b1++];
    }
}*/
int* merge_arrays(const int a[], int na, const int b[], int nb){
    int *result = new int[na+nb];
    int a1 = 0;
    int b1 = 0;
    for(int c1 = 0; c1 < na + nb; c1++){
        if(a1 == na){result[c1] = b[b1++]; continue;}
        else if(b1 == nb){result[c1] = a[a1++]; continue;}
        if(a[a1] <= b[b1] && a1 < na) result[c1] = a[a1++];
        else if(b[b1] <= a[a1] && b1 < nb) result[c1] = b[b1++];
    }
    return result;
}
int main(){
    	
/*{ const int NA = 4, NB = 6;
  int a[NA] = { 1, 2, 4, 7};
  int b[NB] = { 0, 3, 5, 6, 8, 9};
  int c[NA+NB];
  merge_arrays(a, NA, b, NB, c);
  print_array(c, NA+NB); }*/
{ const int NA = 4, NB = 6;
  int a[NA] = { 1, 2, 4, 7};
  int b[NB] = { 0, 3, 5, 6, 8, 9};
  int* c = merge_arrays(a, NA, b, NB);
  print_array(c, NA+NB);
  delete [] c; }
  return 0;
}