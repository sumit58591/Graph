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
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    vector<vector<int>> adjList(numberOfNodes);
    for(int i = 0; i < numberOfNodes; i++) {
        for(int j = 0; j < numberOfEdges; j++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    vector<int> bfsTraversal = dfsOfGraph(adjList);
    for(int i = 0; i < bfsTraversal.size(); i++) cout << bfsTraversal[i] << " ";
    return 0;
}