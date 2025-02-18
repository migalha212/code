#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;
// mindblown XD
int main() {
    string line;
    long long res = 0;
    while (getline(cin, line)) {
        stringstream ss(line);
        int i;
        queue<int> q;
        while (ss >> i) {
            cout << i << ' ';
            q.push(i);
        }
        cout << endl;
        int a = q.front(); q.pop();
        int b = 0;
        bool asc = false;
        bool des = false;
        bool safe = true;
        while (!q.empty()) {
            b = q.front(); q.pop();
            int dif = a - b;
            if (dif < 0 && !asc) {
                if (abs(dif) > 3 || abs(dif) < 1) {
                    safe = false; break;
                }
                des = true;
            }
            else if (dif >= 0 && !des) {
                if (dif > 3 || dif < 1) {
                    safe = false; break;
                }
                asc = true;
            }
            else if (des || safe) {
                safe = false;
                break;
            }
            a = b;
        }
        if (safe) {
            cout << "was safe" << endl;
            res++;
        }
    }
    cout << res << endl;
}