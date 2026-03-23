//topic list 
//Binary Exponentiation (BigMod)
//ncr pre_computation in O(n) and ncr query in O(1)
//bitmask subset generation
//bit operations
//list of divisors of n in O(sqrt(n) * log(sqrt(n))) time
//gcd and lcm
//2D Prefix Sum Precomputation and Query
//two pointers technique for counting subarrays with sum constraints/sliding window

#include<bits/stdc++.h>
using namespace std;
#define setbit(n)  __builtin_popcount(n)
#define ll long long
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const int mod = 1e9 + 7 , N = 1e6 + 9;





//binary exponentiation (bigmod)
// computes x^n mod m in O(log n) time
int power(int x, long long n) { 
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

// returns the list of divisors of n in O(sqrt(n) * log(sqrt(n))) time
vector<ll> get_divisors(ll n) {
  vector<ll> divs;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) {
        divs.push_back(n / i);
      }
    }
  }
  sort(divs.begin(), divs.end());
  return divs;
}

//ncr pre_computation in O(n) and ncr query in O(1)
int f[N], inv[N], finv[N];
void prec() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}
int ncr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return 1LL * f[n] * finv[n - r] % mod * finv[r] % mod;
}

//bitmask subset generation
//this is for n<=22; we check all subsets of the given set and do some operations on them

// int main() {
//   int n, l, r, x; cin >> n >> l >> r >> x;
//   int c[n];
//   for (int i = 0; i < n; i++) {
//     cin >> c[i];
//   }
//   int ans = 0;
//   for (int mask = 0; mask < (1 << n); mask++) {
//     // fix the subset as the elements under this bitmask
//     int total_problems = 0, total_difficulty = 0;
//     int min_difficulty = 1e6 + 9, max_difficulty = 0;
//     for (int i = 0; i < n; i++) {
//       if ((mask >> i) & 1) {
//         total_problems++;
//         total_difficulty += c[i];
//         min_difficulty = min(min_difficulty, c[i]);
//         max_difficulty = max(max_difficulty, c[i]);
//       }
//     }
//     if (total_problems >= 2 and total_difficulty >= l and total_difficulty <= r
//       and abs(min_difficulty - max_difficulty) >= x) {
//       ans++;
//     }
//   }
//   cout << ans << '\n';
//   return 0;
// }
// Time: O(n * 2^n)
// Space: O(n)

//setbit(n) returns the number of set bits in the binary representation of n
// Sets the kth bit of x to 0 and returns the result
int unset_kth_bit(int x, int k) {
  return x & (~(1 << k));
}

// Toggles the kth bit of x and returns the result
int toggle_kth_bit(int x, int k) {
  return x ^ (1 << k);
}

// Checks if x is a power of 2
bool check_power_of_2(int x) {
  return setbit(x) == 1;
}


/* 2D Prefix Sum Precomputation (1-based indexing)
   Builds the prefix table in O(N*M) to allow O(1) subgrid sum queries.
*/
int a[N][N], pref[N][N];
void build_2d_prefix(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
}

/* 2D Range Sum Query
   Calculates sum of subgrid from (x1, y1) to (x2, y2) in O(1).
*/
int query_2d(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}


/* 1D Prefix XOR Precomputation (1-based indexing)
   Builds the prefix table in O(N) to allow O(1) range XOR queries.
*/
int a2[N], pref_xor[N];
void build_prefix_xor(int n) {
    for (int i = 1; i <= n; i++) {
        pref_xor[i] = pref_xor[i - 1] ^ a2[i];
    }
}

/* Range XOR Query
   Calculates XOR sum from index l to r in O(1).
*/
int query_xor(int l, int r) {
    return pref_xor[r] ^ pref_xor[l - 1];
}

/* Two Pointers: Count Subarrays with Sum <= S
   Iterates through all possible left boundaries 'l' and moves 
   the right boundary 'r' as far as possible in O(N) total time.
*/
ll count_subarrays_with_sum_limit(int n, ll s) {
    ll ans = 0, sum = 0;
    int r = 1;
    for (int l = 1; l <= n; l++) {
        while (r <= n && sum + a2[r] <= s) {
            sum += a2[r];
            r++;
        }
        // r - 1 is the farthest index such that sum(a[l...r-1]) <= s
        // All subarrays starting at l and ending at any point from l to r-1 are valid
        ans += (r - l); 
        if (r > l) sum -= a2[l];
        else r = l + 1; // Handle case where a2[l] > s
    }
    return ans;
}