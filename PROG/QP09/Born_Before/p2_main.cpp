#include "Person.h"
#include <vector>
using namespace std;

void born_before(const vector<Person>& persons, const Date& date){
    date.show();
    cout << ": ";
    for(Person p: persons){
        if (p.get_birth_date().is_before(date)){ 
            p.show();
            cout << " ";
        }
    }
}

