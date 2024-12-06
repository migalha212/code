#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    long long res = 0;
    string line;
    int j = 1;
    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> report;
        while (ss >> num) {
            cout << num << '-';
            report.push_back(num);
        }
        cout << ';' << endl;
        int i = 0;
        int a = report[i++], b = 0;
        bool problem = false; //* checks if a problem was previously found in the report
        bool safe = true; //* checks if the report is safe
        bool asc = false;
        int last_diff = 0;
        while (i < report.size()) {
            //* get the next 2 elements and compute their difference
            b = report[i++];
            int diff = a - b;

            //* first condition (the difference must be in the interval [1,3])
            if (abs(diff) < 1 || abs(diff) > 3) {
                //* if its the first time something broke, try with the next element
                if (!problem) {
                    problem = true;
                    continue; //* since the previous ellement is only replaced at the end of the loop, restarting will suffice
                }
                else {
                    //* if a problem already occured before, break
                    safe = false; break;
                }
            }

            //* second condition (always ascending or descending)
            if (diff < 0 && last_diff != 0) {
                if (asc && last_diff > 0) {
                    if (!problem) {
                        if (a == report[0]) {
                            if (report[1] - report[2] < 0) {
                                a = b;
                                problem = true; continue;
                            }
                        }
                        problem = true;
                        continue;
                    }
                    else {
                        safe = false; break;
                    }
                }
                asc = false;
            }
            else if (diff > 0 && last_diff != 0) {
                if (!asc && last_diff < 0) {
                    if (!problem) {
                        if (a == report[0]) {
                            if (report[1] - report[2] > 0 && report[2] - report[3] > 0) {
                                a = b;
                                problem = true; continue;
                            }
                            problem = true;
                            continue;
                        }
                        else {
                            safe = false; break;
                        }
                    }
                    asc = true;
                }
                else {
                    asc = diff > 0;
                }
                last_diff = diff;
                a = b;
            }
        }
        if (safe) {
            cout << j++ << "safe!" << endl;
            res++;
        }
        else cout << j++ << endl;
        report.clear();
    }
    cout << res;
}