#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void dfsRec(vector<vector<int>> &adj,
            vector<bool> &visited, int s, vector<int> &res) {

    visited[s] = true;
    res.push_back(s);

    for (int i : adj[s])
        if (!visited[i])
            dfsRec(adj, visited, i, res);
}

vector<int> dfs(vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    vector<int> res;

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i])
            dfsRec(adj, visited, i, res);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);  // comment out if directed graph
    }

    vector<int> result = dfs(adj);

    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
