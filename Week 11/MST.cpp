#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999

// Structure to represent a node in the graph
struct Node {
    int vertex;
    int weight;
};

// Custom comparator for priority queue based on weights
struct CompareNode {
    bool operator()(const Node& node1, const Node& node2) {
        return node1.weight > node2.weight;
    }
};

// Function to perform Prim's algorithm for minimum spanning tree
void primMST(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false); // Track visited vertices
    vector<int> minWeights(numVertices, INF); // Store minimum weights
    vector<int> parent(numVertices, -1); // Store parents to reconstruct MST

    // Create a priority queue to store nodes (vertex, weight)
    priority_queue<Node, vector<Node>, CompareNode> pq;

    // Start with the given startVertex
    minWeights[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        visited[u] = true;

        // Explore all adjacent vertices of u
        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < minWeights[v]) {
                // Update minimum weight and parent
                minWeights[v] = graph[u][v];
                parent[v] = u;
                pq.push({v, minWeights[v]});
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    int Min_cost=0;
    for (int v = 1; v < numVertices; ++v) {
        cout << parent[v] << " - " << v << " : " << graph[parent[v]][v] << endl;
        Min_cost=Min_cost+graph[parent[v]][v];
    }
    cout<<"Minimum cost is : "<<Min_cost<<endl;
}

// Main function
int main() {
    int numVertices = 5;

    // Given graph adjacency matrix
    vector<vector<int>> graph = {
        { 0, 3, 0, 0, 0,1 },
        { 3, 0, 2, 1, 10,0 },
        { 0, 2, 0, 3, 0,5 },
        { 0, 1, 3, 0, 5,0 },
        { 0, 10, 0, 5, 0,4 },
        {1,0,5,0,4,0} 
    };

    int startVertex = 0; // Start vertex for Prim's algorithm

    primMST(graph, startVertex);

    return 0;
}
