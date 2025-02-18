#include <iostream>
#include <vector>
using namespace std;


int dfs(int x, int y, vector<vector<int>>& v, int count, int row, int col);
int main() {
    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++) {
        int rows, columns;
        cin >> rows >> columns;
        vector<vector<int>> table(rows);
        string line;
        for (int i = 0; i < rows; i++) {
            vector<int> part(columns);
            for (int k = 0; k < columns; k++) {
                char num;
                cin >> num;
                part[k] = num;
            }
            table[i] = part;
        }
        vector<int> cells;
        int largest = 0, count = 0;
        // invoke dfs, check all adjacent squares for one that belongs to a cell, if none do, it is a new cell, if any do, 
        // . or # means unvisited, and the number will go up from 47 -> 0, 48 -> 1, depending on which group they belong to
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < columns; k++) {
                if (table[i][k] == '#') {
                    count++;
                    largest = max(dfs(i, k, table, count, rows, columns), largest);
                }
            }
        }
    cout << count << ' ' << largest << endl;
    }
}

// returns the total size of the cell if one is found
int dfs(int x, int y, vector<vector<int>>& v, int count, int row, int col) {
    int size = 1;
    //* if it is not part of a cell, return
    if (v[x][y] != '#') {
        return 0;
    }
    //* if it is, label it
    v[x][y] = '#' + 1 + count;
    if (x - 1 >= 0) {
        size += dfs(x - 1, y, v, count, row, col);
    }
    if (x + 1 < row) {
        size += dfs(x + 1, y, v, count, row, col);
    }
    if (y - 1 >= 0) {
        size += dfs(x, y - 1, v, count, row, col);
    }
    if (y + 1 < col) {
        size += dfs(x, y + 1, v, count, row, col);
    }
    if (x - 1 >= 0 && y + 1 < col) {
        size += dfs(x - 1, y + 1, v, count, row, col);
    }
    if (x + 1 < row && y - 1 >= 0) {
        size += dfs(x + 1, y - 1, v, count, row, col);
    }
    if (y - 1 >= 0 && x - 1 >= 0) {
        size += dfs(x - 1, y - 1, v, count, row, col);
    }
    if (y + 1 < col && x + 1 < row) {
        size += dfs(x + 1, y + 1, v, count, row, col);
    }
    return size;
}
