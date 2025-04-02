#include <bits/stdc++.h>
using namespace std;

bool detect(int source, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[source] = 1;
    queue<pair<int, int>> q;
    q.push({source, -1});
    while(!q.empty()) {
        int parent = q.front().second;
        int node = q.front().first;
        q.pop();
        visited[node] = 1;
        for(auto& adjacentNode : adjList[node]) {
            if(!visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                q.push({adjacentNode, node});
            } else if(parent != adjacentNode) return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(V + 1);
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> visited(V + 1, 0);
    for(int i = 0; i <= V; i++) {
        if(!visited[i]) {
            if(detect(i, adjList, visited)) return true;
        }
    }

    return false;
}

int main() {
    int numberOfVertex;
    cin >> numberOfVertex;
    int numberOfEdges;
    cin >> numberOfEdges;
    vector<vector<int>> edges;
    for(int i = 0; i < numberOfEdges; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    bool isCycleOutput = isCycle(numberOfVertex, edges);
    if(isCycleOutput) cout << "Cycle Detected!" << endl;
    else cout << "No cycle detected!" << endl;
    return 0;
}