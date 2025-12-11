#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// print like Java printGraph()
void printGraph(const vector<int>& dist, const vector<int>& parent, int V) {
    cout << "vertex\tparent\tdistance\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << parent[i] << "\t\t";
        if (dist[i] >= INF) cout << INF;   // show large value like Java
        else cout << dist[i];
        cout << "\n";
    }
    cout << "\n";
}

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {

    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V-1; i++) {
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }

        // print after every main iteration (like your Dijkstra print)
        cout << "After iteration " << i << ":\n";
        printGraph(dist, parent, V);
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle!\n";
    }

    return dist;
}

int main() {
    cout << "Enter the number of Vertex and Edges: ";
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << "Enter source: ";
    int src;
    cin >> src;

    bellmanFord(V, edges, src);  // printing happens inside

    return 0;
}
