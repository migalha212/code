#include <iostream>
using namespace std;
void addone(int &a){a++;}

int main(){
    char a[] = "Hello world!";
    for(char c : a)
    {
        cout << c;
    }
    return 0;
}


