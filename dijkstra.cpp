#include <iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

vector<int> sSSP(vector<vector<pair<int,int>>> &adj,int src){

    int n=adj.size();

    vector<int>dist(n,INT_MAX);

    dist[src]=0;

    // Min-Priority Queue stores {distance, node}
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater <pair<int,int>>> pq;
    pq.push({0,src}); // Start with the source node

    while (!pq.empty()){

        // Extract node 'x' with the smallest distance
        pair<int ,int> x =pq.top();
        pq.pop();

        // Optimization: Skip if a shorter path has already been found/processed
        if (x.first>dist[x.second]) continue;

        // Iterate through all neighbors (edges) of the current node
        for (auto &edge :adj[x.second]){

            int v=edge.first;  // Neighbor node
            int w=edge.second; // Edge weight

            // Relaxation step: Check if a shorter path is found
            if (dist[x.second]+w < dist[v]){
                dist[v]=dist[x.second]+w; // Update shortest distance
                pq.push({dist[v],v});     // Push neighbor with the new distance
            }
        }

    }

    return dist; 

}


int main(){

    int n,m ;

    cin>>n>>m;

    // Adjacency list: adj[s] stores list of {destination, weight} pairs
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<m;i++){

        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back({d,w}); // Add edge from s to d with weight w

    }

    int src;

    cin>>src;

    vector<int> dist=sSSP(adj,src);

    // Output the shortest distances from the source to all nodes
    for(auto a: dist){

        cout<<a<<" ";
    }

}