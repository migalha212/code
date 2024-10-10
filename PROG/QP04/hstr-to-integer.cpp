#include <iostream>
using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long res = 0;
    int i = 0;
    while(hstr[i] != 0){
        res *= 16;
        if (hstr[i] >= 'a' && hstr[i] <= 'z'){
            res += hstr[i] - 'a' + 10;
        }
        else if(hstr[i] >= 'A' && hstr[i] <= 'Z') res += hstr[i] - 'A' + 10;
        else res += hstr[i] - '0';
        i++;
    }
    return res;
}

int main(){
    //cout << hstr_to_integer("0");
    cout << hstr_to_integer("cafebabe2022");
    return 0;
}



