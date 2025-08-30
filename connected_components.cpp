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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};
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
    vector<bool> visited(n+1,false);
    vector<int> components;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components.pb(i);
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int cur=q.front();
                q.pop();

                for(int nei:graph[cur]){
                    if(!visited[nei]){
                        visited[nei]=true;
                        q.push(nei);
                    }
                }
            }
        }
    }

    int k=components.size()-1;
    cout<<k<<endl;

    for (int i = 0; i < k; i++) {
        cout << components[i] << " " << components[i+1] << endl;
    }

    
    
}

        
  
    

