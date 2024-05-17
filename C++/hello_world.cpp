#include <iostream>
using namespace std;
void addone(int &a){a++;}

int main(){
    char a[] = " hello world";
    for(char c : a)
    {
        cout << c;
    }
    return 0;
}


