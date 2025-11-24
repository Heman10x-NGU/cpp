#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        int p1 = a[n - 1];
        int p2 = a[n - 2];
        int p3 = a[n - 3];

        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; ++i) {
            int c = 1;
            for (int v = 1; v <= 3; ++v) {
                if (v == p1 || v == p2) continue; 
                if (p1 == p2 && v == p3) continue; 
                c = v; break;
            }
            ans.push_back(c);


            p3 = p2;
            p2 = p1;
            p1 = c;
        }

        for (int i = 0; i < k; ++i)
            cout << ans[i] << (i + 1 == k ? '\n' : ' ');
    }
    return 0;
}