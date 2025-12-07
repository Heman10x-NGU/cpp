#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> evens, odds;
        bool hasOne = false;
        for (auto v : a) {
            if (v == 1) hasOne = true;
            if ((v & 1LL) == 0) evens.push_back(v);
            else odds.push_back(v);
        }

        bool printed = false;

        if (hasOne) {
            long long y = -1;
            for (auto v : a) {
                if (v > 1) { y = v; break; }
            }
            if (y != -1) {
                cout << 1 << " " << y << "\n";
                continue;
            }
        }

        if (evens.size() >= 2) {
            cout << evens[0] << " " << evens[1] << "\n";
            continue;
        }

        if (evens.size() == 1) {
            long long e = evens[0];
            for (auto x : odds) {
                if (x < e) {
                    long long q = e / x;
                    if ((q % 2LL) == 0) {
                        cout << x << " " << e << "\n";
                        printed = true;
                        break;
                    }
                } else break;
            }
            if (printed) continue;
        }

        for (int i = 0; i + 1 < (int)odds.size(); ++i) {
            if (odds[i + 1] < 2LL * odds[i]) {
                cout << odds[i] << " " << odds[i + 1] << "\n";
                printed = true;
                break;
            }
        }
        if (printed) continue;

        bool found = false;
        int m = (int)odds.size();
        for (int i = 0; i < m && !found; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if (((odds[j] / odds[i]) % 2LL) == 1LL) {
                    cout << odds[i] << " " << odds[j] << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (found) continue;

        cout << -1 << "\n";
    }
    return 0;
}