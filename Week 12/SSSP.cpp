#include <iostream>
#include <climits>
#include <vector>

#define INFINITY 9999
#define max 6

using namespace std;

void dijkstra(int G[max][max], int n, int startNode);

int main() {
    int G[max][max] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int n = 6;    // number of vertices
    int u = 5;    // starting city

    dijkstra(G, n, u);

    return 0;
}

void dijkstra(int G[max][max], int n, int startNode) {
    int cost[max][max], distance[max], pred[max];
    bool visited[max];
    int count, mindistance, nextNode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    // Initializing pred[], distance[] and visited[]
    for (i = 0; i < n; i++) {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = false;
    }

    distance[startNode] = 0;
    visited[startNode] = true;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        // Next node gives the node at minimum distance
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextNode = i;
            }
        }

        // Checking if a better path exists through nextNode
        visited[nextNode] = true;

        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextNode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    // Printing the shortest distance and path
    for (i = 0; i < n; i++) {
        if (i != startNode) {
            cout << "Shortest times from City " << startNode << " to City " << i << ":" << endl;
            cout << "City " << startNode << " to City " << i << ": " << distance[i] << endl;

            cout << "Path: " << i;
            j = i;
            do {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startNode);

            cout << endl << endl;
        }
    }

    // Calculate and print the average times
    double total = 0;
    int avgCount = 0;
    for (i = 0; i < n; i++) {
        if (i != startNode && distance[i] != INFINITY) {
            total += distance[i];
            avgCount++;
        }
    }

    double average = total / avgCount;
    cout << "Average time taken from City " << startNode << " to other cities: " << average << endl;
}
