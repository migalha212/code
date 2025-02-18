#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;


bool eval(pair<int, int> curr, vector<string>& maze) {
    return maze[curr.first][curr.second] == '.' || maze[curr.first][curr.second] == 'T';
}


int main() {
    int cases;
    pair<int, int> p, t;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int res = 0;
        int rows, columns;
        cin >> rows >> columns;
        vector<string> maze(rows);
        vector<vector<int>> rese(rows);
        for (int j = 0; j < rows; j++) {
            string line = "";
            for (int k = 0; k < columns; k++) {
                unsigned char c;
                cin >> c;
                if (c == 'P') p = { j,k };
                else if (c == 'T') t = { j,k };
                line += c;
                rese[j].push_back(0);
            }
            maze[j] = line;
        }

        queue<pair<int, int>> q;
        q.push(p);
        maze[p.first][p.second] = '0';
        while (!q.empty()) {
            pair<int, int> curr = q.front(); q.pop();
            if (eval({ curr.first + 1, curr.second }, maze)) {
                q.push({ curr.first + 1, curr.second });
                maze[curr.first + 1][curr.second] = 0;
                rese[curr.first + 1][curr.second] = rese[curr.first][curr.second] + 1;
            }
            if (eval({ curr.first - 1, curr.second }, maze)) {
                q.push({ curr.first - 1 , curr.second });
                maze[curr.first - 1][curr.second] = 0;
                rese[curr.first - 1][curr.second] = rese[curr.first][curr.second] + 1;
            }
            if (eval({ curr.first, curr.second + 1 }, maze)) {
                q.push({ curr.first, curr.second + 1 });
                maze[curr.first][curr.second + 1] = 0;
                rese[curr.first][curr.second + 1] = rese[curr.first][curr.second] + 1;
            }
            if (eval({ curr.first , curr.second - 1 }, maze)) {
                q.push({ curr.first , curr.second - 1 });
                maze[curr.first][curr.second - 1] = 0;
                rese[curr.first][curr.second - 1] = rese[curr.first][curr.second] + 1;
            }

        }
            res = rese[t.first][t.second];
        cout << res << endl;
    }
}

