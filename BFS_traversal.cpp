// BFS traversal is a level order traversal. For level order traversal, we use queue data structure
// which is first in first out

// We can start from any node and that node will be the starting node which we will push in queue DS.

// The first node will be at level 0, the nodes which are connected with that node or 
// which are just neighbors will be at level 1 and so on.

// Inorder to do a BFS traversal, we need to set a initial configuration

// Since graph can contain multiple connected components, hence we will have a visited array
// to keep track of each node.


#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    int vis[adj.size()] = {0};
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto& it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
    // Time Complexity will be O(N + E) as queue will run for each nodes and
    // at most graph will have 2E edges.
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

    vector<int> bfs = bfsOfGraph(adjList);
    for(int i = 0; i < bfs.size(); i++) cout << bfs[i] << " ";
    return 0;
}