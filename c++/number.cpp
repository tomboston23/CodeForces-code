#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        if (gcd(a,b) != 1) {
            cout << -1 << endl;
            continue;
        }
        cout << 1LL*a*b-a-b << endl;
    }

    return 0;
}