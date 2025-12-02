#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int mx = a[0], ans = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < mx) ++ans;
            else if (a[i] > mx) mx = a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}