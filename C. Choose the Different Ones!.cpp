
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    set<int> s1;
    vector<int> b(m);
    set<int> s2;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            s1.insert(a[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] <= k) {
            s2.insert(b[i]);
        }
    }

    if (s1.size() < k / 2 || s2.size() < k / 2) {
        cout << "NO" << endl;
        return;
    }

    vector<int> cnt(k + 1, 0);
    for (int e : s1) {
        cnt[e] |= 1;  // Mark presence in s1
    }
    for (int e : s2) {
        cnt[e] |= 2;  // Mark presence in s2
    }

    bool flag = true;
    for (int i = 1; i <= k; ++i) {
        if (cnt[i] == 0) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

