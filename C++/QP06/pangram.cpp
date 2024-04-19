#include <string>
#include <iostream>
using namespace std;

bool pangram(const string& s, string& m){
    int alpha[26] = {0,};
    bool flag = true;
    for(long unsigned int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') alpha[s[i] -'a'] = 1;
        else if(s.at(i) >= 'A' && s.at(i) <= 'Z') alpha[s.at(i)-'A'] = 1;
    }
    for(int j = 0; j < 26; j++){
        if(alpha[j] == 0){
            m.push_back('a'+ j);
            flag = false;
        }
    }
    return flag;
}

int main(){
    	
{ string s = " Stu yZ abC GhI MnO pQr   ";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}