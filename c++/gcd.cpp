#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
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
        cout << gcd(a,b) << endl;;
    }

    return 0;
}