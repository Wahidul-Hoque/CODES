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
    vector<string> grid(n);
    pii start, end;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                start={i,j};
            }
            else if(grid[i][j]=='B'){
                end={i,j};
            }
        }
    }
    
    // BFS setup
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    bool found = false;
    while(!q.empty()){
        auto curr =q.front();
        q.pop();
        int x=curr.first;
        int y=curr.second;
        if(x==end.first && y==end.second){
            found=true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                !visited[nx][ny] && grid[nx][ny] != '#') {
                
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                direction[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }

        
    }
    if(!found){
        cout << "NO" << endl;
        return 0;
    }
    // Reconstruct the path
        string path;
        int x = end.first, y = end.second;
        int length = 0;

        while (x != start.first || y != start.second) {
            path += direction[x][y];
            auto p = parent[x][y];
            x = p.first;
            y = p.second;
            length++;
        }
        reverse(all(path));
        cout << "YES" << endl;
        cout << length << endl;
        cout << path << endl;
}

        
  
    

