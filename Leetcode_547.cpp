// Number of Provinces
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList) {
    visited[node] = 1;
    for(const auto& it : adjList[node]) {
        if(!visited[it]) dfs(it, visited, adjList);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adjList(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j] == 1 and i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, 0);
    int findCircleNumOutput = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            findCircleNumOutput++;
            dfs(i, visited, adjList);
        }
    }

    return findCircleNumOutput;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    int findCircleNumOutput = findCircleNum(isConnected);
    cout << findCircleNumOutput << endl;
    return 0;
}