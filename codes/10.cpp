#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> idx;


        for (int i = 0; i < n; ++i)
            if (s[i] == '0')
                idx.push_back(i + 1);

        if (idx.empty()) {
            idx.reserve(n);
            for (int i = 1; i <= n; ++i) idx.push_back(i);
        }


        cout << idx.size() << '\n';
        if (!idx.empty()) {
            for (size_t i = 0; i < idx.size(); ++i) {
                if (i) cout << ' ';
                cout << idx[i];
            }
            cout << '\n';
        }
    }
    return 0;
}