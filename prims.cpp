
//If the list of edges are given

#include <bits/stdc++.h>
using namespace std;


    int spanningTree(int V, vector<vector<int>>& edges) {

        // Make adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Min-heap (weight, node)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});  // start from node 0

        vector<int> vis(V, 0);
        int sum = 0;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;

            // Push all neighbors
            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int adjWt = p.second;

                if (!vis[adjNode]) {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return sum;
    }


int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    
    cout <<spanningTree(V, edges);

    return 0;
}


//If adjacency list is given

#include <bits/stdc++.h>
using namespace std;


    int spanningTree(int V, vector<vector<int>> adj[]) {

        // Min-heap: (weight, node)
        priority_queue<
            pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V, 0);
        int sum = 0;
        vector<int>parent(V,-1);

        pq.push({0, 0});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt   = it.first;
            int node = it.second;

            if (vis[node])  continue;

            vis[node] = 1;
            sum += wt;

            // Check all neighbours
            for (auto it : adj[node]) {
                int adjNode = it[0];  
                int adjWt   = it[1];  

                if (!vis[adjNode]) {
                    pq.push({adjWt, adjNode});
                    parent[adjNode]=node;
                }
            }
        }

       cout<<"Printing the MST"<<endl;

       for(int i=1; i<=V-1;i++)
       {
        cout<<parent[i]<<"->"<<i<<" Weight:";
       
       for(auto it: adj[i])
       {
            if(it[0]==parent[i])
            {
                cout<<it[1];
                break;
            }    
       }
       cout<<endl;
    }

        return sum;
    }



int main() {
    int t;
    cin >> t;

    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // Undirected
        }

        
        cout <<"total weight of MST"<< spanningTree(V, adj) << "\n";
    }

    return 0;
}












