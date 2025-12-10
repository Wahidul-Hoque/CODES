#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> bellman_Ford(vector<vector<pair<int, int>>> &adj, int src, bool &hasCycle)
{
    int v = adj.size();
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    hasCycle = false;

    for (int i = 0; i < v - 1; i++)
    {
        bool changed = false;
        for (int j = 0; j < v; j++)
        {
            for (auto &edge : adj[j])
            {
                int x = dist[edge.first];
                if (dist[j] != INT_MAX && dist[j] + edge.second < dist[edge.first]){
                    dist[edge.first] = dist[j] + edge.second;
                    changed=true;
                }
            }
        }
        if (!changed)
            break;
    }

    for (int j = 0; j < v; j++)
    {
        if(dist[j]== INT_MAX)continue;
        
        for (auto &edge : adj[j])
        {

            int x = dist[edge.first];
            if (dist[j] != INT_MAX && dist[j] + edge.second < dist[edge.first]){
                dist[edge.first] = dist[j] + edge.second;
                hasCycle =true;
            }
        }
    }

    return dist;
}

int main()
{

    // vector<vector<int>> dist(n, vector<int>(n, INF));

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {

        int s, d, w;

        cin >> s >> d >> w;
        adj[s].push_back({d, w});
    }

    int src;
    bool b;

    cin >> src;

    vector<int> dist = bellman_Ford(adj, src, b);

    for (auto a : dist)
    {

        cout << a << " ";
    }

    cout << endl
         << b;
}