#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                                                         // number of test cases
    cin >> T;
    while (T--) {
        int n, m;                                                  // swords, monsters
        cin >> n >> m;

        vector<int64> a(n);                                        // sword damages
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int64> b(m), c(m);                                  // monster stats
        for (int i = 0; i < m; ++i) cin >> b[i];
        for (int i = 0; i < m; ++i) cin >> c[i];
          /* ------------------------------------------------------------------
           Separate monsters
        ------------------------------------------------------------------ */
        vector<pair<int64,int64>> good;    // c>0
        vector<int64> bad;                 // c==0   (only life is relevant)

        for (int i = 0; i < m; ++i)
            if (c[i] == 0) bad.push_back(b[i]);
            else            good.emplace_back(b[i], c[i]);

        sort(good.begin(), good.end(),            // increasing life
             [](auto &x, auto &y){ return x.first < y.first; });
        sort(bad.begin(), bad.end());             // increasing life