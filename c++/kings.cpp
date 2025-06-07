#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll n, m, k;

bool is_valid(ll mask) {
    return (mask & (mask >> 1)) == 0;
}

bool valid(ll a, ll b) {
    if (a & b) return false;               // same column
    if (a & (b >> 1)) return false;        // diagonal left
    if (a & (b << 1)) return false;        // diagonal right
    return true;
}

ll num_ones(ll mask) {
    ll cnt = 0;
    while (mask) {
        cnt += mask & 1;
        mask >>= 1;
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;

    const ll max_mask = 1 << m;

    vector<ll> valid_masks;
    vector<ll> mask_kings(max_mask, 0);
    for (ll mask = 0; mask < max_mask; ++mask) {
        if (is_valid(mask)) {
            valid_masks.push_back(mask);
            mask_kings[mask] = num_ones(mask);
        }
    }

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(max_mask, vector<ll>(k + 1, 0)));

    for (ll mask : valid_masks) {
        ll cnt = mask_kings[mask];
        if (cnt <= k)
            dp[1][mask][cnt] = 1;
    }

    for (ll row = 2; row <= n; ++row) {
        for (ll prev_mask : valid_masks) {
            for (ll prev_kings = 0; prev_kings <= k; ++prev_kings) {
                if (dp[row - 1][prev_mask][prev_kings] == 0) continue;

                for (ll cur_mask : valid_masks) {
                    if (!valid(prev_mask, cur_mask)) continue;
                    ll cur_kings = mask_kings[cur_mask];
                    if (prev_kings + cur_kings <= k) {
                        dp[row][cur_mask][prev_kings + cur_kings] += dp[row - 1][prev_mask][prev_kings];
                    }
                }
            }
        }
    }

    long long result = 0;
    for (ll mask : valid_masks) {
        result += 0LL + dp[n][mask][k];
    }

    cout << result << endl;
    return 0;
}
