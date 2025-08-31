#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long
#define us_ unordered_set
#define um_ unordered_map
typedef pair<int, int> ii; typedef vector<ii> vii; 
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mp make_pair
#define pb push_back
#define setbit(n)  __builtin_popcount(n)
#define t_zero(n)  __builtin_ctz(n)
#define t_one(n)     ( __builtin_ctz(~(n)))
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg_vec(v)        \
    cerr << #v << ": ";   \
    for (auto x : v)      \
        cerr << x << ' '; \
    cerr << endl;
#define dbg_pair(p) cerr << #p << ": (" << p.first << "," << p.second << ")" << endl
#define pii pair<int,int>

int main() {
    FAST_IO

    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    // BFS setup
    vector<int> visited(n+1,  false);
    vector<int> distance(n+1, -1);
    vector<int> parent(n+1, -1);
    queue<int>q;
    q.push(1);
    visited[1] = true;
    distance[1]=1;
    while(!q.empty()){
        int curr =q.front();
        q.pop();
        if(curr==n)break;
        for(int n:graph[curr]){
            if(!visited[n]){
                visited[n]=true;
                q.push(n);
                distance[n]=distance[curr]+1;
                parent[n]=curr;
            }
        }
        
    }
    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    // Reconstruct the path
        vector<int> path;
        for(int node=n;node!=-1;node=parent[node]){
            path.pb(node);
        }
        reverse(all(path));
        cout << distance[n] << endl;
        for (int node : path) {
            cout << node << " ";
        }
}

        
  
    

