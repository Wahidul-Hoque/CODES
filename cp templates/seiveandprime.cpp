#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long
#define ld long double
const int MAX_PRIME = 1000000; 
// is_prime[i] will be true if i is prime, false otherwise
vector<bool> is_prime;
// Stores all the generated prime numbers sequentially
vector<int> primes;

void sieve(int n = MAX_PRIME) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    // We only need to loop up to sqrt(n) for the outer loop
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            // Update all multiples of p starting from p*p
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    
    // Collect all the primes into a list for easy traversal
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

int main() {
    FAST_IO;
    sieve();
    
    
    return 0;
}