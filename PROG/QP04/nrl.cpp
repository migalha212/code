#include <iostream>
using namespace std;

void fill_zero(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}
int nrl(const char s[], char low[]){
    low[0] = 0;
    int ch[27] = {0,};
    fill_zero(ch,26);
    int res = 0;
    int i = 0;
    while(s[i]){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(ch[s[i]-'a'] < 1){
                ch[s[i]-'a'] = 1;
                res++;
            }
            else if(ch[s[i]-'a'] < 2){
                res--;
                ch[s[i]-'a'] = 2;
            }
        }
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(ch[s[i]-'A'] < 1){
                ch[s[i]-'A'] = 1;
                res++;
            }
            else if(ch[s[i]-'A'] < 2){
                res--;
                ch[s[i]-'A'] = 2;
            }
        }
        i++;
    }
    int k = 0;
    for(int j = 0; j < 27; j++){
        if(ch[j] == 1){
            low[k] = 'a' + j;
            low++; 
        }
    }
    return res;
}

int main(){
{ const char s[] = "";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
{ const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
    return 0;
}