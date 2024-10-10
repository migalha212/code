#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

double average(const string fname){
    ifstream inf(fname);
    double curr;
    double avg = 0;
    double ct = 0;
    while(true){
        if(inf.eof()) break;
        if(inf >> curr){
        ct++; avg += curr;
        }
        else {
        inf.clear();inf.ignore(1);
        }
    }
    return avg / ct;
}

int main(){
    { double m = average("p6_test2.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
    return 0;
}