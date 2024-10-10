#include <iostream>
using namespace std;


char* duplicate(const char s[]){
    int tam = 0;
    while(s[tam]){
        tam++;
    }
    char *res = new char[tam+1]; res[0] = 0;
    for(int i = 0; i < tam; i++){
        res[i] = s[i];
    }
    res[tam] = 0;
    return res;
}

int main(){
    { char* s = duplicate("");
  cout << "\"" << s << "\"\n";
  delete [] s; }
  return 0;
}