#include <iostream>
using namespace std;
void trim(char s[]){
    // ! ' '= 32
    int i;
    while(s[i]){
      if (s[i] = ' '){
        for(int j = 0; s[j] != '\0';j++){
          s[j] = s[j+1];
        }
        continue;
      }
      break;
    }
}

int main(){
{ char s[] = " abc! def? ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n";}
    return 0;
}
