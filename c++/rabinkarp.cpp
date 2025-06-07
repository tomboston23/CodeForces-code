#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
const int base = 27;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vector<long long> prefix(n + 1, 0);
    vector<long long> power(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] * base + (s[i] - 'a' + 1)) % MOD;
        power[i + 1] = (power[i] * base) % MOD;
    }
    
    
    auto get_hash = [&](int l, int r) -> long long {
        long long raw = (prefix[r] - prefix[l] * power[r - l]) % MOD;
        return (raw + MOD) % MOD;
    };

    int count = 0;

    for (int i = 0; i < n; ++i) { 
        for (int j = i + 1; j < n; ++j) {
            //both loops are O(n^2). Use binary search
            // to find largest L where s[i:i+L] == s[j:j+L]
            // so it's O(n^2 * log (n))
            if (s[i] != s[j]) continue;

            int low = 0;
            int high = n - j;
            while (low < high) {
                int mid = (low + high + 1) / 2;
                if (get_hash(i, i + mid) == get_hash(j, j + mid)) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            count += low;
        }
    }

    cout << count << '\n';
}
