#include <string>
#include <vector>
using namespace std;

string longest_prefix(const vector<string>& v){
    string aux = v[0];
    for(size_t i = 1; i < v.size();i++){
        for(size_t j = 0; j < min( v[i].size() , aux.size()); j++){
            if(aux[j] == v[i][j]) continue;
            else {
                aux = aux.substr(0,j);
                break;
            }
        }
    }
    return aux;
}