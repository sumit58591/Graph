#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<pair<int, int>, int>> q;
    int m = grid.size(), n = grid.at(0).size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) q.push({{i, j}, 0});
            visited[i][j] = grid[i][j];
        }
    }

    vector<int> deltRow = {-1, 0, 1, 0};
    vector<int> deltCol = {0, 1, 0, -1};
    int orangeRottingOutput = 0;
    while(!q.empty()) {
        pair<pair<int, int>, int> currOrange = q.front();
        pair<int, int> coordinate = currOrange.first;
        int x = coordinate.first;
        int y = coordinate.second;
        int time = currOrange.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nRow = x + deltRow[i];
            int nCol = y + deltCol[i];
            if(nRow >= 0 and nRow < m and nCol >= 0 and nCol < n) {
                if(visited[nRow][nCol] != 2 and grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, time + 1});
                    visited[nRow][nCol] = 2;
                    orangeRottingOutput = max(orangeRottingOutput, time + 1);
                }
            }
        }
    }


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 1) return -1;
        }
    }

    return orangeRottingOutput;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    int orangesRottingOutput = orangesRotting(grid);
    cout << orangesRottingOutput << endl;
    return 0;
}