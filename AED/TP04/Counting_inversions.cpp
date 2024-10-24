#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long merge_count(vector<long long> &v,vector<long long> & aux,int  left_pos, int right_pos, int right_end){
    int left_end =  right_pos - 1, aux_pos = left_pos; //* boundaries
    int num_elements = right_end - left_pos + 1;
    long long res = 0;

    while(left_pos <= left_end && right_pos <= right_end){
        if(v[left_pos] <= v[right_pos]){
            aux[aux_pos++] = v[right_pos++];
        }
        else{
            aux[aux_pos++] = v[left_pos++]; res += left_end - left_pos;
        }
    }

    while(left_pos <= left_end){
        aux[aux_pos++] = v[left_pos++];
    }
    while(right_pos <= right_end){
        aux[aux_pos++] = v[right_pos++];
    }
    for(int i = 0; i < v.size(); i++, right_end--){
        v[right_end] = aux[right_end];
    }
    return res; 
}

long long count_inversions(vector<long long> &v,vector<long long>& aux, int s, int n){
    long long res = 0;
    if(s < n){
        int m = s + (n-s) / 2;  //* medium point of the vector
        res += count_inversions(v,aux,s,m);  //* calls recursivas para ambos os lados
        res += count_inversions(v,aux,m+1,n);

        //! auxiliary function to mergeSort and calculate
        res += merge_count(v,aux,s,m+1,n);
    }
    return res; //* base case
}

int main(){
    //* Vector/Exercise set-up
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<long long> aux(n);
    cout << count_inversions(v,aux,0,n - 1) << endl;
}