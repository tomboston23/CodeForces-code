#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<int> primes;
    vector<bool> prime(n + 1, true);
    int count = n-1;

    for (int p = 2; p*p <= n; p++) {


        if (prime[p] == true) {
            primes.push_back(p);
            
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p){
                count-= (int)prime[i];
                prime[i] = false;
                
            }
        }
    }

    cout << count << endl;
    // Print all prime numbers
    for (int i = 2; i <=n; i++ )
        if(prime[i]) cout << i << " ";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    SieveOfEratosthenes(n);
    return 0;
}

/* euler sieve
each non-prime number x is sieved by y such that x = c*y and c is its smallest prime factor
for(y = 2; y < n; y++)
    if s[y] == 0
        y is prime
    for(primes <= y)
        s[primes*y] = true
*/

