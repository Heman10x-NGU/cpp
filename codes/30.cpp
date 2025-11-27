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
        int first = -1, last = -1, ans = 0;
        for (int i = 0; i < n; ++i) if (s[i] == '1') {
            if (first == -1) first = i;
            if (last != -1) ans = max(ans, i - last - 1);
            last = i;
        }
        ans = max(ans, first + n - last - 1);
        cout << ans << '\n';
    }
    return 0;
}