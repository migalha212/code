#include <iostream>
using namespace std;

bool pangram(const char s[], char m[]){
    m[0] = 0;
    int flag[26] = {0,};
    bool check = true;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            flag[s[i] - 'a'] = 1;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            flag[s[i] - 'A'] = 1;
        }
    }
    int k = 0;
    for(int j = 0; j < 26;j++){
        if(flag[j] == 0){
            m[k] = 'a' + j;
            check = false;
            k++;
        }
        
    }
    
    return check;
}

int main(){
    	
{ char s[] = " Stu yZ abC GhI MnO pQr   ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}