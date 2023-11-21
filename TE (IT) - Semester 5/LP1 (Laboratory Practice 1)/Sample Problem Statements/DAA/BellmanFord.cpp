#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int source, destination, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(vector<Edge> &edges, int numVertices, int source)
{
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < numVertices - 1; i++)
    {
        for (const Edge &edge : edges)
        {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
            {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge &edge : edges)
    {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
        {
            cout << "Graph contains a negative-weight cycle. Bellman-Ford does not work." << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "\nShortest distances from source vertex " << source << "\nto all other vertices (using Bellman-Ford Algorithm):" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertex " << i+1 << ": " << distance[i] << endl;
    }
}

int main()
{
    int numVertices, numEdges;

    cout << "\nBELLMAN FORD ALGORITHM (USING DYNAMIC PROGRAMMING)" << endl;;
    cout << "\nEnter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter the source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, numVertices, source);

    return 0;
}
