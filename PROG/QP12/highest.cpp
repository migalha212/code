#include <bits/stdc++.h> 
using namespace std;

float get_average(list<int> grades)
{
    float med = 0;
    for(int f: grades)
    {
        med += f;
    }
    return med / float(grades.size());
}

string student_highest_avg(map<string, list<int>> m){
    string max = "";
    float curr = 0;
    for(pair<string,list<int>> s : m){
        if(get_average(s.second) > curr)
        {
            max = s.first;
            curr = get_average(s.second);
        }
    }
    return max;
}