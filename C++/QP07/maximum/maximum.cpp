#include <fstream>
#include <string>
#include <iomanip>
#include "show_file.h"
using namespace std;

void maximum(const string& input_fname, const string& output_fname){
    ifstream inf(input_fname);
    ofstream ouf(output_fname);
    string line;
    int ct = 0; double maxi = -1000;
    double curr = 0;
    while(getline(inf,line)){
        if(line == "") continue;
        if(line.find_first_not_of(" ") == string::npos) continue;
        istringstream st(line);
        ct++;
        st >> curr;
        maxi = (curr > maxi) ? curr : maxi;
        ouf <<fixed << setprecision(3) << curr << "\n";
    }
    ouf << "count=" << ct << "/max=" << maxi;
}

int main(){
    { maximum("p4_test1.txt", "p4_test1_out.txt");
  show_file("p4_test1_out.txt"); }
    return 0;
}