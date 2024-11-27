#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, pair<int, int>> movies;

    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;
        if (movies.find(name) != movies.end())
        {
            movies[name] = {score >= 5 ? movies[name].first + 1 : movies[name].first, ++movies[name].second};
        }
        else
            movies[name] = {score >= 5 ? 1 : 0, 1};
    }
    //* number of movies with at least one review
    cout << movies.size() << endl;
    //* max number of reviews on a movie, how many have that number
    //* ammount of movies with more positive than negative reviews (reviews >= 5 are positive) 
    int cur_max = 0;
    int amountOfMovies = 0;
    int positiveMovies = 0;
    for (pair<string,pair<int,int>> movie : movies){
        if(movie.second.first > movie.second.second - movie.second.first) positiveMovies++;  
        if(movie.second.second == cur_max) amountOfMovies++;
        else if(movie.second.second > cur_max){
            cur_max = movie.second.second;
            amountOfMovies = 1;
        }
    }
    cout << cur_max << ' ' << amountOfMovies << endl;
    cout << positiveMovies << endl;
}