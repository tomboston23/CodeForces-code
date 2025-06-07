#include <bits/stdc++.h>
using namespace std;

vector<bool> SieveOfEratosthenes(int n)
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
    return prime;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<bool> primes = SieveOfEratosthenes(n);
    int c = 0;
    for(int i = 2; i <= n; i++){
        if(!primes[i]) continue;
        int count = 0;
        c++;
        for(int j = i; j <= n; j*=i){
            count += n/j;
        }
        cout << i << " " << count << endl;
    }
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




//hints:
 
/*
find all primes numbers less than N in O(N) time using Euler's Sieve

f(N): number of primes < N
f(N) ~~ N/ln(N)

f(1e7) ~~ 1e7/7*ln(10) ~~ 5x10^5

naive: for loop i = 1 to n
    factor(i)
takes n^2 time

pre-processing
2. first find primes < N
for(i = 2 ... sqrt(n))

for number k you're guaranteed floor(n/k) numbers divisible by k


1. find primes (O(N))
2. for each prime < N
        ans[prime] += N // prime
        prime *= original prime
*/