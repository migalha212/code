#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
string name;
int wins;
int draws;
int losses;
int goalsScored;
int goalsAgainst;
int points;
int goalAverage;
}Team;

bool teamSort(Team a, Team b){
    if(a.points > b.points){
        return true;
    }
    else if(a.points == b.points && a.goalAverage > b.goalAverage){
        return true;
    }
    else if(a.points == b.points && a.goalAverage == b.goalAverage && a.name < b.name){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<Team> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].wins >> v[i].draws >> v[i].losses >> v[i].goalsScored >> v[i].goalsAgainst;
        v[i].points = v[i].wins * 3 + v[i].draws * 1;
        v[i].goalAverage = v[i].goalsScored - v[i].goalsAgainst;
    }
    sort(v.begin(),v.end(),teamSort);
    for(int i = 0; i < n; i++){
        cout << v[i].name << ' ' << v[i].points << ' ' << v[i].goalAverage << endl;
    }

}