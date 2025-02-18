#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int k;
    string sequence;
    cin >> k >> sequence;
    unordered_map<string, int> sequences;

    for (int i = 0; i <= sequence.size() - k; i++) {
        string sub = sequence.substr(i, k);
        if (sequences.find(sub) != sequences.end()) {
            sequences[sub]++;
        }
        else {
            sequences[sub] = 1;
        }
    }

    int res = 0, rep = 0;
    for (pair<string, int> freq : sequences) {
        if (freq.second > res) {
            res = freq.second;
            rep = 1;
        }
        else if (freq.second == res) {
            rep++;
        }
    }

    cout << res << endl;

    if (rep != 1) {
        cout << rep << endl;
    }

    else {
        for (pair<string, int> freq : sequences)
            if (freq.second == res)
                cout << freq.first << endl;
    }
}