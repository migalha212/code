#include <fstream>
#include <iostream>
#include "print.h"
using namespace std;

void normalise(const string& input_fname, const string& output_fname){
    string line;
    string word;
    ifstream fin(input_fname);
    ofstream fout(output_fname);
    while(true){
        if(fin.eof()) break;
        getline(fin,line);
        if(line == "") continue;
        for(char& c : line){
            c = toupper(c);
        }
        int temp1 = line.find_first_not_of(" ");
        int temp2 = line.find_last_not_of(" ");
        if(temp1 == temp2 && temp1 >= 0) fout << line[temp1] << "\n";
        else if(temp1 >= 0) fout << line.substr(temp1,temp2-temp1+1) << "\n";

        istringstream li(line);
        }
}

int main(){
    //{ normalise("p3_test1.txt", "p3_test1_out.txt"); 
  //print("p3_test1_out.txt"); }
  	//{ normalise("p3_test4.txt", "p3_test4_out.txt");
  //print("p3_test4_out.txt"); }
//{ normalise("p3_test5.txt", "p3_test5_out.txt");
//  print("p3_test5_out.txt"); }
{ normalise("p3_test2.txt", "p3_test2_out.txt");
  print("p3_test2_out.txt"); }
  return 0;
}