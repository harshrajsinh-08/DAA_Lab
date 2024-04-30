#include <iostream>
#include <climits>
using namespace std;
void BellmanFord(int graph[][3], int V, int E,int src)
{
	int dist[V];
	for (int i = 0; i < V; i++){dist[i] = INT_MAX;}
	dist[src] = 0;

	// Relax all edges |V| - 1 times.
	for (int i = 0; i < V - 1; i++) {

		for (int j = 0; j < E; j++) {
			if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
				dist[graph[j][1]] = 
				dist[graph[j][0]] + graph[j][2];
		}
	}

	// check for negative-weight cycles.
	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dist[x] != INT_MAX &&
				dist[x] + weight < dist[y])
			cout << "Graph contains negative"
					" weight cycle"
				<< endl;
	}

	cout << "Vertex disttance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << "\t\t" << dist[i] << endl;
}

// Driver program to test above functions
int main()
{
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph

	// Every edge has three values (u, v, w) where
	// the edge is from vertex u to v. And weight
	// of the edge is w.
	int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
					{ 1, 2, 3 }, { 1, 3, 2 }, 
					{ 1, 4, 2 }, { 3, 2, 5 }, 
					{ 3, 1, 1 }, { 4, 3, -3 } };

	BellmanFord(graph, V, E, 0);
	return 0;
}
