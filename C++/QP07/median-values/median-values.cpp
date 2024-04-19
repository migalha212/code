#include "show_file.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void calc_medians(const string& input_fname, const string& output_fname){
    ifstream inf(input_fname);
    ofstream ouf(output_fname);
    double curr = 0;
    string id;
    string line;
    vector <double> d;
    int ct = 0;
    bool flag = false;
    double media = 0;
    while(getline(inf,line)){
        flag = false;
        istringstream stri(line);
        stri >> id; for(char c: id){if(c == '#') flag = true;};if(flag) continue;
        ct = 0;
        d.clear();
        while(stri >> curr){
            ct++;
            d.push_back(curr);
        }
        sort(d.begin(),d.end());
        media = (ct % 2 == 0) ? 0.5 * (d[ ct / 2 - 1] + d[ ct / 2]) : d[ct / 2];

        ouf << id << " " << fixed << setprecision(1) << media << "\n"; 
    }
}


int main(){
    //{ calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
  //show_file("p5_test2_out.txt"); }
  	
{ calc_medians("p5_test3.txt", "p5_test3_out.txt");
  show_file("p5_test3_out.txt"); }
  return 0;
}