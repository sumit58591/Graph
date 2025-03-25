#include <bits/stdc++.h>
using namespace std;

int main() {
    // We will be given if the graph is undirected or directed
    // In question, they will provide : number of nodes and number of edges
    // Matrix Way for storing Graph
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    int adj[numberOfNodes + 1][numberOfNodes + 1];
    for(int i = 0; i < numberOfEdges; i++) {
        int u, v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        // For a weighted graph, instead of 1 we will assign the weight value
    }

    // The other method is using Adjacency List
    // An adjacency list contains vector of vector which will store all the neighbours
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<vector<int>>adjList (noOfNodes + 1);
    // For smaller value of nodes we can use vector<int> adjList[noOfNodes + 1];
    for(int i = 0; i < noOfEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        // For a weighted graph, instead of saving the neighbours, 
        // We will save the pairs, where pairs will have two things, first is neighbor and second is weight
    }

    // In case of directed graph, 
    // if there is an edge between u and v then we won't do adjList[v].push_back(u)
}