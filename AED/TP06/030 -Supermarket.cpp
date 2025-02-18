#include <iostream>
#include <vector>
using namespace std;


typedef struct 
{
    string name;
    int arrival;
    int products;
}Customer;

int main(){
    int c; //number of checkouts
    cin >> c;
    vector<int> speed(c);
    for(int i = 0; i < c; i++){
        cin >> speed[i];
    }
    int n; //number of customers
    vector<Customer> customers(n);
    for(int i = 0; i < n; i++){
        cin >> customers[i].name >> customers[i].arrival >> customers[i].name;
    }
}