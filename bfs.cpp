#include<bits/stdc++.h>
using namespace std;

vector<int> bfstravarsal(int V, vector<int>adj[])
{

    vector<int>vis(V,0);

    vector<int>discovery(V,-1);
    
    int time=0;

    vis[0]=1;
    discovery[0]=time++;
    queue<int>q;

    q.push(0);

    vector<int>bfs;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
                discovery[it]=time++;
            }
        }
    }


    cout << "Node\tDiscovery Time\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << discovery[i] << "\n";
    }

    return bfs;

}




int main()
{

    cout<<"Enter the number of Vertex and Edges"<<endl;
    int V,E;
    cin>>V>>E;


    vector<int>adj[V];

    for(int i=0; i<E;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
         adj[v].push_back(u);

    }
    
    vector<int>bfs = bfstravarsal(V, adj);

    cout<<"The bfs travarsal is"<<endl;

    for(int i=0; i<bfs.size(); i++)
    {
        cout<<bfs[i]<<" ";
    }

    return 0;

}
