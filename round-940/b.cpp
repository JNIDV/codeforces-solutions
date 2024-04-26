/*
Author: JNIDV
Date created:

Solution:
Greedy start from lowest powers 2 and create the smallest integer of the form 111...111_2.
Pad zeroes until the array is full.
Add the remaining to the last element since it won't contribute to the OR anyways.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans = {0};
    int pow = 1;
    while (pow <= k) {
        ans.front() += pow;
        k -= pow;
        pow <<= 1;
    }
    while ((int) ans.size() < n) {
        ans.push_back(0);
    }
    ans.back() += k;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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
