#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

const int64 LIM = 2'000'000'000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;   cin >> T;
    while (T--) {
        int n;         int64 a;
        cin >> n >> a;

        vector<int64> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

       
        vector<pair<int64,int>> ev;

        for (int64 x : v) {
            if (x == a) continue; 

            int64 dist = llabs(x - a) - 1;
            if (dist < 0) continue;

            int64 l = max<int64>(0,x - dist);
            int64 r = min<int64>(LIM,x + dist);

            ev.emplace_back(l,   +1);
            if (r + 1 <= LIM)
                ev.emplace_back(r + 1, -1);
        }

        
        ev.emplace_back(0, 0);

        sort(ev.begin(), ev.end());

        int64 cur = 0, best = 0, best_b = 0;

        for (size_t i = 0; i < ev.size(); ) {
            int64 pos   = ev[i].first;
            int64 delta = 0;
            while (i < ev.size() && ev[i].first == pos) {
                delta += ev[i].second;
                ++i;
            }
            cur += delta;
            if (cur > best) {
                best   = cur;
                best_b = pos;
            }
        }

        cout << best_b << '\n';
    }
    return 0;
}