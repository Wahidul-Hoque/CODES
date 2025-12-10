#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void bfsConnected(vector<vector<int>>& adj, int src, vector<bool>& visited, vector<int>& res) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // visit all the unvisited neighbour of current node
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// BFS for all components (handles disconnected graphs)
vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<int> res;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bfsConnected(adj, i, visited, res);
    }
    return res;
}

int main(){
    int n,m;cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> order= bfs(adj);

    for( int x: order){
        cout<<x<<" ";
    }
    cout<<endl;
}
