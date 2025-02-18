#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string sortString(const string & str){
    string a = "";
    for(const char c : str){if(c != ' '){a += tolower(c);}}
    sort(a.begin(),a.end());
    return a;
}

int main(){
    int n, res = 0;
    string str;
    cin >> n;
    vector<string> v(n);
    getline(cin ,str);
    for(int i = 0; i < n; i++){
        getline(cin,str); v[i] = sortString(str);
    }

    sort(v.begin(),v.end());
    str = v[0];
    bool flag = 0;
    for(int i = 1; i < n; i++){
        if(str == v[i] && !flag){ res++; flag = 1;}
        else if( str != v[i]){str = v[i]; flag = 0;}
    }
    cout << res << endl;
}