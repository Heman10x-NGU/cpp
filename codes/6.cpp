#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;  


bool isPossible(u64 n) {
    if (n == 0) return true;            

    int L = 64 - __builtin_clzll(n);     

    for (int B = L; B <= 59; ++B) {    
       
        if ((B & 1) && ((n >> (B >> 1)) & 1)) continue;

        bool ok = true;
        for (int i = 0; i < B / 2; ++i) {
            int left  = (n >> i)         & 1;
            int right = (n >> (B - 1 - i)) & 1;
            if (left != right) { ok = false; break; }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) {
        u64 n; cin >> n;
        cout << (isPossible(n) ? "YES\n" : "NO\n");
    }
    return 0;
}