#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int> adj[], vector<int> &vis, vector<int>&ls,
         vector<int> &discovery, vector<int> &finish, int &time)
{
    vis[start] = 1;
    discovery[start] = ++time;   // record discovery time

    ls.push_back(start);

    for(auto it : adj[start])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, ls, discovery, finish, time);
        }
    }

    finish[start] = ++time;      // record finishing time
}

vector<int> dfsofgraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;

    vector<int> discovery(V, 0);
    vector<int> finish(V, 0);
    int time = 0;

    dfs(start, adj, vis, ls, discovery, finish, time);

    // Print discovery and finishing times
    cout << "Node\tDiscovery\tFinishing\n";
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" << discovery[i] << "\t\t" << finish[i] << "\n";
    }

    return ls;
}

int main()
{
    cout << "Enter the number of Vertex and Edges" << endl;
    int V,E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dfs_traversal = dfsofgraph(V, adj);

    cout << "The dfs travarsal is" << endl;
    for(int i = 0; i < dfs_traversal.size(); i++)
    {
        cout << dfs_traversal[i] << " ";
    }

    return 0;
}
