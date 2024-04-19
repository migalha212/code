#include <iostream>
using namespace std;

char* repeat(const char str[], int n){
    int i = 0;
    while(str[i] != '\0') i++;
    char* a = new char[n*i+1];
    for(int j = 0; j < n*i; j++){
        a[j] = str[j % i];
    }
    a[n*i] = '\0';
    return a;
}
int main(){
{ const char str[] = "C/C++@LEIC.";
  char* r = repeat(str, 5);
  cout << "\"" << r << "\"\n";
  delete [] r; }
    return 0;
}