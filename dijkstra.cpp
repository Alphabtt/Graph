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

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    vector<vector<pair<int,int>>> adj(V);

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, INF);
    vector<int> parent(V, -1);   // parent array added

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dis > dist[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int adjWt = it.second;

            if (dis + adjWt < dist[adjNode]) {
                dist[adjNode] = dis + adjWt;
                parent[adjNode] = node;        // save parent like Java
                pq.push({dist[adjNode], adjNode});
            }
        }

        // print after every main step (like Java)
        printGraph(dist, parent, V);
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

    dijkstra(V, edges, src);  // printing happens inside

    return 0;
}
