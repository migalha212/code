#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,pair<int,int>> movies;
    int mostReviewed = 0;
    for(int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        if(movies.find(name) != movies.end()){
            mostReviewed = max(++movies[name].second,mostReviewed);
        } else
            movies[name] = {score,1};
    }

    cout << movies.size() << endl;
    
}