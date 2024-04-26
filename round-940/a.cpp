/*
Author: JNIDV
Date created: 2024-04-26

Solution:
Count frequencies c[x] and add floor(c[x] / 3) across all x in a.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int A = 100;
int cnt[A + 1];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= A; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (int i = 0; i <= A; i++) {
        ans += cnt[i] / 3;
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
