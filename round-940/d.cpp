/*
Author: JNIDV
Date created: 2024-04-26

Solution:
Notice that f(x, y) ^ f(y, z) > f(x, z) is equivalent to f(x, z) ^ a[y] > f(x, z).
This only happens when f(x, z)'s bit at the place of the most significant set bit of a[y] is unset.
Fix y.
We can count how many segments [x, y - 1] has xor 0 and how many segments [y, z] has xor 0.
Similarly, count how many segments [x, y - 1] has xor 1 and how many segments [y, z] has xor 1.
There is an additional case where x = y, in which we add how many segments [y + 1, z] has xor 1.
Add all these values across all y.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int B = 30, N = 100000;

int a[N], pre_xor[B + 1][N], suf_xor[B + 1][N], pre_cnt[B + 1][N], suf_cnt[B + 1][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int bit = 0; bit <= B; bit++) {
        pre_xor[bit][0] = a[0] >> bit & 1;
        for (int i = 1; i < n; i++) {
            pre_xor[bit][i] = pre_xor[bit][i - 1] ^ (a[i] >> bit & 1);
        }
        pre_cnt[bit][0] = pre_xor[bit][0];
        for (int i = 1; i < n; i++) {
            pre_cnt[bit][i] = pre_cnt[bit][i - 1] + pre_xor[bit][i];
        }
        suf_xor[bit][n - 1] = a[n - 1] >> bit & 1;
        for (int i = n - 2; i >= 0; i--) {
            suf_xor[bit][i] = suf_xor[bit][i + 1] ^ (a[i] >> bit & 1);
        }
        suf_cnt[bit][n - 1] = suf_xor[bit][n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_cnt[bit][i] = suf_cnt[bit][i + 1] + suf_xor[bit][i];
        }
    }
    ll ans = 0;
    for (int y = 0; y < n; y++) {
        int hsb = -1;
        for (int bit = B; bit >= 0; bit--) {
            if (a[y] >> bit & 1) {
                hsb = bit;
                break;
            }
        }
        int pre0_yy, pre1_yy, pre1_ny, suf0_ny, suf1_ny;
        if (y > 0 && pre_xor[hsb][y - 1]) {
            pre0_yy = pre_cnt[hsb][n - 1] - pre_cnt[hsb][y - 1];
            pre1_yy = n - y - pre0_yy;
        } else {
            pre1_yy = pre_cnt[hsb][n - 1] - (y > 0 ? pre_cnt[hsb][y - 1] : 0);
            pre0_yy = n - y - pre1_yy;
        }
        if (pre_xor[hsb][y]) {
            pre1_ny = n - 1 - y - pre_cnt[hsb][n - 1] + pre_cnt[hsb][y];
        } else {
            pre1_ny = pre_cnt[hsb][n - 1] - pre_cnt[hsb][y];
        }
        if (suf_xor[hsb][y]) {
            suf0_ny = suf_cnt[hsb][0] - suf_cnt[hsb][y];
            suf1_ny = y - suf0_ny;
        } else {
            suf1_ny = suf_cnt[hsb][0] - suf_cnt[hsb][y];
            suf0_ny = y - suf1_ny;
        }
        ans += (ll) suf0_ny * pre0_yy + pre1_ny + (ll) suf1_ny * pre1_yy;
    }
    cout << ans << "\n";
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
