// Time Complexity: O(N + E)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& list) {
    visited[node] = true;
    list.push_back(node);
    for(const auto& it: adj[node]) {
        if(!visited[it]) {
            dfs(it, visited, adj, list);
        }
    }

    return;
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    // Code here
    vector<int> list;
    vector<bool> visited(adj.size(), false);
    int start = 0;
    dfs(start, visited, adj, list);
    return list;
}

int main() {
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<int>> adjList(noOfNodes);
    for(int i = 0; i < noOfEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> dfs = dfsOfGraph(adjList);
    for(int i = 0; i < dfs.size(); i++) cout << dfs[i] << " ";
    return 0;
}