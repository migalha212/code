#include <iostream>
#include <stack>
#include <sstream>
typedef bool flag;
using namespace std;

typedef struct{
    char name;
    int date;
}Groom;

int main(){
    string formula;
    getline(cin,formula);

    //* Solution
    stack<Groom> venue;
    flag missMatch = false;
    int counter = 0;
    string res = "";
    ostringstream a(res);
    for(int i = 0; i < formula.length() && !missMatch; i++){
        char c = formula[i];
        switch (c)
        {
    //* Dealing with placing all open brackets into the stack for later comparisson
        case '(':
        case '{':
        case '[':
            venue.push({c,i});
            break;
            
    //* Comparing closing brackets to the top of the stack to look for match or missMatch
    //* porque raios existe uma barra entre '{' e '}' e '[' e ']' mas nao entre '(' e ')'     
        case ')': 
        if(venue.empty()) missMatch = true;
        else if(venue.top().name == '('){
            a << "() " << venue.top().date << ' ' << i << endl;
            venue.pop();
            counter++;
        }
        else{
            missMatch = true;
        }
        break;
        case ']':
        if(venue.empty()) missMatch = true;
        else if(venue.top().name == '['){
            a << "[] " << venue.top().date << ' ' << i << endl;
            venue.pop(); counter++;
        }
        else{
            missMatch = true;
        }
        break;
        case '}':
        if(venue.empty()) missMatch = true;
        else if(venue.top().name == '{'){
            a << "{} " << venue.top().date << ' ' << i << endl;
            venue.pop(); counter++;
        }
        else{
            missMatch = true;
        }
        
        break;
        default:
            break;
        }
    }
    res = a.str();
    if(counter == 0 && !missMatch){
        cout << "no brides and grooms to marry" << endl;
    }
    else if(missMatch || !venue.empty()){
        cout << "badly matched pairs" << endl;
    }
    else{
        cout << res;
    }

}