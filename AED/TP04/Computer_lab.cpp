#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct{
int entry_hour;
int leaving_hour;

}Student;

inline bool left_at(Student a, Student b){
    if( a.entry_hour <= b.entry_hour && a.leaving_hour < b.leaving_hour 
        || b.entry_hour <= a.entry_hour && b.leaving_hour < a.leaving_hour)
        return true;

        return false;
}

int main(){
int n, count = 0; cin >> n;
int max = 0;
vector<int> v1(n);
vector<int> v2(n);
for(int i = 0; i < n; i++){
    cin >> v1[i] >> v2[i];
}
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
int begin = 0, end = 0;
for(int i = 0; i <= v2[n-1]; i++){
    if(v1[begin] == i && begin < v1.size()) {count++; begin++;}
    if(v2[end] == i && end < v2.size()) {count--; end++;}
    max = max >= count ? max : count;
}

cout << max << endl;
}