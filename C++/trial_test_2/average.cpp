#include "show_file.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void average(const string& input_fname, const string& output_fname){
    ifstream inf(input_fname);
    ofstream onf(output_fname);
    double input = 0;
    double total = 0;
    double counter = 0;
    int lines = 0;
    string line = "";
    while(getline(inf,line)){
        lines++;
        total = 0;
        counter = 0;
        istringstream iss(line);
        while(iss >> input){
            total += input;
            counter++;
        }
        total /= counter;
        onf << fixed << setprecision(3) << total << '\n';
    }
    onf << "lines=" << lines;
}