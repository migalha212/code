#include <iostream>
using namespace std;

int main(){
    char a;
    cin >> a;
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) cout << "LETTER";
    else if(a >= '0' && a <= '9') cout << "DIGIT";
    else cout << "OTHER";
    return 0;
}