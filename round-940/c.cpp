/*
Author: JNIDV
Date created: 2024-04-26

Solution:
Let dp[x] be the number of ways to take x rows/cols.
dp[x] = 2 * (x - 1) * dp[x - 2] + dp[x - 1]
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;
    ll dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int x = 2; x <= n; x++) {
        dp[x] = (2LL * (x - 1) * dp[x - 2] + dp[x - 1]) % MOD;
    }
    int take = n;
    while (k--) {
        int r, c;
        cin >> r >> c;
        if (r != c) {
            take -= 2;
        } else {
            take--;
        }
    }
    cout << dp[take] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
