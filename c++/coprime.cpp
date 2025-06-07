#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi prime_factors(int n){
    vi factors;
    if(n % 2 == 0){
        factors.push_back(2);
    }
    while(n%2==0){
        n/=2;
    }
    for(int i = 3; i*i<=n; i++){
        if(n%i==0) factors.push_back(i);
        else continue;
        while(n%i==0) n/=i;
    }
    if(n>2) factors.push_back(n);
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vi p = prime_factors(n);
        ll numer = 1LL;
        ll denom = 1LL;
        for(int k : p){
            numer *= 1LL * (k-1);
            denom *= 1LL * k;
        }
        cout << n*numer/denom << endl;
    }
    return 0;
}