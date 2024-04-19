#include "smatrix.h"
#include <vector>
using namespace std;


void sum(const smatrix& a, const smatrix& b, smatrix& r){
    size_t a1 = 0;
    size_t b1 = 0;

while(a1 < a.size() && b1 < b.size()){
    if(a[a1].row < b[b1].row || (a[a1].row == b[b1].row && a[a1].col < b[b1].col)){
        r.push_back(a[a1++]); continue;
    }
    if(b[b1].row < a[a1].row || (b[b1].row == a[a1].row && b[b1].col < a[a1].col)){
        r.push_back(b[b1++]); continue;
    }
    if(b[b1].row == a[a1].row && b[b1].col == a[a1].col){
        if(b[b1].value + a[a1].value != 0){
            r.push_back(sm_entry{b[b1].row,b[b1].col,b[b1].value + a[a1].value});
        }
        a1++;b1++;continue;
    }
}
    while(a1 < a.size()){
        r.push_back(a[a1++]);
    }
    while(b1 < b.size()){
        r.push_back(b[b1++]);
    }
    return;
}

int main(){
    	
        	
{ smatrix r;
  sum({ },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }
{ smatrix r;
  sum({ {0, 0, 1}, {1, 0, 1} },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }

  return 0;
}