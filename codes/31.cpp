#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; if (!(cin >> n >> m)) return 0;
    const int K = 26;
    vector<array<int, K>> cnt(n);
    array<ll, K> tot{}; tot.fill(0);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s; cnt[i].fill(0);
        for (char ch : s) ++cnt[i][ch - 'A'];
        for (int c = 0; c < K; ++c) tot[c] += cnt[i][c];
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ll cur = m; bool bad = false;
        for (int c = 0; c < K && !bad; ++c) {
            ll A = tot[c] - cnt[i][c], B = cnt[i][c];
            if (B && !A) { bad = true; break; }
            if (!B) continue;
            if ((ll)m * A < B) { bad = true; break; }
            cur = min(cur, (ll)m - (B + A - 1) / A);
        }
        ans[i] = (!bad && cur >= 0) ? cur : -1;
    }
    for (int i = 0; i < n; ++i) cout << (i ? " " : "") << ans[i];
    cout << '\n';
    return 0;
}